#include "Game/Game.h"

Game::Game(QObject *parent) : QObject(parent), m_timeLastUpdate(QTime::currentTime()), m_currentPlayer(Player1), m_inputState(Angle), m_gameState(Menu), m_cannonballFired(false)
{
    m_view = new QGraphicsView(&m_scene);
    newGame();

    m_timer.setInterval(1000/60);
    connect(&m_timer, &QTimer::timeout, this, &Game::update);

    m_timer.start();
}

Game::~Game()
{

}

bool Game::pause()
{
	return m_gameState == Pause;
}

void Game::setPause(bool pause)
{
    if (m_gameState == Play && pause){
		m_gameState = Pause;
		m_scene.addItem(new PauseOverlay(m_scene.sceneRect()));
	}	
	else if (m_gameState == Pause && !pause) {
		for (auto item : m_scene.items()) {
			if (PauseOverlay* pauseOverlay = dynamic_cast<PauseOverlay*>(item)) {
				m_scene.removeItem(item);
				delete pauseOverlay;
			}
		}
		m_gameState = Play;
	}
}
		

void Game::newAngle(double angle)
{
	emit angleChanged(angle);
}

void Game::newPower(double power)
{
	emit powerChanged(power);
}

void Game::customEvent(QEvent *event)
{ 
	if (m_gameState == Play && !m_cannonballFired) {
		if (event->type() == FPGAEvent::customFPGAEvent) {
			FPGAEvent* fpgaEvent = static_cast<FPGAEvent *>(event);

			if (fpgaEvent->command() == Change) {
                m_inputState = (InputState)(m_inputState + 1);
                if (m_inputState == NoState)
                    m_inputState = Angle;
                emit stateChanged(m_inputState);
			}
			else {
				for (auto item : m_scene.items()) {
					if (Cannon* cannon = dynamic_cast<Cannon*>(item)) {
						if (cannon->owner() == m_currentPlayer) {
                            if (fpgaEvent->command() == Increase && m_inputState == Angle)
								cannon->increaseAngle(1);
                            else if (fpgaEvent->command() == Decrease && m_inputState == Angle)
								cannon->decreaseAngle(1);
                            else if (fpgaEvent->command() == Increase && m_inputState == Power)
								cannon->increasePower(1);
                            else if (fpgaEvent->command() == Decrease && m_inputState == Power)
								cannon->decreasePower(1);
                            else if ((fpgaEvent->command() == Decrease || fpgaEvent->command() == Increase) && m_inputState == Fire) {
								CannonBall* ball = cannon->fire();
								connect(ball, &CannonBall::destroyed, this, &Game::cannonBallDestroyed);
								m_scene.addItem(ball);
								cannon->reset();

                                m_inputState = Angle;
                                emit stateChanged(m_inputState);

								m_currentPlayer = (Player)(m_currentPlayer + 1);
								if (m_currentPlayer == NoPlayer)
									m_currentPlayer = Player1;
								emit playerChanged(m_currentPlayer);
							}
							return;
						}
					}
				}
			}
		}
	}
}

void Game::newCannonball()
{
	m_cannonballFired = true;
}

void Game::cannonBallDestroyed()
{
	m_cannonballFired = false;
}

void Game::update()
{
    if (m_gameState == Play || m_gameState == Transition) {
        m_scene.advance();

		for (auto item : m_scene.items()) {
			if (CannonBall* cannonball = dynamic_cast<CannonBall*>(item)) {
				//Update physic
				cannonball->updateEntity(m_timeLastUpdate.msecsTo(QTime::currentTime()));

				//Check collisions
				if (cannonball->outsideOfScene()) {
					m_scene.removeItem(item);
					delete item;
				}
				else {
					for (auto collider : cannonball->collidingItems()) {
						if (Castle* castle = dynamic_cast<Castle*>(collider)) {
							if (castle->owner() != cannonball->owner()) {
								m_scene.removeItem(item);
                                Animation* explosion = new Animation(QPixmap(":/resources/explosion.png"),25,64,64);
                                    explosion->setPos(item->pos());
                                    m_scene.addItem(explosion);
								delete item;
                                castle->takeDamage(20);
                                m_gameState = Transition;
								break;
							}
						}
						else if (QGraphicsRectItem* terrain = dynamic_cast<QGraphicsRectItem*>(collider)) { //Temp for terrain
							/*m_scene.removeItem(item);
							delete item;
							break;*/
						}
						else if (Cannon* cannon = dynamic_cast<Cannon*>(collider)) {
							if (cannon->owner() != m_currentPlayer) {
								m_scene.removeItem(item);
								delete item;
								break;
							}
						}
					}
				}
			}
            else if(Animation* explosion = dynamic_cast<Animation*>(item)) {
                if(explosion->done()){
                    m_scene.removeItem(item);
                    delete item;
                    if(m_gameState == Transition) {
                        createNewTerrain();
                        return;
                    }
                }
            }
		}
	}

    m_timeLastUpdate = QTime::currentTime();
}

void Game::newGame(Difficulty p_difficulty, int p_player)
{
    m_gameDifficulty = p_difficulty;

	/**Setup basic scene and view**/
    m_scene.clear();
	m_scene.setSceneRect(0, 0, 1920, 750);

	m_view->setFrameStyle(QFrame::NoFrame);
	m_view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setBackgroundBrush(QBrush(QColor(Qt::black)));

    /**Setup Background**/
    m_scene.addRect(m_scene.sceneRect(), QPen(Qt::NoPen), QBrush(QColor(107, 219, 242)));

	/**Setup Terrain**/
	BezierMode bezier;
	switch (p_difficulty)
	{
	case Difficulty::Easy:
		bezier = BezierMode::LowCurves;
		break;
	case Difficulty::Hard:
		bezier = BezierMode::InsaneCurves;
		break;
	case Difficulty::Intermediate:
		bezier = BezierMode::HighCurves;
		break;
	case Difficulty::Random:
		bezier = BezierMode(rand() % 4);
	}



	m_terrain = new Terrain(bezier, 1920.0f, 100);
	m_terrain->setPos(0, 500);

	/**Add items**/
    Castle * castle1 = new Castle(QPixmap(":/resources/long_castle_p1.png"),Player::Player1, 100);
        castle1->setScale(2);
		m_scene.addItem(castle1);

	Castle * castle2 = new Castle(QPixmap(":/resources/long_castle_p2.png"), Player::Player2, 100);
        castle2->setScale(2);
		m_scene.addItem(castle2);
		

	m_scene.addItem(m_terrain);
	Cannon * cannon1 = new Cannon(QPixmap(":/resources/cannon_gun.png/"), QPixmap(":/resources/cannon_support.png/"), QPointF(300, 0), false, Player::Player1);
		cannon1->setScale(0.1);
		connect(cannon1, &Cannon::angleChanged, this, &Game::newAngle);
		connect(cannon1, &Cannon::powerChanged, this, &Game::newPower);
		connect(cannon1, &Cannon::fired, this, &Game::newCannonball);
		m_scene.addItem(cannon1);

	Cannon * cannon2 = new Cannon(QPixmap(":/resources/cannon_gun.png/"), QPixmap(":/resources/cannon_support.png/"), QPointF(300, 0), true, Player::Player2);
		cannon2->setScale(0.1);
		cannon2->setTransform(QTransform::fromScale(-1, 1));
		connect(cannon2, &Cannon::angleChanged, this, &Game::newAngle);
		connect(cannon2, &Cannon::powerChanged, this, &Game::newPower);
		connect(cannon2, &Cannon::fired, this, &Game::newCannonball);
		m_scene.addItem(cannon2);

    castle1->setPos(m_terrain->mapToScene(m_terrain->getLowestPointBetween(0, m_terrain->boundingRect().width() / 8)) - QPointF(castle1->boundingRect().width()/2, 150));
    castle2->setPos(m_terrain->mapToScene(m_terrain->getLowestPointBetween(m_terrain->boundingRect().width() * (7.0f / 8.0f), m_terrain->boundingRect().width() - castle2->boundingRect().width())) - QPointF(castle2->boundingRect().width()/2, 150));

	QPointF chosenPoint = m_terrain->mapToScene(m_terrain->getHighestPointBetween(
		castle1->pos().rx(),
		castle1->pos().rx() + m_terrain->boundingRect().width() / 8.0));
	QPointF offset = QPointF(960 * cannon1->scale() / -2.0f, 480 * cannon1->scale() / -3.0f);
	cannon1->setPos(chosenPoint + offset);
		
	chosenPoint = m_terrain->mapToScene(m_terrain->getHighestPointBetween(
		castle2->pos().rx() - m_terrain->boundingRect().width() / 8.0,
		castle2->pos().rx()));
	offset = QPointF(960 * cannon2->scale() / 2.0f, 480 * cannon2->scale() / -3.0f);
	cannon2->setPos(chosenPoint + offset);

    GameOverlay* overlay = new GameOverlay();
    overlay->setPos(240, 10);
    connect(castle1, &Castle::damageTaken, overlay, &GameOverlay::newPlayerLife);
    connect(castle2, &Castle::damageTaken, overlay, &GameOverlay::newPlayerLife);
    m_scene.addItem(overlay);

    emit newGameGenerated();
}

void Game::startPlaying()
{
    m_gameState = Play;
}


void Game::createNewTerrain()
{
    int player1Life;
    int player2Life;
    for (auto item : m_scene.items()) {
        if (Castle* castle = dynamic_cast<Castle*>(item)) {
            if (castle->owner() == Player1)
                player1Life = castle->life();
            else if (castle->owner() == Player2)
                player2Life = castle->life();
        }
    }

    newGame(m_gameDifficulty, 2);

    for (auto item : m_scene.items()) {
        if (Castle* castle = dynamic_cast<Castle*>(item)) {
            if (castle->owner() == Player1)
                castle->takeDamage(castle->life() - player1Life);
            else if (castle->owner() == Player2)
                castle->takeDamage(castle->life() - player2Life);
        }
    }
}

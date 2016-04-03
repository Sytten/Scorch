#include "Game/Game.h"

Game::Game(QObject *parent) : QObject(parent), m_timeLastUpdate(QTime::currentTime()), m_currentPlayer(Player1), m_currentState(Power)
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

void Game::customEvent(QEvent *event)
{ 
   for(auto item : m_scene.items())
   {
       /* if(Cannon* cannon = qgraphicsitem_cast<Cannon*>(item)) {

        }*/
   }
}

void Game::checkCollisions()
{
    //TODO: Check all colliding objects to verify if the cannonball collided with something, if its the case delete it and remove the life to the castle if necessary
}

void Game::update()
{
    //TODO: Call the update on the scene with the delta time, the objects will need to be moved to entity based system before!
    //TODO: move view to display current player or follow cannonball if fired
    checkCollisions();
    m_timeLastUpdate = QTime::currentTime();
}

void Game::newGame()
{
	/**Setup basic scene and view**/
    m_scene.clear();
	m_scene.setSceneRect(0, 0, 1280, 450);

	m_view->setFrameStyle(QFrame::NoFrame);
	m_view->scale(1.5, 1.5);

	/**Add items**/
    Castle * castle1 = new Castle(QPixmap(":/resources/long_castle_p1.png"),Player::Player1, 100);
	castle1->setPos(50, 350);
		m_scene.addItem(castle1);

	Castle * castle2 = new Castle(QPixmap(":/resources/long_castle_p2.png"), Player::Player2, 100);
	castle2->setPos(1173, 350);
		m_scene.addItem(castle2);

	/**Setup Terrain**/
	m_scene.addRect(0, 450, 1280, 50, QPen(Qt::NoPen), QBrush(QColor(Qt::darkGreen)));
}

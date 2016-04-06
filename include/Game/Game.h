#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include <QPointer>

#include "Input/FPGAEvent.h"
#include "Game/State.h"
#include "Game/Player.h"
#include "Game/Castle.h"
#include "Game/Cannon.h"
#include "Game/PauseOverlay.h"
#include "Game/GameOverlay.h"
#include "Game/Animation.h"
#include "Terrain/Terrain.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = 0);
    ~Game();

    InputState getInputState() { return m_inputState; }
    GameState getGameState() { return m_gameState; }
    QGraphicsView* getView() { return m_view; }
	bool pause();

public slots:
	void newGame(Difficulty p_difficulty = Difficulty::Easy, int p_player = 2, Player p_startingPlayer = Player::Player1);
    void startPlaying();
	void createNewTerrain();
	void setPause(bool pause);
	void newAngle(double angle);
	void newPower(double power);

protected:
    void customEvent(QEvent* event);

protected slots:
    void update();
	void newCannonball();
	void cannonBallDestroyed();

private:
    QGraphicsScene m_scene;
    QPointer<QGraphicsView> m_view;
    QTimer m_timer;
    QTime m_timeLastUpdate;
    Player m_currentPlayer;
    InputState m_inputState;
	GameState m_gameState;

	Terrain * m_terrain;

	bool m_cannonballFired;
    Difficulty m_gameDifficulty;

signals:
    void playerChanged(Player player);
    void stateChanged(InputState state);
	void angleChanged(double angle);
	void powerChanged(double power);
    void newGameGenerated();
};

#endif // GAME_H

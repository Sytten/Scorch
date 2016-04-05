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

#include "Terrain/Terrain.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = 0);
    ~Game();

    InputState getState() { return m_currentState; }
    QGraphicsView* getView() { return m_view; }
	bool pause();

public slots:
    void newGame();
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
    InputState m_currentState;
	GameState m_gameState;

	Terrain * m_terrain;

	bool m_cannonballFired;

signals:
    void playerChanged(Player player);
    void stateChanged(InputState state);
	void angleChanged(double angle);
	void powerChanged(double power);
};

#endif // GAME_H

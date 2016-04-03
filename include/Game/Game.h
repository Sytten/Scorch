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

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = 0);
    ~Game();

    State getState() { return m_currentState; }
    QGraphicsView* getView() { return m_view; }

public slots:
    void newGame();
	void newAngle(double angle);
	void newPower(double power);

protected:
    void customEvent(QEvent* event);
    void checkCollisions();

protected slots:
    void update();

private:
    QGraphicsScene m_scene;
    QPointer<QGraphicsView> m_view;
    QTimer m_timer;
    QTime m_timeLastUpdate;
    Player m_currentPlayer;
    State m_currentState;

signals:
    void playerChanged(Player player);
    void stateChanged(State state);
	void angleChanged(double angle);
	void powerChanged(double power);
};

#endif // GAME_H

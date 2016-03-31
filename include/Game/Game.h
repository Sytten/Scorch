#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include <QPointer>

#include "Input/FPGAEvent.h"

enum Player {Player1 = 0, Player2, NoPlayer};
enum State {Power = 0, Angle, Fire, NoState};

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject* parent = 0);
    ~Game();

    State getState() { return m_currentState; }
    QGraphicsView* getView() { return m_view; }

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
};

#endif // GAME_H

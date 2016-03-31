#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>

#include "Input/FPGAEvent.h"

enum Player {Player1, Player2, None};

class Game : public QObject
{
    Q_OBJECT

public:
    Game(QObject parent = 0);
    ~Game();

    QGraphicsView* getView() { return &m_scene; }

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
};

#endif // GAME_H

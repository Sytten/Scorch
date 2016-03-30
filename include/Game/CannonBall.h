#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QGraphicsPixmapItem>
#include <QTime>
#include <QVector2D>

#include "Input/FPGAEvent.h"

class CannonBall : public QGraphicsPixmapItem
{
public:
    CannonBall(QGraphicsItem *parent = 0);

    //void advance(int phase);

protected:
    //void customEvent(QEvent * event);

private:
    QVector2D m_position;
    QVector2D m_velocity;
    QTime m_timeLastUpdate;
};

#endif // CANNONBALL_H

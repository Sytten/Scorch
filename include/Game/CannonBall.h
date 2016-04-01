#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QVector2D>

#include "Game/Entity.h"

class CannonBall : public Entity
{
public:
    CannonBall(QGraphicsItem *parent = 0);

    //void advance(int phase);

protected:
    //void customEvent(QEvent * event);

private:
    QVector2D m_position;
    QVector2D m_velocity;
};

#endif // CANNONBALL_H

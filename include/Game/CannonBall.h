#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QVector2D>

#include "Game/Entity.h"

class CannonBall : public Entity
{
public:
    CannonBall(Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime);

    int type() const { return UserType + 2; }

protected:
    void customEvent(QEvent * event);

private:
    QVector2D m_position;
    QVector2D m_velocity;
};

#endif // CANNONBALL_H

#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
public:
    Cannon(QGraphicsItem *parent = 0);

    void update(double deltaTime) { Q_UNUSED(deltaTime) }

private:
    double m_angle;
    double m_power;
};

#endif // CANNON_H

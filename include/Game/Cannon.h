#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
public:
    Cannon(QGraphicsItem *parent = 0);

private:
    double m_angle;
    double m_power;
};

#endif // CANNON_H

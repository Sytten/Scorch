#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
public:
    Cannon(Player owner, QGraphicsItem *parent = 0);

    void update(double deltaTime) { Q_UNUSED(deltaTime) }

    void type() const { return UserType + 1; }
};

#endif // CANNON_H

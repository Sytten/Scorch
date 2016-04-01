#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
public:
    Cannon(const QPixmap &pixmap, Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime) { Q_UNUSED(deltaTime) }

    int type() const { return UserType + 1; }
};

#endif // CANNON_H

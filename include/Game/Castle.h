#ifndef CASTLE_H
#define CASTLE_H

#include "Game/Entity.h"

class Castle : public Entity
{
public:
    Castle(Player owner, int p_initialLife, QGraphicsItem *parent = 0);

    bool isAlive();
    void takeDamage(int p_damage);

    void update(double deltaTime) {Q_UNUSED(deltaTime)}

    void type() const { return UserType + 3; }

private:
    int m_life;
};

#endif // CASTLE_H

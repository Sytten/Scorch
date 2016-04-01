#ifndef CASTLE_H
#define CASTLE_H

#include "Game/Entity.h"

class Castle : public Entity
{
public:
    Castle(int p_initialLife, QGraphicsItem *parent = 0);

    bool isAlive();
    void takeDamage(int p_damage);

private:
    int m_life;
};

#endif // CASTLE_H

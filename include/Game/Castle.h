#ifndef CASTLE_H
#define CASTLE_H

#include "Game/Entity.h"

class Castle : public Entity
{
public:
    Castle(const QPixmap &pixmap, Player owner, int p_initialLife, QGraphicsItem *parent = 0);

    bool isAlive();
    void takeDamage(int p_damage);

    void updateEntity(double deltaTime) {Q_UNUSED(deltaTime)}

    int type() const { return UserType + 3; }

private:
    int m_life;
};

#endif // CASTLE_H

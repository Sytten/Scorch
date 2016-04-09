/********
File: Castle.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Entity castle that maintains the life system coherent for the player
********/

#ifndef CASTLE_H
#define CASTLE_H

#include "Game/Entity.h"

class Castle : public Entity
{
    Q_OBJECT

public:
    Castle(const QPixmap &pixmap, Player owner, int p_initialLife, QGraphicsItem *parent = 0);

    bool isAlive();
    void takeDamage(int p_damage);
    int life() { return m_life; }

    void updateEntity(double deltaTime) {Q_UNUSED(deltaTime)}

    int type() const { return UserType + 3; }

private:
    int m_life;

signals:
    void damageTaken(Player player, int life);
    void destroyed(Player player);
};

#endif // CASTLE_H

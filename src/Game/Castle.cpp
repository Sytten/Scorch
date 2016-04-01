#include "Game/Castle.h"

Castle::Castle(Player owner, int p_initialLife, QGraphicsItem *parent) : Entity(owner, parent), m_life(p_initialLife)
{

}

bool Castle::isAlive()
{
    if(m_life > 0)
        return true;
    return false;
}

void Castle::takeDamage(int p_damage)
{
    m_life -= p_damage;
    if(m_life < 0)
        m_life = 0;
}

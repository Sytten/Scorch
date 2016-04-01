#include "Game/Entity.h"

Entity::Entity(Player owner, QGraphicsItem *parent) : QGraphicsItem(parent), m_owner(owner)
{
}

Player Entity::owner() const
{
    return m_owner;
}

void Entity::setOwner(Player owner)
{
    if (m_owner == owner)
        return;

    m_owner = owner;
    emit ownerChanged(owner);
}

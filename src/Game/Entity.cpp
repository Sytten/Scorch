#include "Game/Entity.h"

Entity::Entity(const QPixmap &pixmap, Player owner, QGraphicsItem *parent) : QGraphicsPixmapItem(pixmap, parent), m_owner(owner)
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

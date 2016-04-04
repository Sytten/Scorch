#include "Game/Entity.h"

Entity::Entity(const QPixmap &pixmap, Player owner, QGraphicsItem *parent) : QGraphicsPixmapItem(pixmap, parent), m_owner(owner)
{
}

bool Entity::outsideOfScene()
{
	if (!scene())
		return true;

	if (pos().x() > scene()->sceneRect().right() || pos().x() < scene()->sceneRect().left())
		return true;

	if (pos().y() > scene()->sceneRect().bottom() || pos().y() < scene()->sceneRect().top())
		return true;

	return false;
}

Player Entity::owner() const
{
    return m_owner;
}

void Entity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(scene())
        painter->setClipRect(mapFromScene(scene()->sceneRect().intersected(mapToScene(boundingRect()).boundingRect())).boundingRect());
    QGraphicsPixmapItem::paint(painter, option, widget);
}

void Entity::setOwner(Player owner)
{
    if (m_owner == owner)
        return;

    m_owner = owner;
    emit ownerChanged(owner);
}

#include "Game/Cannon.h"

Cannon::Cannon(const QPixmap & cannon, const QPixmap & base, QPointF cannonRelativePosition, Player owner, QGraphicsItem * parent) : Entity(QPixmap(), owner, parent), m_power(50), m_angle(0)
{
	m_cannon = new QGraphicsPixmapItem(cannon, this);
	m_base = new QGraphicsPixmapItem(base, this);

	m_cannon->setPos(cannonRelativePosition);
}
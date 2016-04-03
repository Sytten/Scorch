#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
public:
    Cannon(const QPixmap &cannon, const QPixmap &base, QPointF cannonRelativePosition, Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime) { Q_UNUSED(deltaTime) }

    int type() const { return UserType + 1; }

private:
	QGraphicsPixmapItem* m_cannon;
	QGraphicsPixmapItem* m_base;

	double m_power;
	double m_angle;
};

#endif // CANNON_H

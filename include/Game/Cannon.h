#ifndef CANNON_H
#define CANNON_H

#include "Game/Entity.h"

class Cannon : public Entity
{
	Q_OBJECT

public:
    Cannon(const QPixmap &cannon, const QPixmap &base, QPointF cannonRelativePosition, Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime) { Q_UNUSED(deltaTime) }

    int type() const { return UserType + 1; }

	void increaseAngle(double angle);
	void decreaseAngle(double angle);
	void increasePower(double power);
	void decreasePower(double power);

	void reset();

private:
	QGraphicsPixmapItem* m_cannon;
	QGraphicsPixmapItem* m_base;

	double m_power;
	double m_angle;

signals:
	void powerChanged(double power);
	void angleChanged(double angle);
};

#endif // CANNON_H

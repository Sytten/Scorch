/********
File: Cannon.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Entity cannon can fire cannonball and maintains the properties set by the player
********/

#ifndef CANNON_H
#define CANNON_H

#include <QPointF>
#include <QMediaPlayer>
#include <QDir>

#include "Game/Entity.h"
#include "Game/CannonBall.h"

class Cannon : public Entity
{
	Q_OBJECT

public:
    Cannon(const QPixmap &cannon, const QPixmap &base, QPointF cannonRelativePosition, bool reversed, Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime) { Q_UNUSED(deltaTime) }

    QPointF shotPoint() { return m_cannon->mapToParent(m_cannon->transformOriginPoint()); }

    int type() const { return UserType + 1; }

	void increaseAngle(double angle);
	void decreaseAngle(double angle);
	void increasePower(double power);
	void decreasePower(double power);

	void reset();

	CannonBall* fire();

private:
	double toRadians(double degrees);

	QGraphicsPixmapItem* m_cannon;
	QGraphicsPixmapItem* m_base;

	QMediaPlayer m_fireSound;

	double m_power;
	double m_angle;

	bool m_reversed;

signals:
	void powerChanged(double power);
	void angleChanged(double angle);
	void fired();
};

#endif // CANNON_H

#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <QVector2D>
#include <QTime>

#include "Game/Entity.h"

class CannonBall : public Entity
{
public:
    CannonBall(const QPixmap &pixmap, QVector2D velocity, QVector2D position, Player owner, QGraphicsItem *parent = 0);

    void updateEntity(double deltaTime);

    int type() const { return UserType + 2; }

private:
    QVector2D m_initialVelocity;
	QVector2D m_initialPosition;
	double m_gravity;
	double m_timeSinceShot;
};

#endif // CANNONBALL_H

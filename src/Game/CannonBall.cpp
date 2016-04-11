#include "Game/CannonBall.h"

CannonBall::CannonBall(const QPixmap & pixmap, QVector2D velocity, QVector2D position, Player owner, QGraphicsItem * parent) : Entity(pixmap, owner, parent), m_initialVelocity(velocity), m_initialPosition(position), m_gravity(9.8), m_timeSinceShot(0)
{
	setScale(0.1);
	setPos(m_initialPosition.toPointF());
}

void CannonBall::updateEntity(double deltaTime)
{
    m_timeSinceShot += deltaTime/1000.0 * 2.0;

	double x = m_initialPosition.x() + m_initialVelocity.x() * m_timeSinceShot;
	double y = m_initialPosition.y() - m_initialVelocity.y() * m_timeSinceShot + 0.75 * m_gravity * m_timeSinceShot * m_timeSinceShot;

	setPos(x, y);

   update(boundingRect());
}

#include "Game/Cannon.h"

Cannon::Cannon(const QPixmap & cannon, const QPixmap & base, QPointF cannonRelativePosition, bool reversed, Player owner, QGraphicsItem * parent) : Entity(QPixmap(), owner, parent), m_power(50), m_angle(0), m_reversed(reversed)
{
	m_cannon = new QGraphicsPixmapItem(cannon, this);
	m_base = new QGraphicsPixmapItem(base, this);

	m_cannon->setPos(cannonRelativePosition);
	m_cannon->setRotation(-m_angle);
	m_cannon->setTransformOriginPoint(280, 110);

	emit angleChanged(m_angle);
	emit powerChanged(m_power);
}

void Cannon::increaseAngle(double value)
{
	if (value <= 0)
		return;

	m_angle += value;

	if (m_angle > 90)
		m_angle = 90;

	m_cannon->setRotation(-m_angle);

	emit angleChanged(m_angle);
}

void Cannon::decreaseAngle(double value)
{
	if (value <= 0)
		return;

	m_angle -= value;

	if (m_angle < 0)
		m_angle = 0;

	m_cannon->setRotation(-m_angle);

	emit angleChanged(m_angle);
}

void Cannon::increasePower(double value)
{
	if (value <= 0)
		return;

	m_power += value;

	if (m_power > 100)
		m_power = 100;

	emit powerChanged(m_power);
}

void Cannon::decreasePower(double value)
{
	if (value <= 0)
		return;

	m_power -= value;

	if (m_power < 0)
		m_power = 0;

	emit powerChanged(m_power);
}

void Cannon::reset()
{
	m_angle = 0;
	m_power = 50;
	m_cannon->setRotation(0);
	emit powerChanged(m_power);
	emit angleChanged(m_angle);
}

CannonBall * Cannon::fire()
{
	double power = m_power;

	if (m_reversed)
		power *= -1;

	emit fired();
    return new CannonBall(QPixmap(":/resources/cannonball.png"), QVector2D(power * 2 * cos(toRadians(m_angle)), m_power * 2 * sin(toRadians(m_angle))), QVector2D(m_cannon->mapToScene(m_cannon->boundingRect().right(), m_cannon->boundingRect().top())), owner());
}

double Cannon::toRadians(double degrees)
{
	return degrees * 3.14159265 / 180.0;
}

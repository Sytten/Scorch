#include "Entities/CannonBall.h"

using namespace std;

CannonBall::CannonBall()
{
	//ctor
}

CannonBall::CannonBall(double p_initialAngle, double p_initialPower, Vector2<double> p_initialPosition)
{
	cout << "Une boule de cannon a ete cree!" << endl;

	m_initialPosition = p_initialPosition;
	cout << "je part du point (" << m_initialPosition.x << "," << m_initialPosition.y << ")" << endl;

	m_initialVelocity.x = sin(p_initialAngle) * p_initialPower;
	cout << "je vais a " << m_initialVelocity.x << "vers l'enemi" << endl;
	m_initialVelocity.y = cos(p_initialAngle) * p_initialPower;
	cout << "je vais a " << m_initialVelocity.y << "vers le haut" << endl;

}

void CannonBall::update(double p_deltaTime)
{
	m_time = p_deltaTime;

}


#include "Entities/CannonBall.h"

using namespace std;

CannonBall::CannonBall()
{
#ifdef GAME_DEBUG
	cout << "CannonBall::CannonBall" << endl;
#endif
}

CannonBall::CannonBall(double p_initialAngle, double p_initialPower, Vector2<double> p_initialPosition)
{
#ifdef GAME_DEBUG
	cout << "CannonBall::CannonBall(double, double, Vector2<double>)" << endl;
#endif

	m_initialPosition = p_initialPosition;

	m_initialVelocity.x = sin(p_initialAngle) * p_initialPower;
	

	m_initialVelocity.y = cos(p_initialAngle) * p_initialPower;
		
#ifdef GAME_DEBUG
	cout << "CannonBall starting from ( X:" << m_initialPosition.x << ", Y:" << m_initialPosition.y << ")" << endl;
	cout << "CannonBall At speed X: " << m_initialVelocity.x << endl;
	cout << "CannonBall At speed X: " << m_initialVelocity.y << endl;
#endif
}

CannonBall::~CannonBall()
{
#ifdef GAME_DEBUG
	cout << "CannonBall::~CannonBall" << endl;
#endif
}

void CannonBall::update(double p_deltaTime)
{
#ifdef GAME_DEBUG
	cout << "CannonBall::update(double)" << endl;
#endif
	m_time = p_deltaTime;

}

void CannonBall::collide(PhysicalEntity& p_collider)
{
#ifdef GAME_DEBUG
	cout << "CannonBall::collide" << endl;
#endif

	static int hitCount = 0;
	
	hitCount++;
	
	if(hitCount >= 2)
	{
		cout << "CannonBall hit" << endl;
	}
	else
	{
		cout << "CannonBall miss" << endl;
	}	
}


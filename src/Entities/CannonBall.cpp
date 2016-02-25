#include "Entities/CannonBall.h"

using namespace std;

CannonBall::CannonBall()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall::CannonBall" << endl;
#endif
	m_initialPosition.x = 0;
	m_initialPosition.y = 0;

	m_initialVelocity.x = 0;
	m_initialVelocity.y = 0;

	m_done = false;
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall starting from ( X:" << m_initialPosition.x << ", Y:" << m_initialPosition.y << ")" << endl;
	cout << "CannonBall At speed X: " << m_initialVelocity.x << endl;
	cout << "CannonBall At speed Y: " << m_initialVelocity.y << endl;
#endif
}

CannonBall::CannonBall(double p_initialAngle, double p_initialPower, Vector2<double> p_initialPosition)
{
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall::CannonBall(double, double, Vector2<double>)" << endl;
#endif

	m_initialPosition = p_initialPosition;

	m_initialVelocity.x = sin(p_initialAngle) * p_initialPower;


	m_initialVelocity.y = cos(p_initialAngle) * p_initialPower;

	m_done =  false;
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall starting from ( X:" << m_initialPosition.x << ", Y:" << m_initialPosition.y << ")" << endl;
	cout << "CannonBall At speed X: " << m_initialVelocity.x << endl;
	cout << "CannonBall At speed Y: " << m_initialVelocity.y << endl;
#endif
}

CannonBall::~CannonBall()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall::~CannonBall()" << endl;
#endif
}

void CannonBall::update(double p_deltaTime)
{
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall::update(double)" << endl;
#endif
    CollisionChecker::checkCollisions(*this);
    m_done = true;
}

void CannonBall::collide(PhysicalEntity& p_collider)
{
#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
	cout << "CannonBall::collide(PhysicalEntity&)" << endl;
#endif

	//TODO Add collision event

#if defined GAME_DEBUG && defined DEBUG_CANNON_BALL
    //cout << "CannonBall hit" << endl;
#endif
}


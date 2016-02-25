#include "Entities/Cannon.h"

using namespace std;

Cannon::Cannon()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::Cannon()" << endl;
#endif
	m_angle = 45;
	m_power = 50;

}

Cannon::~Cannon()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::~Cannon()" << endl;
#endif
	//ctor
}

void Cannon::powerUp()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::powerUp" << endl;
#endif
	m_power = m_power + 10;
	if (m_power >= m_maxPower)
	{
#if defined GAME_DEBUG && defined DEBUG_CANNON
		cout << "Cannot go higher than " << m_maxPower << endl;
#endif
		m_power = m_maxPower;
	}

}

void Cannon::powerDown()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::powerDown" << endl;
#endif
	m_power = m_power - 10;
	if (m_power <= m_minPower)
	{
#if defined GAME_DEBUG && defined DEBUG_CANNON
		cout << "Cannot go lower than " << m_minPower << endl;
#endif
		m_power = m_minPower;
	}

}

void Cannon::angleUp()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::angleUp" << endl;
#endif
	m_angle = m_angle + 10;
	if (m_angle >= m_maxAngle)
	{
#if defined GAME_DEBUG && defined DEBUG_CANNON
		cout << "Angle cannot be higher than " << m_maxAngle << endl;
#endif
		m_angle = m_maxAngle;

	}

}

void Cannon::angleDown()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::angleDown" << endl;
#endif
	m_angle = m_angle - 10;
	if (m_angle <= m_minAngle)
	{
#if defined GAME_DEBUG && defined DEBUG_CANNON
		cout << "Angle cannot be lower than " << m_minAngle << endl;
#endif
		m_angle = m_minAngle;
	}

}

void Cannon::update(double p_deltaTime)
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::update" << endl;
#endif

}


bool Cannon::reset()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::reset" << endl;
#endif
	return false;
}

std::shared_ptr<CannonBall> Cannon::fire()
{
#if defined GAME_DEBUG && defined DEBUG_CANNON
	cout << "Cannon::fire!" << endl;
#endif
    return make_shared<CannonBall>(m_angle, m_power, getPosition());
}

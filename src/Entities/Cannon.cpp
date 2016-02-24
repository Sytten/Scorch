#include "Entities/Cannon.h"

using namespace std;

Cannon::Cannon()
{
#ifdef GAME_DEBUG
	cout << "Cannon::Cannon" << endl;
#endif
	
	m_angle = 45;
	m_power = 50;

}

Cannon::~Cannon()
{
#ifdef GAME_DEBUG
	cout << "Cannon::~Cannon" << endl;
#endif
	//ctor
}

void Cannon::powerUp()
{
#ifdef GAME_DEBUG
	cout << "Cannon::powerUp" << endl;
#endif
	m_power = m_power + 10;
	if (m_power >= m_maxPower)
	{
#ifdef GAME_DEBUG
		cout << "Cannot go higher than " << m_maxPower << endl;
#endif
		m_power = m_maxPower;
	}
		
}

void Cannon::powerDown()
{
#ifdef GAME_DEBUG
	cout << "Cannon::powerDown" << endl;
#endif
	m_power = m_power - 10;
	if (m_power <= m_minPower)
	{
#ifdef GAME_DEBUG
		cout << "Cannot go lower than " << m_minPower << endl;
#endif
		m_power = m_minPower;
	}
		
}

void Cannon::angleUp()
{
#ifdef GAME_DEBUG
	cout << "Cannon::angleUp" << endl;
#endif
	m_angle = m_angle + 10;
	if (m_angle >= m_maxAngle)
	{
#ifdef GAME_DEBUG
		cout << "Angle cannot be higher than " << m_maxAngle << endl;
#endif
		m_angle = m_maxAngle;

	}

}

void Cannon::angleDown()
{
#ifdef GAME_DEBUG
	cout << "Cannon::angleDown" << endl;
#endif
	m_angle = m_angle - 10;
	if (m_angle <= m_minAngle)
	{
#ifdef GAME_DEBUG
		cout << "Angle cannot be lower than " << m_minAngle << endl;
#endif
		m_angle = m_minAngle;
	}
		
}

void Cannon::update(double p_deltaTime)
{
#ifdef GAME_DEBUG
	cout << "Cannon::update" << endl;
#endif

}


bool Cannon::reset()
{
#ifdef GAME_DEBUG
	cout << "Cannon::reset" << endl;
#endif
	return false;
}

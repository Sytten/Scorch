#include "Entities/Cannon.h"

using namespace std;

Cannon::Cannon()
{
	cout << "un canon est construit" << endl;
	//ctor
}

Cannon::~Cannon()
{
	cout << "un canon est construit" << endl;
	//ctor
}

void Cannon::powerUp()
{
	cout << "j'augmente la puissance de 10!" << endl;
	m_power = m_power + 10;
	if (m_power >= 100)
		m_power = 100;
}

void Cannon::powerDown()
{
	cout << "je diminue la puissance de 10!" << endl;
	m_power = m_power - 10;
	if (m_power <= 0)
		m_power = 0;
}

void Cannon::angleUp()
{
	cout << "j'augmente la l'angle de 10°" << endl;
	m_angle = m_angle + 10;
	if (m_angle >= 90)
		m_angle = 90;
}

void Cannon::angleDown()
{
	cout << "j'ai diminue l'angle de 10°" << endl;
	m_angle = m_angle - 10;
	if (m_angle <= 0)
		m_angle = 0;
}

void Cannon::update(double p_deltaTime)
{

}


bool Cannon::reset()
{
	return false;
}

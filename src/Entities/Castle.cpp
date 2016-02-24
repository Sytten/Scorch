#include "Entities/Castle.h"


using namespace std;

Castle::Castle()
{
#ifdef GAME_DEBUG
	cout << "Castle::Castle()" << endl;
#endif
	m_life = INITIAL_LIFE;
}

Castle::Castle(int p_initialLife)
{
#ifdef GAME_DEBUG
	cout << "Castle::Castle(int)" << endl;
#endif
	m_life = p_initialLife;
}

Castle::~Castle()
{
#ifdef GAME_DEBUG
	cout << "Castle::~Castle()" << endl;
#endif	
}

void Castle::update(double p_deltaTime)
{	
#ifdef GAME_DEBUG
	cout << "Castle::update(double)" << endl;
#endif
}

void Castle::collide(PhysicalEntity & p_collider)
{
#ifdef GAME_DEBUG
	cout << "Castle::collide(PhysicalEntity&)" << endl;
#endif
	
}

bool Castle::stillAlive() const
{
#ifdef GAME_DEBUG
	cout << "Castle::stillAlive(void)" << endl;
#endif
	if (m_life == 0)
		return false;
	return true;
}

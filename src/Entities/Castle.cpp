#include "Entities/Castle.h"


using namespace std;

Castle::Castle()
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::Castle()" << endl;
#endif
	m_life = INITIAL_LIFE;
}

Castle::Castle(int p_initialLife, int p_id)
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::Castle(int, int)" << endl;
#endif
	m_life = p_initialLife;
	m_id = p_id;
}

Castle::~Castle()
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::~Castle()" << endl;
#endif
}

void Castle::update(double p_deltaTime)
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::update(double)" << endl;
#endif
}

void Castle::collide(PhysicalEntity & p_collider)
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::collide(PhysicalEntity&)" << endl;
#endif

    m_life -= 10;

    if(m_life < 0)
        m_life = 0;
}

bool Castle::stillAlive() const
{
#if defined GAME_DEBUG && defined DEBUG_CASTLE
	cout << "Castle::stillAlive(void)" << endl;
#endif
	if (m_life > 0)
		return true;
	return false;
}

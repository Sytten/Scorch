#include "D:\\Qt\include\Entities\Castle.h"


using namespace std;

Castle::Castle()
{
}

Castle::Castle(int p_initialLife)
{
	cout << "un chateau a ete contruit" << endl;
    //ctor
}

void Castle::update(double p_deltaTime)
{
}

void Castle::collide(PhysicalEntity & p_collider)
{
}

bool Castle::stillAlive()
{
	if (m_life = 0)
		return false;
	return true;
}

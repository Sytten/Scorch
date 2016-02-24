#include "Entities/PhysicalEntity.h"

using namespace std;

PhysicalEntity::PhysicalEntity()
{
#ifdef GAME_DEBUG
	cout << "PhysicalEntity::PhysicalEntity()" << endl;
#endif
}

PhysicalEntity::~PhysicalEntity()
{
#ifdef GAME_DEBUG
	cout << "PhysicalEntity::~PhysicalEntity()" << endl;
#endif
}

void PhysicalEntity::collide(PhysicalEntity& p_collider)
{
#ifdef GAME_DEBUG
	cout << "PhysicalEntity::collide(PhysicalEntity&)" << endl;
#endif
}

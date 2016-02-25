#include "Entities/PhysicalEntity.h"

using namespace std;

PhysicalEntity::PhysicalEntity()
{
#if defined GAME_DEBUG && defined DEBUG_PHYS_ENTITY
	cout << "PhysicalEntity::PhysicalEntity()" << endl;
#endif
}

PhysicalEntity::~PhysicalEntity()
{
#if defined GAME_DEBUG && defined DEBUG_PHYS_ENTITY
	cout << "PhysicalEntity::~PhysicalEntity()" << endl;
#endif
}

void PhysicalEntity::collide(PhysicalEntity& p_collider)
{
#if defined GAME_DEBUG && defined DEBUG_PHYS_ENTITY
	cout << "PhysicalEntity::collide(PhysicalEntity&)" << endl;
#endif
}

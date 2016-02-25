#ifndef PHYSICALENTITY_H
#define PHYSICALENTITY_H

#include "Entity.h"
#include "CollisionChecker.h"

//#define DEBUG_PHYS_ENTITY

class PhysicalEntity : public Entity
{
    public:
        PhysicalEntity();
        virtual ~PhysicalEntity();

		virtual void collide(PhysicalEntity& p_collider);
};

#endif // PHYSICALENTITY_H

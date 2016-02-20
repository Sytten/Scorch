#ifndef PHYSICALENTITY_H
#define PHYSICALENTITY_H

#include "Entity.h"


class PhysicalEntity : public Entity
{
    public:
        PhysicalEntity();
        virtual ~PhysicalEntity();

      //  virtual void collide(PhysicalEntity& p_collider);
};

#endif // PHYSICALENTITY_H

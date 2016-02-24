#ifndef TERRAIN_H
#define TERRAIN_H

#include "Entities/PhysicalEntity.h"

class Terrain : public PhysicalEntity
{
    public:
        Terrain();

		~Terrain();

        void update(double p_deltaTime);

        void collide(PhysicalEntity& p_collider);
};

#endif // TERRAIN_H

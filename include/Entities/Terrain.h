#ifndef TERRAIN_H
#define TERRAIN_H

#include "D:\\Qt\include\Entities\PhysicalEntity.h"

class Terrain : public PhysicalEntity
{
    public:
        Terrain();

        void update(double p_deltaTime);

        void collide(PhysicalEntity& p_collider);
};

#endif // TERRAIN_H

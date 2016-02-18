#ifndef TERRAIN_H
#define TERRAIN_H

#include "Entities/Entity.h"

class Terrain : public Entity
{
    public:
        Terrain();

        void update(double p_deltaTime);
};

#endif // TERRAIN_H

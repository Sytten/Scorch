#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H

#include "Entities/Entity.h"

class CollisionChecker
{
    public:
        CollisionChecker();

        static bool collide(Entity &p_entity);

        static bool registerEntity(Entity )

    private:
        vector<Entity> m_entities;
};

#endif // COLLISIONCHECKER_H

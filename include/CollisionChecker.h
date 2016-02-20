#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H

#include <memory>

#include "Entities/Entity.h"

class CollisionChecker
{
    public:
        CollisionChecker();

       // static bool collide(Entity& p_entity);

       // static bool registerEntity(std::weak_ptr<Entity> p_newEntity);
       // static bool unregisterEntity(int p_oldEntityID);

    private:
       // static vector<std::weak_ptr<Entity> > m_entities;
};

#endif // COLLISIONCHECKER_H

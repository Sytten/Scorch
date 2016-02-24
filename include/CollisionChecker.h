#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H

#include <memory>
#include <vector>

class PhysicalEntity;

class CollisionChecker
{
    public:
        CollisionChecker();

        static bool checkCollisions(PhysicalEntity& p_entity);

        static bool registerEntity(std::weak_ptr<PhysicalEntity> p_newEntity);
        //static bool unregisterEntity(int p_oldEntityID);

    private:
        static std::vector<std::weak_ptr<PhysicalEntity> > m_entities;
};

#endif // COLLISIONCHECKER_H

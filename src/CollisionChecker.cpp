#include "CollisionChecker.h"
#include "Entities/PhysicalEntity.h"

using namespace std;

std::vector<std::weak_ptr<PhysicalEntity> > CollisionChecker::m_entities;

CollisionChecker::CollisionChecker()
{
    //ctor
}

bool CollisionChecker::checkCollisions(PhysicalEntity& p_entity)
{
#ifdef GAME_DEBUG
    static int numberOfCalls = 0;

    if(numberOfCalls > 1)
    {
        for(int i = 0; i < m_entities.size(); i++)
        {
            auto entity = m_entities[i].lock();
            if(entity)
            {
                if(entity->getID() == 1002)
                {
                    entity->collide(p_entity);
                    p_entity.collide(*entity);
                }
            }
            else
                m_entities.erase(m_entities.begin()+i);
        }
    }
    else
        cout << "CannonBall missed" << endl;

    numberOfCalls++;
#endif

}

bool CollisionChecker::registerEntity(std::weak_ptr<PhysicalEntity> p_newEntity)
{
    m_entities.push_back(p_newEntity);
    return true;
}

#ifndef CASTLE_H
#define CASTLE_H

#include "Entities/PhysicalEntity.h"
#include <iostream>

#define INITIAL_LIFE 5

class Castle : public PhysicalEntity
{
    public:
		Castle();
        Castle(int p_initialLife);

		///TEMP pour tests
		Castle(int p_initialLife, int p_id);

		~Castle();

        void update(double p_deltaTime);
        void collide(PhysicalEntity& p_collider);

        bool stillAlive() const;

    private:
        int m_life;
};

#endif // CASTLE_H

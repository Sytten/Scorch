#ifndef CASTLE_H
#define CASTLE_H

#include "D:\\Qt\include\Entities\PhysicalEntity.h"
#include <iostream>


class Castle : public PhysicalEntity
{
    public:
		Castle();
        Castle(int p_initialLife);

        void update(double p_deltaTime);

        void collide(PhysicalEntity& p_collider);

        bool stillAlive();

    private:
        int m_life;
};

#endif // CASTLE_H

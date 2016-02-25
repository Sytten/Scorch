#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <math.h>
#include <iostream>

#include "Entities/PhysicalEntity.h"
#include "Helper/Vector2.h"

//#define DEBUG_CANNON_BALL

class CannonBall : public PhysicalEntity
{
    public:
        CannonBall();
        CannonBall(double p_initialAngle, double p_initialPower, Vector2<double> p_initialPosition);

		~CannonBall();

		void collide(PhysicalEntity& p_collider);
        void update(double p_deltaTime);

        bool done() { return m_done; }

    private:
		Vector2<double>  m_initialPosition;
		Vector2<double>  m_initialVelocity;

        double m_time;
        bool m_done;
};

#endif // CANNONBALL_H

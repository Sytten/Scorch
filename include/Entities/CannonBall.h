#ifndef CANNONBALL_H
#define CANNONBALL_H

#include "Entities/Entity.h"
#include "Vector2.h"

class CannonBall : public Entity
{
    public:
        CannonBall() = delete;
        CannonBall(double p_initialAngle, double p_initialPower, Vector2<double> m_initialPosition);

        void update(double p_deltaTime);

    private:
        Vector2<double> const m_initialPosition;
        Vector2<double> const m_initialVelocity;

        double m_time;
};

#endif // CANNONBALL_H

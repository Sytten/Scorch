#ifndef CANNON_H
#define CANNON_H

#include <memory>

#include "Entities/CannonBall.h"
#include "Entities/Entity.h"

class Cannon : Entity
{
    public:
        Cannon();

        void powerUp();
        void powerDown();

        void angleUp();
        void angleDown();

        std::shared_ptr<CannonBall> fire();

        void update(double p_deltaTime);

        bool reset();

    private:
        double m_angle;
        double const m_maxAngle;
        double const m_minAngle;

        double m_power;
        double const m_maxPower;
        double const m_minPower;
};

#endif // CANNON_H

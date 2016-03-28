#ifndef CANNON_H
#define CANNON_H

#include <memory>

#include "Entities/CannonBall.h"
#include "Entities/Entity.h"

//#define DEBUG_CANNON

class Cannon : public Entity
{
    public:
        Cannon();

		~Cannon();

        void powerUp();
        void powerDown();

        void angleUp();
        void angleDown();

		std::shared_ptr<CannonBall> fire();

        void update(double p_deltaTime);

        bool reset();

    private:
        double m_angle;
        double const m_maxAngle = 90;
        double const m_minAngle = 0;

        double m_power;
        double const m_maxPower = 100;
        double const m_minPower = 0;

};

#endif // CANNON_H

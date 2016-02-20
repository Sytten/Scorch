#ifndef CANNON_H
#define CANNON_H

#include <memory>

#include "D:\\Qt\include\Entities\CannonBall.h"
#include "D:\\Qt\include\Entities\Entity.h"

class Cannon //: public Entity
{
    public:
        Cannon();

        void powerUp();
        void powerDown();

        void angleUp();
        void angleDown();

       // std::shared_ptr<CannonBall> fire();

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

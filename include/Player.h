#ifndef PLAYER_H
#define PLAYER_H

#include <memory>

#include "Entities/CannonBall.h"
#include "Entities/Cannon.h"
#include "Entities/Castle.h"

#define DEBUG_PLAYER

class Player
{
    public:
        Player();

		///TEMP pour tests
		Player(int p_id);

        void increasePower();
        void decreasePower();

        void increaseAngle();
        void decreaseAngle();

        bool isAlive();

        void update(double p_deltaTime);

        std::shared_ptr<CannonBall> fire();

    private:
        Cannon m_cannon;
        std::shared_ptr<Castle> m_castle;
};

#endif // PLAYER_H

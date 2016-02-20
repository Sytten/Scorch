#ifndef GAME_H
#define GAME_H

#include <memory>

#include "Player.h"
#include "Inputs/InputHandler.h"
#include "Entities/CannonBall.h"

enum State {
    Play,
    Pause,
    Exit
};

class Game
{
    public:
        Game();

        void play();
        void pause();

    private:
        std::shared_ptr<Player> m_player1;
        std::shared_ptr<Player> m_player2;
        std::shared_ptr<CannonBall> m_currentCannonBall;
};

#endif // GAME_H

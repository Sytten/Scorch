#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>
#include "Player.h"
#include "Entities\Terrain.h"

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
        State m_currentState;
        bool m_player1Turn;
};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>
#include "Player.h"

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
		State currentState;
};

#endif // GAME_H

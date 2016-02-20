#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>
#include "Player.h"

//#include "D:\\Qt\\include\\Player.h"
//#include "D:\\Qt\\include\\Inputs\\InputHandler.h"
//#include "D:\\Qt\\include\\Entities\\CannonBall.h"

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

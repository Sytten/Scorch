#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Inputs/InputHandler.h"

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
};

#endif // GAME_H

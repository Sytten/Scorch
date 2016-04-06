/********
File: State.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Various States enum used for the game management
********/

#ifndef STATE_H
#define STATE_H

enum InputState {Angle = 0, Power, Fire, NoState};

enum GameState {Play = 0, Pause, Transition, Menu};

enum Difficulty {Easy = 0, Intermediate, Hard, Random};

#endif // STATE_H

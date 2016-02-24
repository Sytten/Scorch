#include "Game.h"

using namespace std;

Game::Game()
{
	cout << "on genere le jeu" << endl;
	Player();
	Player();
    //ctor
}

void Game::play()
{
	currentState = Play;
	cout << "Le jeu est en marche!" << endl;

}

void Game::pause()
{
	currentState = Pause;
	cout << "Le jeu est sur pause" << endl;
}

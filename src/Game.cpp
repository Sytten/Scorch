#include "Game.h"

using namespace std;

Game::Game() : m_player1(new Player()), m_player2(new Player()), m_currentCannonBall(nullptr), m_currentState(Exit), m_player1Turn(true)
{
#ifdef GAME_DEBUG
	cout << "Game generation" << endl;
#endif
}

void Game::play()
{
#ifdef GAME_DEBUG
    cout << "Game is starting" << endl;
#endif

	m_currentState = Play;

    int iteration = 0;

    while(m_currentState != Exit)
    {
        switch (iteration)
        {
            case 1:
                m_player1->increaseAngle();
                m_player1->increaseAngle();
                m_player1->decreaseAngle();
                iteration++;
                break;

            case 2:
                m_player1->increasePower();
                m_player1->increasePower();
                m_player1->decreasePower();
                iteration++;
                break;

            case 3:
                m_currentCannonBall = m_player1->fire();
                if(!m_player1Turn)
                    iteration++;
                break;

            case 4:
                pause();
                iteration++;
                break;

            case 5:
                //player 2 adjust angle
                break;

            case 6:
                //player 2 adjust power
                break;

            case 7:
                //player 2 Shoot and wait
                break;

            case 8:
                //player 1 adjust angle
                break;

            case 9:
                //player 1 adjust power
                break;

            case 10:
                //player 1 shoot and wait
                break;

            default:
                break;
        }

        m_currentState = Exit;

        if(m_player1)
            m_player1->update();
        if(m_player2)
            m_player2->update();
        if(m_currentCannonBall)
            m_currentCannonBall->update();

        //Check if players alive, if one is not = game over
        //Check if cannonBall done and change playerTurn
    }
}

void Game::pause()
{
#ifdef GAME_DEBUG
	cout << "Game is Pausing" << endl;
#endif

    m_currentState = Pause;

    while(m_currentState == Pause)
    {
        for(int i = 10; i > 0; i++)
        {
#ifdef GAME_DEBUG
            cout << i << endl;
#endif
        }

        m_currentState = Play;
    }

#ifdef GAME_DEBUG
    cout << Game is resuming << endl;
#endif
}

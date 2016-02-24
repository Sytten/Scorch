#include "Game.h"

using namespace std;

Game::Game() : m_player1(new Player(1001)), m_player2(new Player(1002)), m_currentCannonBall(nullptr), m_currentState(Exit), m_player1Turn(true)
{
#ifdef GAME_DEBUG
	cout << "Game generation" << endl;
#endif
}

void Game::play()
{
#ifdef GAME_DEBUG
    cout << "Game is starting" << endl;

    int iteration = 1;
#endif

	m_currentState = Play;

    while(m_currentState != Exit)
    {
#ifdef GAME_DEBUG
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
                iteration++;
                break;

            case 4:
                if(!m_player1Turn)
                    iteration++;
                break;

            case 5:
                pause();
                iteration++;
                break;

            case 6:
                m_player2->increaseAngle();
                m_player2->increaseAngle();
                m_player2->decreaseAngle();
                iteration++;
                break;

            case 7:
                m_player2->increasePower();
                m_player2->increasePower();
                m_player2->decreasePower();
                iteration++;
                break;

            case 8:
                m_currentCannonBall = m_player2->fire();
                iteration++;
                break;

            case 9:
                if(m_player1Turn)
                    iteration++;
                break;

            case 10:
                m_player1->increaseAngle();
                iteration++;
                break;

            case 11:
                m_player1->increasePower();
                m_player1->increasePower();
                iteration++;
                break;

            case 12:
                m_currentCannonBall = m_player1->fire();
                iteration++;
                break;

            case 13:
                if(!m_player1Turn)
                    iteration++;
                break;

            default:
				
                break;
        }
#endif

        if(m_currentCannonBall)
        {
            m_currentCannonBall->update(0.1);

            if(m_currentCannonBall->done())
            {
                m_player1Turn = !m_player1Turn;
                m_currentCannonBall.reset();
            }
        }

        if(m_player1 && m_player2)
        {
            m_player1->update(0.1);
            m_player2->update(0.1);

            if(!m_player1->isAlive())
            {
#ifdef GAME_DEBUG
                cout << "Player 2 wins!!!!" << endl;
#endif
                m_currentState = Exit;
            }
            else if(!m_player2->isAlive())
            {
#ifdef GAME_DEBUG
                cout << "Player 1 wins!!!!" << endl;
#endif
                m_currentState = Exit;
            }
        }

#ifdef GAME_DEBUG
		cout << "End of a game loop" << endl;
		cin.get();
#endif
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
        for(int i = 10; i > 0; i--)
        {
#ifdef GAME_DEBUG
            cout << i << endl;
#endif
        }

        m_currentState = Play;
    }

#ifdef GAME_DEBUG
    cout << "Game is resuming" << endl;
#endif
}

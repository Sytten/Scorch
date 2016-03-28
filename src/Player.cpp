#include "Player.h"

using namespace std;


Player::Player() : m_castle(new Castle())
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::Player()" << endl;
#endif
    CollisionChecker::registerEntity(m_castle);
}

////TEMP pour tests
Player::Player(int p_id) : m_castle(new Castle(5, p_id))
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::Player(int)" << endl;
#endif
    CollisionChecker::registerEntity(m_castle);
}

void Player::increasePower()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::increasePower()" << endl;
#endif
	m_cannon.powerUp();
}

void Player::decreasePower()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::decreasePower()" << endl;
#endif
	m_cannon.powerDown();
}

void Player::increaseAngle()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::increaseAngle()" << endl;
#endif
	m_cannon.angleUp();
}

void Player::decreaseAngle()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::decreaseAngle()" << endl;
#endif
	m_cannon.angleDown();

}

bool Player::isAlive()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::isAlive()" << endl;
#endif
	if (m_castle){	
        bool returnValue = m_castle->stillAlive();
#if defined GAME_DEBUG && defined DEBUG_PLAYER
		if (returnValue)
			cout << "Player is still alive" << endl;
		else
			cout << "Player is eliminated" << endl;
#endif
		return returnValue;
	}
	cout << "Player is eliminated" << endl;
    return false;
}

void Player::update(double p_deltaTime)
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::update(double)" << endl;
#endif

}

std::shared_ptr<CannonBall> Player::fire()
{
#if defined GAME_DEBUG && defined DEBUG_PLAYER
	cout << "Player::fire()" << endl;
#endif
    return m_cannon.fire();
}

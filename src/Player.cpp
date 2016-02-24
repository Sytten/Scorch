#include "Player.h"

using namespace std;


Player::Player() : m_castle(new Castle())
{
#ifdef GAME_DEBUG
	cout << "Player::Player()" << endl;
#endif
    CollisionChecker::registerEntity(m_castle);
}

////TEMP pour tests
Player::Player(int p_id) : m_castle(new Castle(5, p_id))
{
#ifdef GAME_DEBUG
	cout << "Player::Player(int)" << endl;
#endif
    CollisionChecker::registerEntity(m_castle);
}

void Player::increasePower()
{
#ifdef GAME_DEBUG
	cout << "Player::increasePower()" << endl;
#endif
	m_cannon.powerUp();
}

void Player::decreasePower()
{
#ifdef GAME_DEBUG
	cout << "Player::decreasePower()" << endl;
#endif
	m_cannon.powerDown();
}

void Player::increaseAngle()
{
#ifdef GAME_DEBUG
	cout << "Player::increaseAngle()" << endl;
#endif
	m_cannon.angleUp();
}

void Player::decreaseAngle()
{
#ifdef GAME_DEBUG
	cout << "Player::decreaseAngle()" << endl;
#endif
	m_cannon.angleDown();

}

bool Player::isAlive()
{
#ifdef GAME_DEBUG
	cout << "Player::isAlive()" << endl;
#endif
    if(m_castle)
        return m_castle->stillAlive();
    else
        return false;
}

void Player::update(double p_deltaTime)
{
#ifdef GAME_DEBUG
	cout << "Player::update(double)" << endl;
#endif

}

std::shared_ptr<CannonBall> Player::fire()
{
#ifdef GAME_DEBUG
	cout << "Player::fire()" << endl;
#endif
    return m_cannon.fire();
}

#include "Player.h"

using namespace std;


Player::Player()
{
#ifdef GAME_DEBUG
	cout << "Player::Player()" << endl;
#endif
	cout << "Joueur est cree" << endl;

	m_castle = Castle();
	m_cannon = Cannon();
}

////TEMP pour tests
Player::Player(int p_id)
{
#ifdef GAME_DEBUG
	cout << "Player::Player(int)" << endl;
#endif
	m_castle = Castle(5, p_id);
	m_cannon = Cannon();
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
	return m_castle.stillAlive();
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

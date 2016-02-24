#include "Player.h"
#include "Entities/Cannon.h"

using namespace std;


Player::Player()
{
	cout << "Joueur est cree" << endl;
}

void Player::increasePower()
{
	m_cannon.powerUp();
}

void Player::decreasePower()
{
	m_cannon.powerDown();
}

void Player::increaseAngle()
{
	m_cannon.angleUp();
}

void Player::decreaseAngle()
{
	m_cannon.angleDown();

}

bool Player::isAlive()
{
	return m_castle.stillAlive();
}

void Player::update(double p_deltaTime)
{

}

std::shared_ptr<CannonBall> fire()
{
    return Cannon.fire();
}

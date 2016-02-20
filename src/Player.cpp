#include "C:\Users\Phil\Documents\Visual Studio 2015\Projects\Console_Scorch_P19\Console_Scorch_P19\include/Player.h"
#include "C:\Users\Phil\Documents\Visual Studio 2015\Projects\Console_Scorch_P19\Console_Scorch_P19\include\Entities\Cannon.h"

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
	return true;
}

void Player::update(double p_deltaTime)
{

}

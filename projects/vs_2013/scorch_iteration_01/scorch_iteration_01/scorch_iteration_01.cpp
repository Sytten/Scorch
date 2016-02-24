// scorch_iteration_01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include "Game.h"

void testCannon(Cannon cannon);
void testCannonBall(CannonBall cannonBall);
void testCollision(CannonBall cannonBall, PhysicalEntity & physE);


int _tmain(int argc, _TCHAR* argv[])
{
	CannonBall cannonBall;
	Castle castle;
	testCannonBall(cannonBall);
	testCollision(cannonBall, castle);

	Cannon cannon;
	testCannon(cannon);

	return 0;
}


void testCannon(Cannon cannon)
{
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();
	cannon.angleUp();

	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();
	cannon.angleDown();

	std::cin.get();
}

void testCannonBall(CannonBall cannonBall)
{
	struct Vector2<double> vector;

	vector.x = 15;
	vector.y = 13;

	cannonBall.move(vector);



	std::cin.get();
}

void testCollision(CannonBall cannonBall, PhysicalEntity & physE)
{

	cannonBall.collide(physE);
	cannonBall.collide(physE);
	cannonBall.collide(physE);
	cannonBall.collide(physE);
	cannonBall.collide(physE);

	std::cin.get();
}
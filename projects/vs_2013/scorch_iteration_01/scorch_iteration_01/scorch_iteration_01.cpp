// scorch_iteration_01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include "Game.h"
#include "Entities\Terrain.h"

#define PLAY_GAME
//#define PLAY_TEST

void testCannon(Cannon cannon);
void testCannonBall(CannonBall cannonBall);
void testCollision(CannonBall cannonBall, PhysicalEntity & physE);
void testTerrain();


int _tmain(int argc, _TCHAR* argv[])
{
#ifdef PLAY_TEST
	CannonBall cannonBall;
	Castle castle;
	testCannonBall(cannonBall);
	testCollision(cannonBall, castle);

	Cannon cannon;
	testCannon(cannon);
	testTerrain();
#endif

#ifdef PLAY_GAME
	Game game;
	game.play();
#endif

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

void testTerrain()
{
	Terrain terrain;

	//Tests supplémentaires à développer lors de l'avancement du terrain
}
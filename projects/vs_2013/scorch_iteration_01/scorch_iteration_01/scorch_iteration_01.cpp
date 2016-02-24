// scorch_iteration_01.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <string>
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
	CannonBall * cannonBall = new CannonBall();
	Castle castle;

	Cannon cannon;

	cannonBall->collide(castle);
	cannonBall->collide(castle); 
	cannonBall->collide(castle);
	cannonBall->collide(castle);
	cannonBall->collide(castle);

	std::cin.get();

	return 0;
}


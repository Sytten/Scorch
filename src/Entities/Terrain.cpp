#include "Entities/Terrain.h"

using namespace std;

Terrain::Terrain()
{
#ifdef GAME_DEBUG
	cout << "Terrain::Terrain()" << endl;
#endif	
}

Terrain::~Terrain()
{
#ifdef GAME_DEBUG
	cout << "Terrain::~Terrain()" << endl;
#endif	
}

void Terrain::update(double p_deltaTime)
{
#ifdef GAME_DEBUG
	cout << "Terrain::update(double)" << endl;
#endif	
}

void Terrain::collide(PhysicalEntity & p_collider)
{
#ifdef GAME_DEBUG
	cout << "Terrain::collide(PhysicalEntity)" << endl;
#endif
}

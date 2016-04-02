#ifndef BEZIERCURVES_H
#define BEZIERCURVES_H

#include <iostream>
#include <math.h>
#include <time.h>

class Curves
{
public:
	Curves();
	Curves(std::string passed);
	~Curves();

	// setter.
	void setTerrainType(std::string passed);

	//getter.
	void getXVal(float x[]);
	void getYVal(float y[]);

	//Functions.
	void printDataPTS();
	void printDataLine();
	float getPt(float n1, float n2, float perc);
	void drawLine();


private:
	float xTab[_DMAX];
	float yTab[_DMAX];

	bool highTerrain = false;
	bool lowTerrain = false;
	bool insaneTerrain = false;
	bool flatTerrain = true;

	float x[10000];
	float y[10000];


};

#endif
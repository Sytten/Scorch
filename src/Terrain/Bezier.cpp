#include "Terrain/Bezier.h"

using namespace std;


Curves::Curves()
{}

Curves::Curves(string passed)
{
	srand(time(0));
	setTerrainType(passed);

	if (insaneTerrain)
	{
		for (int i = 1; i <= 10; i++)
		{
			xTab[i] = i * 10;
			yTab[i] = (rand() % 100) + (fmod(rand(), 1000) / 1000);
		}
	}

	if (flatTerrain)
	{
		for (int i = 1; i <= 10; i++)
		{
			xTab[i] = i * 10;
			yTab[i] = 1;
		}
	}

	if (highTerrain)
	{
		for (int i = 1; i <= 10; i++)
		{
			xTab[i] = i * 10;
			yTab[i] = (rand() % 100) + (fmod(rand(), 100) / 1000);
		}
	}

	if (lowTerrain)
	{
		for (int i = 1; i <= 10; i++)
		{
			xTab[i] = i * 10;
			yTab[i] = (rand() % 10) + (fmod(rand(), 100) / 1000);
		}
	}
}

Curves::~Curves()
{}

void Curves::setTerrainType(std::string passed)
{
	if (passed == "Insane" || passed == "insane")
	{
		insaneTerrain = true;
		lowTerrain = false;
		highTerrain = false;
		flatTerrain = false;
	}

	if (passed == "High" || passed == "high")
	{
		insaneTerrain = false;
		lowTerrain = false;
		highTerrain = true;
		flatTerrain = false;
	}

	if (passed == "Low" || passed == "low")
	{
		insaneTerrain = false;
		lowTerrain = true;
		highTerrain = false;
		flatTerrain = false;
	}

	if (passed == "Flat" || passed == "flat")
	{
		insaneTerrain = false;
		lowTerrain = false;
		highTerrain = false;
		flatTerrain = true;
	}
	/*else
	{
	cout << "not a choice dumbass!" << endl;
	return;
	}*/

}

void Curves::printDataPTS()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << "X value: " << xTab[i] << "	Y Value: " << yTab[i] << endl;
	}
}

float Curves::getPt(float n1, float n2, float perc)
{
	int diff = n2 - n1;

	return n1 + diff*perc;
}

void Curves::drawLine()
{
	float xa;
	float xb;
	float ya;
	float yb;

	for (int j = 0; j <= 8; j++)
	{

		for (int i = 1; i <= 100; i++)
		{
			// The Green Line
			xa = getPt(xTab[1+j], xTab[2+j], i*0.01);
			ya = getPt(yTab[1+j], yTab[2+j], i*0.01);
			//cout << " " << (float)xa << "," << (float)ya << "		";			DEGUG!!!!!!!!!
			xb = getPt(xTab[2+j], xTab[3+j], i*0.01);
			yb = getPt(yTab[2+j], yTab[3+j], i*0.01);
			//cout << (float)xb << "," << (float)yb << endl;					DEBUG!!!!!!!!!

			// The Black Dot
			x[(j*100)+i] = (1 - i*0.01)*xa + i*0.01*xb;
			y[(j*100)+i] = (1 - i*0.01)*ya + i*0.01*yb;
		}
	}
}

void Curves::printDataLine()
{
	cout << "pts de la ligne" << endl;

	for (int i = 1; i <= 700;i++)
	{
		cout << "	X line: " << x[i] << "	Y line: " << y[i];
		
	}
}

void Curves::getXVal(float xVal[])
{
	int i = 0;

	while (x != nullptr)
	{
		xVal[i] = x[i];
		i++;
	}
}

void Curves::getYVal(float yVal[])
{
	int i = 0;

	while (y != nullptr)
	{
		yVal[i] = y[i];
		i++;
	}
}


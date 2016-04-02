#include <qpainterpath.h>



class Terrain
{

public:
	Terrain();
	~Terrain();
	void generateTerrain();
	//void changeTerrain();

private:
	float xVal[1000];
	float yVal[1000];
};
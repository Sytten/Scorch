#include <iostream>
#include <time.h>
#include <QApplication>

#include "GameWindow.h"

using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));

	QApplication app(argc, argv);
	GameWindow window; 

	window.showMaximized();
	app.exec();
}

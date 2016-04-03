#include <iostream>
#include <QApplication>

#include "GameWindow.h"

using namespace std;

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	GameWindow window; 

	window.showMaximized();
	app.exec();
}
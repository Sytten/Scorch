#include "GameWindow.h"


GameWindow::GameWindow(QWidget *parent):QMainWindow(parent)
{
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;

	layout->addWidget(m_mainGameWidget);

	//bottomLayout->addWidget(m_newGameButton);





	//layout->addLayout(bottomLayout);
	setLayout(layout);
}


GameWindow::~GameWindow()
{
}


void GameWindow::keyPressEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
		return;
	switch (event->key()){
	case Qt::Key_Right:
	case Qt::Key_Left:
		break;
	case Qt::Key_Up:
	case Qt::Key_Down:
		break;
	default:
		break;
	}
}

void GameWindow::keyReleaseEvent(QKeyEvent *event)
{
	if (event->isAutoRepeat())
		return;

	switch (event->key()) {
	case Qt::Key_Right:
	case Qt::Key_Left:
		break;
	case Qt::Key_Up:
	case Qt::Key_Down:
		break;
	default:
		break;
	}
}
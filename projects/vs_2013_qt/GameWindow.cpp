#include "GameWindow.h"


GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{
	setupUI();
}

void GameWindow::setupUI()
{
	QVBoxLayout *layout = new QVBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;

	m_mainGameWidget = new QLabel("This is the core of the game");
	m_mainGameWidget->setStyleSheet("QLabel { background-color : red; color : blue; }");
	m_mainGameWidget->setMinimumSize(QSize(800, 600));
	
	layout->addWidget(m_mainGameWidget);


	m_newGameButton = new QPushButton("Nouvelle partie");
	bottomLayout->addWidget(m_newGameButton);

	QVBoxLayout *modeLayout = new QVBoxLayout;
	m_currentMode = new QLabel("Current mode goes here");
	m_currentPlayerTurn = new QLabel("Current player turn goes here");
	modeLayout->addWidget(m_currentMode);
	modeLayout->addWidget(m_currentPlayerTurn);
	bottomLayout->addLayout(modeLayout);

	m_currentAngle = new QLabel("Current angle of fire goes here");
	m_currentPower = new QLabel("Current power of fire goes here");

	bottomLayout->addWidget(m_currentAngle);
	bottomLayout->addWidget(m_currentPower);

	layout->addLayout(bottomLayout);
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
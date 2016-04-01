#include "Information/GameModeWidget.h"

GameModeWidget::GameModeWidget(QWidget * parent) :QWidget(parent)
{
	//This should be an object
	QVBoxLayout *modeLayout = new QVBoxLayout;
	m_playerControlAngle = new PlayerControlModeWidget(1, true);
	m_playerControlPower = new PlayerControlModeWidget(2, false);
	m_playerControlFire = new PlayerControlModeWidget(3, false);

	m_player1Indicator = new PlayerActivatedWidget;
	m_player2Indicator = new PlayerActivatedWidget(2, false);

	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;

	topLayout->addWidget(m_playerControlAngle);
	topLayout->addWidget(m_playerControlPower);
	topLayout->addWidget(m_playerControlFire);

	bottomLayout->addWidget(m_player1Indicator);
	bottomLayout->addWidget(m_player2Indicator);

	modeLayout->addLayout(topLayout);
	modeLayout->addWidget(new QLabel("Tour du joueur :"));
	modeLayout->addLayout(bottomLayout);

	setLayout(modeLayout);
}

GameModeWidget::~GameModeWidget()
{

}


void setCurrentPlayer(int player)
{
	m_player1Indicator->setActivated(!m_player1Indicator->activated());
	m_player2Indicator->setActivated(!m_player2Indicator->activated());
}

int GameModeWidget::currentPlayer()const
{
	if (m_player1Indicator->activated())
		return 1;
	return 2;
}

void GameModeWidget::setCurrentMode(int gameMode)
{

}

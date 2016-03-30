#include "Information/GameModeWidget.h"

GameModeWidget::GameModeWidget(QWidget * parent) :QWidget(parent)
{
	//This should be an object
	QVBoxLayout *modeLayout = new QVBoxLayout;
	m_currentMode = new QLabel("Current mode goes here");
	m_player1Indicator = new PlayerActivatedWidget;
	m_player2Indicator = new PlayerActivatedWidget(2, false);

	QHBoxLayout *topLayout = new QHBoxLayout;
	QHBoxLayout *bottomLayout = new QHBoxLayout;

	topLayout->addWidget(m_currentMode);

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


void GameModeWidget::togglePlayer()
{
	m_player1Indicator->setActivated(!m_player1Indicator->activated());
	m_player2Indicator->setActivated(!m_player2Indicator->activated());
}

int GameModeWidget::getCurrentPlayer()const
{
	if (m_player1Indicator->activated())
		return 1;
	return 2;
}

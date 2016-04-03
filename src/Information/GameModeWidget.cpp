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

	QLabel * mode = new QLabel("Mode :");
	QLabel * joueur = new QLabel("Tour du joueur :");
	
	QFont font = mode->font();
	font.setPointSize(20);
	font.setBold(true);
	mode->setFont(font);
	
	QFont font1 = joueur->font();
	font1.setPointSize(20);
	font1.setBold(true);
	joueur->setFont(font1);
	
	bottomLayout->addWidget(m_player1Indicator);
	bottomLayout->addWidget(m_player2Indicator);
	modeLayout->addWidget(mode);
	modeLayout->addLayout(topLayout);
	modeLayout->addWidget(joueur);
	modeLayout->addLayout(bottomLayout);
	setLayout(modeLayout);
}

GameModeWidget::~GameModeWidget()
{

}


void GameModeWidget::setCurrentPlayer(Player player)
{
	if (player == Player::Player1)
	{
		m_player1Indicator->setActivated(true);
		m_player2Indicator->setActivated(false);
	}
	else if(player == Player::Player2)
	{
		m_player1Indicator->setActivated(false);
		m_player2Indicator->setActivated(true);
	}
	else
	{
		m_player1Indicator->setActivated(false);
		m_player2Indicator->setActivated(false);
	}
}

Player GameModeWidget::currentPlayer()const
{
	if (m_player1Indicator->activated())
		return Player::Player1;
	else if (m_player2Indicator->activated())
		return Player::Player2;
	return Player::NoPlayer;
}

State GameModeWidget::currentMode()const
{
	if (m_playerControlAngle->activated())
		return State::Angle;
	else if (m_playerControlFire->activated())
		return State::Fire;
	else if (m_playerControlPower->activated())
		return State::Power;
	return State::NoState;
}

void GameModeWidget::setCurrentMode(State gameMode)
{
	if (gameMode == State::Angle)
	{
		m_playerControlAngle->setActivated(true);
		m_playerControlFire->setActivated(false);
		m_playerControlPower->setActivated(false);
	}
	else if (gameMode == State::Fire)
	{
		m_playerControlAngle->setActivated(false);
		m_playerControlFire->setActivated(true);
		m_playerControlPower->setActivated(false);
	}
	else if (gameMode == State::Power)
	{
		m_playerControlAngle->setActivated(false);
		m_playerControlFire->setActivated(false);
		m_playerControlPower->setActivated(true);
	}
	else
	{
		m_playerControlAngle->setActivated(false);
		m_playerControlFire->setActivated(false);
		m_playerControlPower->setActivated(false);
	}

}

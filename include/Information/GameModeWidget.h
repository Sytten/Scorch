#ifndef GAMEMODEWIDGET_H
#define GAMEMODEWIDGET_H

#include <QtWidgets>

#include "PlayerActivatedWidget.h"
#include "PlayerControlModeWidget.h"

#include "Game\Player.h"
#include "Game\State.h"

class GameModeWidget : public QWidget
{
public:
	GameModeWidget(QWidget * parent = 0);
	~GameModeWidget();

	Player currentPlayer()const;
	State currentMode()const;

protected:

private:
	PlayerActivatedWidget * m_player1Indicator,
		*m_player2Indicator;
	PlayerControlModeWidget * m_playerControlAngle, 
							* m_playerControlPower, 
							* m_playerControlFire;
public slots:
	void setCurrentMode(State gameMode);
	void setCurrentPlayer(Player player);
};

#endif

#ifndef GAMEMODEWIDGET_H
#define GAMEMODEWIDGET_H

#include <QtWidgets>

#include "PlayerActivatedWidget.h"
#include "PlayerControlModeWidget.h"

class GameModeWidget : public QWidget
{
public:
	GameModeWidget(QWidget * parent = 0);
	~GameModeWidget();

	int currentPlayer()const;
	int currentMode()const;

protected:

private:
	PlayerActivatedWidget * m_player1Indicator,
		*m_player2Indicator;
	PlayerControlModeWidget * m_playerControlAngle, 
							* m_playerControlPower, 
							* m_playerControlFire;
public slots:
	void setCurrentMode(int gameMode);
	void setCurrentPlayer(int player);

};

#endif

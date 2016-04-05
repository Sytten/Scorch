#ifndef GAMEMODEWIDGET_H
#define GAMEMODEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>


#include "PlayerActivatedWidget.h"
#include "PlayerControlModeWidget.h"

#include "Game/Player.h"
#include "Game/State.h"

class GameModeWidget : public QWidget
{
public:
	GameModeWidget(QWidget * parent = 0);
	~GameModeWidget();

	Player currentPlayer()const;
	InputState currentMode()const;

protected:

private:
	PlayerActivatedWidget * m_player1Indicator,
		*m_player2Indicator;
	PlayerControlModeWidget * m_playerControlAngle, 
							* m_playerControlPower, 
							* m_playerControlFire;
public slots:
	void setCurrentMode(InputState gameMode);
	void setCurrentPlayer(Player player);
};

#endif

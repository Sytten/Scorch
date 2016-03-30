#ifndef GAMEMODEWIDGET_H
#define GAMEMODEWIDGET_H

#include <QtWidgets>

#include "PlayerActivatedWidget.h"

class GameModeWidget : public QWidget
{
public:
	GameModeWidget(QWidget * parent = 0);
	~GameModeWidget();

	void togglePlayer();
	int getCurrentPlayer()const;

protected:

private:
	QLabel * m_currentMode;
	PlayerActivatedWidget * m_player1Indicator,
		*m_player2Indicator;

};

#endif

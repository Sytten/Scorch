#pragma once

#include<iostream>

#include<QKeyEvent>
#include<QtWidgets>

#include<QCloseEvent>

#include "Information/FirePowerWidget.h"
#include "Information/AngleStatusWidget.h"
#include "Information/GameModeWidget.h"
#include "GameBottomLayout.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QMainWindow *parent = 0);
	~GameWindow();

protected:
	void keyPressEvent(QKeyEvent * KeyEvent);
	void keyReleaseEvent(QKeyEvent * KeyEvent);

	void closeEvent(QCloseEvent * CloseEvent);

private slots :

private:

	void setupUI();

	QLabel * m_mainGameWidget;

	GameModeWidget * m_gameModeWidget;
	AngleStatusWidget * m_currentAngle;
	FirePowerWidget * m_currentPower;

	QMenuBar * m_menuBar;
	QMenu * m_menuFile;
	QAction * m_actionQuit;
	QAction * m_actionNewGame;

	QStatusBar * m_statusBar;

	float temp_power;
	float temp_angle;

	bool temp_player1Turn;
};



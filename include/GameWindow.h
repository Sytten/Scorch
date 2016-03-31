#pragma once

#include<iostream>

#include <QKeyEvent>
#include <QtWidgets>
#include <QString>
#include <QCloseEvent>

#include "Input/FPGAReceiver.h"
#include "Information/FirePowerWidget.h"
#include "Information/AngleStatusWidget.h"
#include "Information/GameModeWidget.h"
#include "GameBottomLayout.h"
#include "Game/Game.h"

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QMainWindow *parent = 0);
	~GameWindow();

public slots:
	void displayStatusMessage(QString message);

protected:
    void keyPressEvent(QKeyEvent * KeyEvent);
    void customEvent(QEvent* event);

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

    FPGAReceiver m_fpga;
    Game m_game;

	float temp_power;
	float temp_angle;

	bool temp_player1Turn;
    bool temp_isPowerControlled;
};



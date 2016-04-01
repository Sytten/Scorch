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

	void playerChanged(Player p_player);
	void stateChanged(State p_state);
	void angleChanged(float p_angle);
	void powerChanged(float p_power);

signals:
	void changePlayer(Player p_player);
	void changeState(State p_state);
	void changeAngle(float p_angle);
	void changePower(float p_power);

protected:
    void keyPressEvent(QKeyEvent * KeyEvent);
    void customEvent(QEvent* event);

private:
    QLabel * m_mainGameWidget;

	QMenuBar * m_menuBar;
	QMenu * m_menuFile;
	QAction * m_actionQuit;
	QAction * m_actionNewGame;

    FPGAReceiver m_fpga;
    Game m_game;

	float temp_power;
	float temp_angle;

	bool temp_player1Turn;
    State temp_isPowerControlled;
};



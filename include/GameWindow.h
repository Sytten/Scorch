#pragma once

#include<iostream>

#include <QKeyEvent>
#include <QtWidgets>
#include <QString>
#include <QCloseEvent>
#include <QApplication>
#include <QMainWindow>

#include "SecondaryWindows.h"
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
    void resizeEvent(QResizeEvent *event);

protected slots:
	void playerChanged(Player p_player);
	void stateChanged(InputState p_state);
	void angleChanged(float p_angle);
	void powerChanged(float p_power);
	void pausedTriggered();

private:
    QLabel * m_mainGameWidget;

	QMenuBar * m_menuBar;
	QMenu * m_menuFichier;
	QMenu * m_menuJeux;
	QMenu * m_menuAide;
	QAction * m_actionQuit;
	QAction * m_actionNewGame;
	QAction * m_actionPause;
	QAction * m_actionMuet;
	QAction * m_actionTutoriel;
	QAction * m_actionVersion;

    FPGAReceiver m_fpga;
    Game m_game;
	
private slots:
	void openNewGame();
	void openTutoriel();
	void openVersion();

signals:
	void changePlayer(Player p_player);
	void changeState(InputState p_state);
	void changeAngle(float p_angle);
	void changePower(float p_power);
};



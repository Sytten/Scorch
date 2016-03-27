#pragma once

#include<iostream>

#include<QKeyEvent>
#include<QtWidgets>

#include<QCloseEvent>

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QMainWindow *parent = 0);
	~GameWindow();

protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

	void closeEvent(QCloseEvent * event);

private slots :

private:

	void setupUI();

	QLabel * m_mainGameWidget;
	QPushButton * m_newGameButton;
	QLabel * m_currentMode;
	QLabel * m_currentPlayerTurn;
	QLabel * m_currentAngle;
	QLabel * m_currentPower;

	QMenuBar * m_menuBar;
	QMenu * m_menuFile;

	QAction * m_actionQuit;
};



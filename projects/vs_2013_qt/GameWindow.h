#pragma once

#include<iostream>

#include<QMainWindow>

#include<QKeyEvent>

#include<QtWidgets>

class GameWindow : public QMainWindow
{
	Q_OBJECT

public:
	GameWindow(QWidget *parent = 0);
	~GameWindow();

protected:
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

	private slots:


private:
	QLabel * m_mainGameWidget;
	QPushButton * m_newGameButton;
	QLabel * m_currentMode;
	QLabel * m_currentPlayerTurn;
	QLabel * m_currentAngle;
	QLabel * m_currentPower;
};



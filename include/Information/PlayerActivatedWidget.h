/********
File: PlayerActivatedWidget.h
Authors: Émile Fugulin, Jean-Philippe Fournier, Philippe Spino, Julien Larochelle
Date: 06 avril 2016
Description: Costum widget to display a player
********/

#ifndef PLAYERACTIVATEDWIDGET_H
#define PLAYERACTIVATEDWIDGET_H

#include<QWidget>
#include<QPainter>
#include<QPen>

class PlayerActivatedWidget : public QWidget
{
public:
	PlayerActivatedWidget(int p_playerNumber = 1, bool p_isActivated = true , QWidget * parent = 0);
	~PlayerActivatedWidget();

	void setActivated(bool p_activated);
	bool activated()const;

protected:
	void paintEvent(QPaintEvent * paintEvent);

private:
	int m_playerNumber;
	bool m_isActivated;
};

#endif

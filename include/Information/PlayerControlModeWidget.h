#ifndef PLAYERCONTROLMODEWIDGET_H
#define PLAYERCONTROLMODEWIDGET_H

#include <QWidget>
#include <QPen>
#include <QPainter>

class PlayerControlModeWidget : public QWidget
{
public:
	PlayerControlModeWidget(int p_gameState = 1, bool p_isActivated = false, QWidget * parent = 0);
	~PlayerControlModeWidget();

	void setActivated(bool p_activated);
	bool activated()const;

protected:
	void paintEvent(QPaintEvent * paintEvent);

private:
	int m_gameState;
	bool m_isActivated;
};

#endif

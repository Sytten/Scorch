#ifndef PLAYERACTIVATEDWIDGET_H
#define PLAYERACTIVATEDWIDGET_H

#include <QtWidgets>

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

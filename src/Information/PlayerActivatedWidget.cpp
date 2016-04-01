#include "Information/PlayerActivatedWidget.h"

PlayerActivatedWidget::PlayerActivatedWidget(int p_playerNumber, bool p_isActivated, QWidget * parent) : QWidget(parent)
{
	m_playerNumber = p_playerNumber;
	m_isActivated = p_isActivated;
	setMinimumSize(QSize(50, 50));
	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

PlayerActivatedWidget::~PlayerActivatedWidget()
{

}

void PlayerActivatedWidget::paintEvent(QPaintEvent * paintEvent)
{
	Q_UNUSED(paintEvent);
	QPainter painter(this);

	QPen pen;
	pen.setBrush(Qt::black);
	pen.setWidth(4);

	QBrush brush;

	if (m_isActivated)brush = QBrush(Qt::black);
	else brush = QBrush(Qt::transparent);

	painter.setPen(pen);
	painter.setBrush(brush);

	//painter.drawRect(rect());
	painter.drawRoundedRect(rect(), 10.0, 10.0);

	QPainterPath path;
	path.addRoundedRect(rect(), 10.0, 10.0);
	painter.fillPath(path, brush);

	QFont font = painter.font();
	font.setPointSize(24);

	painter.setFont(font);

	if (m_isActivated)painter.setPen(Qt::white);
	else painter.setPen(Qt::black);

	painter.drawText(rect(), Qt::AlignCenter, QString::number(m_playerNumber));
}

void PlayerActivatedWidget::setActivated(bool p_activated)
{
	m_isActivated = p_activated;
	update();
}

bool PlayerActivatedWidget::activated()const
{
	return m_isActivated;
}

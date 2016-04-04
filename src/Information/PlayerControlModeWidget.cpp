#include "Information/PlayerControlModeWidget.h"

PlayerControlModeWidget::PlayerControlModeWidget(int p_gameState, bool p_isActivated, QWidget * parent) : QWidget(parent)
{
	m_gameState = p_gameState;
	m_isActivated = p_isActivated;
	setMinimumSize(QSize(100, 50));
	setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
}

PlayerControlModeWidget::~PlayerControlModeWidget()
{
}

void PlayerControlModeWidget::setActivated(bool p_activated)
{
	m_isActivated = p_activated;
	update();
}

bool PlayerControlModeWidget::activated()const
{
	return m_isActivated;
}

void PlayerControlModeWidget::paintEvent(QPaintEvent * paintEvent)
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

	if (m_isActivated)painter.setPen(Qt::red);
	else painter.setPen(Qt::black);

	if (m_gameState == 1)
		painter.drawText(rect(), Qt::AlignCenter, "Angle");
	else if (m_gameState == 2)
		painter.drawText(rect(), Qt::AlignCenter, "Puissance");
	else
		painter.drawText(rect(), Qt::AlignCenter, "Tir");

}

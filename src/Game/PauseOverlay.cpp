#include "Game/PauseOverlay.h"

void PauseOverlay::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

	painter->fillRect(rect(), QColor(100, 100, 100, 128));
	painter->setPen(QColor(0, 0, 0, 255));
	painter->setFont(QFont("arial,helvetica", 48));
	painter->drawText(rect(), "Pause", QTextOption(Qt::AlignCenter));
}

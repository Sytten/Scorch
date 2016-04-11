#include "Game/WinOverlay.h"

void WinOverlay::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	Q_UNUSED(option);
	Q_UNUSED(widget);

    painter->fillRect(rect(), QColor(0, 0, 0, 150));

    QPen pen(QColor(Qt::red), 15);
    painter->setPen(pen);

    QFont font = painter->font();
    font.setPointSize(72);
    font.setBold(true);
    painter->setFont(font);

    painter->drawText(rect(), "VICTOIRE!\n" + m_winner, QTextOption(Qt::AlignCenter));
}

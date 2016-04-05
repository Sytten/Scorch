#include "Game/GameOverlay.h"

QRectF GameOverlay::boundingRect() const
{
    return QRectF(pos().x()-m_outlineWidth/2, pos().y() -5 - m_outlineWidth/2, 960 + m_outlineWidth, 60 + m_outlineWidth);
}

void GameOverlay::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(QRect(pos().x(), pos().y(), 450, 50),10,10);
    path.addRoundedRect(QRect(pos().x()+510, pos().y(), 450, 50),10,10);

    QPen pen(QColor(188, 198, 204), 5);
    m_outlineWidth = pen.widthF();
    painter->setPen(pen);
    painter->fillPath(path, Qt::yellow);
    painter->drawPath(path);

    path = QPainterPath();
    path.addRoundedRect(QRect(pos().x()+pen.width()/2, pos().y()+pen.width()/2, 450 * (100-m_player1Life)/100, 50-pen.width()),10,10);
    path.addRoundedRect(QRect(pos().x()+960-450 * (100-m_player2Life)/100-pen.width()/2, pos().y()+pen.width()/2, 450 * (100-m_player2Life)/100, 50-pen.width()),10,10);
    painter->fillPath(path, Qt::red);


    path = QPainterPath();
    pen.setColor(Qt::white);
    painter->setPen(pen);
    path.addRoundedRect(QRect(pos().x()+445, pos().y()-5, 70, 60), 10, 10);
    painter->fillPath(path, Qt::black);
    painter->drawPath(path);

    if(m_player1Life == 0 || m_player2Life == 0)
        pen.setColor(Qt::red);
    else
        pen.setColor(Qt::yellow);
    painter->setPen(pen);
    QFont font = painter->font();
    font.setPointSize(24);
    painter->setFont(font);
    path = QPainterPath();

    QPoint spacing;
    spacing.setY((60 - painter->fontMetrics().height())/2);
    spacing.setX((70 - painter->fontMetrics().width("KO"))/2);
    path.addText(pos().x() + 445 + spacing.x(), pos().y() + 45 - spacing.y(), painter->font(),"KO");
    painter->drawPath(path);
}

void GameOverlay::newPlayerLife(Player player, int life)
{
	if (player == Player1)
		m_player1Life = life;
	else if (player == Player2)
		m_player2Life = life;

    update(boundingRect());
}

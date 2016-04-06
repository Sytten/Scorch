#include "Game/Animation.h"

Animation::Animation(const QPixmap &spriteSheet, int numberOfFrame, int spriteWidth, int spriteHeight, QGraphicsItem *parent)
    : QGraphicsPixmapItem(spriteSheet, parent), m_numberOfFrame(numberOfFrame), m_currentFrame(0), m_spriteWidth(spriteWidth), m_spriteHeight(spriteHeight), m_currentSpriteRect(0,0,spriteWidth,spriteHeight)
{
}

void Animation::advance(int phase)
{
    if(phase == 0 && !done()) {
        m_currentFrame++;

        m_currentSpriteRect.translate(m_spriteWidth, 0);

        if(m_currentSpriteRect.x() >= pixmap().width()) {
            m_currentSpriteRect.setX(0);
            m_currentSpriteRect.setWidth(m_spriteWidth);
            m_currentSpriteRect.translate(0, m_spriteHeight);
        }
        update(boundingRect());
    }
}

void Animation::setPos(const QPointF &pos)
{
    QGraphicsPixmapItem::setPos(pos.x()-m_spriteWidth/2, pos.y()-m_spriteHeight/2);
}

void Animation::setPos(qreal x, qreal y)
{
    Animation::setPos(QPointF(x, y));
}

void Animation::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QPointF(0, 0), pixmap(), m_currentSpriteRect);
}

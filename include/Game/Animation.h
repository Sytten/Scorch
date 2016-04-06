#ifndef ANIMATION_H
#define ANIMATION_H

#include <QGraphicsPixmapItem>
#include <QPainter>

class Animation : public QGraphicsPixmapItem
{
public:
    Animation(const QPixmap& spriteSheet, int numberOfFrame, int spriteWidth, int spriteHeight, QGraphicsItem* parent = 0);

    virtual void advance(int phase);

    virtual void setPos(const QPointF& pos);
    virtual void setPos(qreal x, qreal y);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);

    bool done() { return m_currentFrame == m_numberOfFrame; }

private:
    int m_numberOfFrame;
    int m_currentFrame;
    int m_spriteWidth;
    int m_spriteHeight;

    QRect m_currentSpriteRect;
};

#endif // ANIMATION_H

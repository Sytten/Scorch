#ifndef IA_H
#define IA_H

#include <QApplication>
#include <QObject>
#include <QPointer>
#include <QPointF>
#include <QRectF>
#include <cmath>

#include "Game/Player.h"
#include "Game/State.h"
#include "Input/FPGAEvent.h"

class IA : public QObject
{
    Q_OBJECT

public:
    IA(Player controllingPlayer, Difficulty difficulty, QRectF target, QPointF startingPoint, QPointer<QObject> receiver, QObject* parent = 0);

    void setTarget(QRect target);
    void update();

public slots:
    void newAngle(double angle);
    void newPower(double power);
    void newPlayer(Player player);
    void newInputState(InputState state);

private:
    void calculateNewTargetParameters();
    bool closeEnough(double target, double value, double range);

    QPointer<QObject> m_receiver;

    Difficulty m_difficulty;

    Player m_controllingPlayer;
    QPointF m_startingPoint;
    bool m_update;

    QRectF m_target;
    double m_targetAngle;
    double m_currentAngle;
    double m_targetPower;
    double m_currentPower;

    double m_gravity;

    InputState m_currentInputState;
};

#endif // IA_H

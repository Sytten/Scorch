#include "Game/IA.h"

IA::IA(Player controllingPlayer, Difficulty difficulty, QRectF target, QPointF startingPoint, QPointer<QObject> receiver, QObject *parent)
    : QObject(parent), m_receiver(receiver), m_difficulty(difficulty), m_controllingPlayer(controllingPlayer), m_startingPoint(startingPoint), m_update(false), m_target(target), m_currentAngle(0), m_currentPower(50), m_gravity(9.8), m_currentInputState(Angle)
{
}

void IA::setTarget(QRect target)
{
    m_target = target;
}

void IA::update()
{
    if (m_update) {
        if (!closeEnough(m_targetAngle, m_currentAngle, 1)) {
            if(m_currentInputState != Angle)
                QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
            else {
                if(m_currentAngle < m_targetAngle)
                    QCoreApplication::postEvent(m_receiver, new FPGAEvent(Increase));
                else
                    QCoreApplication::postEvent(m_receiver, new FPGAEvent(Decrease));
            }
        }
        else if (!closeEnough(m_targetPower, m_currentPower, 1)) {
            if(m_currentInputState != Power)
                QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
            else {
                if(m_currentPower < m_targetPower)
                    QCoreApplication::postEvent(m_receiver, new FPGAEvent(Increase));
                else
                    QCoreApplication::postEvent(m_receiver, new FPGAEvent(Decrease));
            }
        }
        else {
            if(m_currentInputState != Fire)
                QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
            else
                QCoreApplication::postEvent(m_receiver, new FPGAEvent(Increase));
        }
    }
}

void IA::newAngle(double angle)
{
    m_currentAngle = angle;
}

void IA::newPower(double power)
{
    m_currentPower = power;
}

void IA::newPlayer(Player player)
{
    if(player == m_controllingPlayer) {
        m_update = true;
        calculateNewTargetParameters();
    }
    else
        m_update = false;
}

void IA::newInputState(InputState state)
{
    m_currentInputState = state;
}

void IA::calculateNewTargetParameters()
{
    bool found = false;
    int i = 0;

    while(!found) {
        m_targetPower = rand() % 20 + 70;

        QPointF target(m_target.center().x(),m_target.top()+50);

        double x = m_startingPoint.x() - target.x();
        double y = m_startingPoint.y() - target.y();

        long double rootTerm = pow((2*m_targetPower), 4) - m_gravity*(m_gravity*pow(x,2) + 2*y*pow((2*m_targetPower),2));

        if(rootTerm < 0) {
            i++;
            if(i > 100) {
                found = true;
                m_targetAngle = rand() % 20 + 10;
            }
        } else {
            found = true;
            double first = (pow((2*m_targetPower),2) + sqrt(rootTerm))/(m_gravity*x);
            double second = (pow((2*m_targetPower),2) - sqrt(rootTerm))/(m_gravity*x);
            double theta_first = atan(first) *180.0 /3.1416;
            double theta_second = atan(second) *180.0 /3.1416;

            if(theta_first < theta_second)
                m_targetAngle = theta_first;
            else
                m_targetAngle = theta_second;

            if(m_difficulty == Easy)
                 m_targetAngle += rand() % 40 -20;
            else if(m_difficulty == Intermediate)
                 m_targetAngle += rand() % 20 -10;
            else if(m_difficulty == Hard)
                 m_targetAngle += rand() % 10 -5;
        }
    }
}

bool IA::closeEnough(double target, double value, double range)
{
    if(qAbs(target - value) < range)
        return true;
    return false;
}

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

    while(!found) {
        m_targetPower = rand() % 20 + 70;

        QPoint target(m_target.center().x(),m_target.top()-50);

        double alpha = m_startingPoint.x() - target.x();
        double beta = m_startingPoint.y() - target.y();
        double eff = 2 * (2*m_targetPower) * (2*m_targetPower) / m_gravity;
        double rootTerm = eff*(eff - 2*beta) - 2*alpha*alpha;

        if(rootTerm < 0) {
            //impossible
        } else {
            found = true;
            double gamma_first = (eff + sqrt(rootTerm))/2;
            double gamma_second = (eff - sqrt(rootTerm))/2;
            double theta_first = atan2(gamma_first, alpha) *180.0 /3.1416;
            double theta_second = atan2(gamma_second, alpha) *180.0 /3.1416;
            if(rand()%2)
                m_targetAngle = theta_first;
            else
                m_targetAngle = theta_second;
        }
    }
}

bool IA::closeEnough(double target, double value, double range)
{
    if(qAbs(target - value) < range)
        return true;
    return false;
}

#include "Input/FPGAReceiver.h"

FPGAReceiver::FPGAReceiver(QObject * parent) : QObject(parent)
{
	m_updateTimer.setInterval(8);
    connect(&m_updateTimer, &QTimer::timeout, this, &FPGAReceiver::updateFPGA);
	m_updateTimer.start();
}

FPGAReceiver::~FPGAReceiver()
{

}

void FPGAReceiver::updateFPGA()
{

}

void FPGAReceiver::handlePressEvent(QKeyEvent *KeyEvent)
{
    if (KeyEvent->isAutoRepeat())
        return;
    switch (KeyEvent->key()){
    case Qt::Key_Right:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Increase));
        break;
    case Qt::Key_Left:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Decrease));
        break;
    case Qt::Key_Up:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Change));
        break;
    case Qt::Key_Down:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Change));
        break;
    default:
        break;
    }
}

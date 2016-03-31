#include "Input/FPGAReceiver.h"

FPGAReceiver::FPGAReceiver(QObject * parent) : QObject(parent), m_indexRead(-1), m_lastCommandSent(None)
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
	if (!m_fpga.estOk()) {
		emit fpgaError(QString::fromUtf8(m_fpga.messageErreur()));
		return;
	}

	if (!m_fpga.lireRegistre(0, m_indexRead)) {
		emit fpgaError(QString::fromUtf8(m_fpga.messageErreur()));
		m_indexRead = -1;
		return;
	} else {
		switch (m_indexRead)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			break;
		}
	}
}

void FPGAReceiver::handlePressEvent(QKeyEvent *KeyEvent)
{
    
    switch (KeyEvent->key()){
    case Qt::Key_Right:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Increase));
        break;
    case Qt::Key_Left:
        QCoreApplication::postEvent(parent(), new FPGAEvent(Decrease));
        break;
    case Qt::Key_Up:
		if (KeyEvent->isAutoRepeat())
			return;
        QCoreApplication::postEvent(parent(), new FPGAEvent(Change));
        break;
    case Qt::Key_Down:
		if (KeyEvent->isAutoRepeat())
			return;
        QCoreApplication::postEvent(parent(), new FPGAEvent(Change));
        break;
    default:
        break;
    }
}

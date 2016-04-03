#include "Input/FPGAReceiver.h"

FPGAReceiver::FPGAReceiver(QObject * receiver, QObject * parent) : QObject(parent), m_indexRead(-1), m_lastCommandSent(None), m_receiver(receiver)
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
#ifdef Q_OS_WIN
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
			m_lastCommandSent = Increase;
			QCoreApplication::postEvent(m_receiver, new FPGAEvent(Increase));
			break;
		case 2:
			if(m_lastCommandSent != Change)
			{
				m_lastCommandSent = Change;
				QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
			}
			break;
		case 3:
			m_lastCommandSent = Decrease;
			QCoreApplication::postEvent(m_receiver, new FPGAEvent(Decrease));
			break;
		default:
			break;
		}
	}
#endif
}

void FPGAReceiver::handlePressEvent(QKeyEvent *KeyEvent)
{
    
    switch (KeyEvent->key()){
    case Qt::Key_Right:
        QCoreApplication::postEvent(m_receiver, new FPGAEvent(Increase));
        break;
    case Qt::Key_Left:
        QCoreApplication::postEvent(m_receiver, new FPGAEvent(Decrease));
        break;
    case Qt::Key_Up:
		if (KeyEvent->isAutoRepeat())
			return;
        QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
        break;
    case Qt::Key_Down:
		if (KeyEvent->isAutoRepeat())
			return;
        QCoreApplication::postEvent(m_receiver, new FPGAEvent(Change));
        break;
    default:
        break;
    }
}

#include "QtFPGAReceiver.h"

QtFPGAReceiver::QtFPGAReceiver(QObject * parent) : QObject(parent)
{
	m_updateTimer.setInterval(8);
	connect(&m_updateTimer, &QTimer::timeout, this, &QtFPGAReceiver::updateFPGA);
	m_updateTimer.start();
}

QtFPGAReceiver::~QtFPGAReceiver()
{

}

void QtFPGAReceiver::updateFPGA()
{

}
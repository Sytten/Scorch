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

#ifndef FPGARECEIVER_H
#define FPGARECEIVER_H

#include <QtCore>
#include <QTimer>
#include <QKeyEvent>
#include <QString>

#ifdef Q_OS_WIN
#include "CommunicationFPGA.h"
#endif
#include "Input/FPGAEvent.h"

class FPGAReceiver : public QObject
{
    Q_OBJECT

public:
    FPGAReceiver(QObject * receiver, QObject * parent = 0);
    ~FPGAReceiver();

    void handlePressEvent(QKeyEvent * KeyEvent);

private:
	QTimer m_updateTimer;
#ifdef Q_OS_WIN
	CommunicationFPGA m_fpga;
#endif
	int m_indexRead;
	Command m_lastCommandSent;
	QObject* m_receiver;

private slots:
	void updateFPGA();

signals:
	void fpgaError(QString message);
};

#endif

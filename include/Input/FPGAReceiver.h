#ifndef FPGARECEIVER_H
#define FPGARECEIVER_H

#include <QtCore>
#include <QTimer>
#include <QKeyEvent>
#include <QString>

#include "CommunicationFPGA.h"
#include "Input/FPGAEvent.h"

class FPGAReceiver : public QObject
{
    Q_OBJECT

public:
    FPGAReceiver(QObject * parent = 0);
    ~FPGAReceiver();

    void handlePressEvent(QKeyEvent * KeyEvent);

private slots:
	void updateFPGA();

signals:
    void newCommand(Command command);
	void fpgaError(QString message);

private:
	QTimer m_updateTimer;
	CommunicationFPGA m_fpga;
	int m_indexRead;
	Command m_lastCommandSent;
};

#endif

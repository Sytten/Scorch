#ifndef FPGARECEIVER_H
#define FPGARECEIVER_H

#include <QtCore>
#include <QTimer>
#include <QKeyEvent>

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
    void newCommand(Command p_command);

private:
	QTimer m_updateTimer;
};

#endif

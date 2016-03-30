#ifndef FPGARECEIVER_H
#define FPGARECEIVER_H

#include <QtCore>
#include <QTimer>

class FPGAReceiver : public QObject
{
    Q_OBJECT

public:
    FPGAReceiver(QObject * parent = 0);
    ~FPGAReceiver();

private slots:
	void updateFPGA();

protected:

private:
	QTimer m_updateTimer;
};

#endif

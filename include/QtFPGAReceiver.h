
#include <QtCore>
#include <QTimer>

class QtFPGAReceiver : public QObject
{
	Q_OBJECT

public:
	QtFPGAReceiver(QObject * parent = 0);
	~QtFPGAReceiver();

private slots:
	void updateFPGA();

protected:

private:
	QTimer m_updateTimer;
};

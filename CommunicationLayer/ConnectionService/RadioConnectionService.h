#pragma once

#include "I_ConnectionService.h"
#include <QObject>
#include <QSerialPort>
#include <QString>

class RadioConnectionService : public I_ConnectionService
{
	Q_OBJECT
public:
	RadioConnectionService(QSerialPort& serialPort_);
	~RadioConnectionService();

public slots:
	void connectDataSource(QString serialPortName, int baudRate);
	void disconnectDataSource();

private:
	QString failed();
	QSerialPort& serialPort_;
};

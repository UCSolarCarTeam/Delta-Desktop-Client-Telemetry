#ifndef I_SERIALPORTCONNECTIONSERVICE_H
#define I_SERIALPORTCONNECTIONSERVICE_H

#include "I_ConnectionService.h"
#include <QObject>
#include <QSerialPort>
#include <QString>

class I_SerialPortConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   I_SerialPortConnectionService(QString portName, int baudrate);

public slots:
   void connectDataSource();
   bool checkStatus();

private:
   QSerialPort serialPort_ = new QSerialPort();

};

#endif // I_SERIALPORTCONNECTIONSERVICE_H

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
   I_SerialPortConnectionService();
   I_SerialPortConnectionService(QString portName, int baudrate);
   char* failed();
   void succeeded();
   void setStatus(char*);

public slots:
   void connectDataSource();
   QString checkStatus();

private:
   QSerialPort serialPort_ = new QSerialPort();
   QString status_ = QString();

};

#endif // I_SERIALPORTCONNECTIONSERVICE_H

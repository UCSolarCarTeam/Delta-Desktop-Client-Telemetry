#pragma once

#include "I_ConnectionService.h"
#include <QObject>
#include <QSerialPort>
#include <QString>
#include <QTimer>

class SerialPortConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   SerialPortConnectionService();
   SerialPortConnectionService(QString portName, int baudrate);
   QString checkStatus();
   bool communicateWithPort(QString message,
                            QString expectedResponse,
                            int maxWaitTime); //in milliseconds

public slots:
   void connectDataSource();
   void disconnectDataSource();

private:
   void setStatus(QString);
   QString failed();
   void succeeded();
   QTimer responseTimer_;
   QSerialPort serialPort_;
   bool connected_ = false;

};


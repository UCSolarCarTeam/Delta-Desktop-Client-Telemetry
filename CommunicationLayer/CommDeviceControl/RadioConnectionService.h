#pragma once

#include "I_ConnectionService.h"
#include <QSerialPort>
#include <QString>

class RadioConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   RadioConnectionService(QSerialPort& serialPort);
   virtual ~RadioConnectionService();

   void setSerialParameters(QString serialPortName, int baudRate);
   bool connectToDataSource();
   void disconnectFromDataSource();

private:
   QSerialPort& serialPort_;
};

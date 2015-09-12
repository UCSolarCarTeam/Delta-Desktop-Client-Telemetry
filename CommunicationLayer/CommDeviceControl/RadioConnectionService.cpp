#include "RadioConnectionService.h"

RadioConnectionService::RadioConnectionService(QSerialPort& serialPort)
: serialPort_(serialPort)
{
}

RadioConnectionService::~RadioConnectionService()
{
   disconnectFromDataSource();
}

void RadioConnectionService::setSerialParameters(QString serialPortName, int baudRate)
{
   serialPort_.setPortName(serialPortName);
   serialPort_.setBaudRate(baudRate);
}

bool RadioConnectionService::connectToDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite))
   {
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(serialPort_.errorString());
      return false;
   }
}

void RadioConnectionService::disconnectFromDataSource()
{
   serialPort_.close();
   emit connectionFailed("DISCONNECTED");
}

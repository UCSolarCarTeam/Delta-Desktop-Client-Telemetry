#include "RadioConnectionService.h"

RadioConnectionService::RadioConnectionService(QSerialPort& serialPort)
: serialPort_(serialPort)
{
}

RadioConnectionService::~RadioConnectionService()
{
	disconnectDataSource();
}

void RadioConnectionService::connectDataSource(QString portName, int baudRate)
{
   if (!portName.isEmpty()){
      serialPort_.setPortName(portName);
   }
   serialPort_.setBaudRate(baudRate);
   if (serialPort_.open(QIODevice::ReadWrite) == 0){
      emit connectionFailed(failed());
      return;
   }
   emit sendDebugMessage("Port name set to " + portName +
                         " with baudrate of " + QString::number(baudRate));

   emit sendDebugMessage("Connected");
   emit connectionSucceeded("CONNECTED");
}

void RadioConnectionService::disconnectDataSource()
{
   disconnect(&serialPort_, 0, this, 0);

   serialPort_.close();
   emit sendDebugMessage("Disconnected");
   emit connectionFailed("DISCONNECTED");
}

QString RadioConnectionService::failed()
{
   //Cases notated in ct.org/doc/qt-5/qserialport.html#SerialPortError-enum
   switch (serialPort_.error())
   {
      case 0:
         return "No serialport error, code logic problem";
      case 1:
         return "No device found!";
      case 2:
         return "Permission error, port open in another process?";
      case 3:
         return "Port open already!";
      case 4:
         return "Parity error";
      case 5:
         return "Framing error";
      case 6:
         return "Break condition detected by hardware on input line";
      case 7:
         return "I/O error while writing data";
      case 8:
         return "I/O error while reading data";
      case 9:
         return "Device unavailable";
      case 10:
         return "Requested operation unsupported/prohibited";
      case 11:
         return "Unidentified error";
      case 12:
         return "Timeout error";
      case 13:
         return "Port not open";
   }
   return "Check SerialPortConnectionService class";
}
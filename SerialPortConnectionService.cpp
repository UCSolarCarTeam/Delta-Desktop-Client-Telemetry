#include "SerialPortConnectionService.h"

namespace
{
   const char* CAR_PORT_ADDRESS = 000;
}

SerialPortConnectionService::SerialPortConnectionService(QString portName, int baudrate)
{
   serialPort_.setBaudRate(baudrate);
   serialPort_.setPortName(portName);
   connected_ = false;
}

SerialPortConnectionService::~SerialPortConnectionService()
{
   disconnectDataSource();
}

void  SerialPortConnectionService::connectDataSource()
{
   if (serialPort_.open(QIODevice::ReadWrite) == 0){
      connected_ = false;
      emit connectionFailed(failed());
      return;
   }

   //talk to port code
}

/*
bool SerialPortConnectionService::communicateWithPort(QString message,
                                                      QString expectedResponse,
                                                      int maxWaitTime)
{
   QByteArray response;

   if (serialPort_.write(qPrintable(message)) == -1){
      setStatus(failed());
      return false;
   }
   if (serialPort_.waitForReadyRead(maxWaitTime)){
      if (serialPort_.canReadLine()){
         response = serialPort_.readLine();
         if (QString(response) == expectedResponse){
            return true;
         }
         else{
            setStatus("Did not receive " + expectedResponse + " after " + message);
            return false;
         }
      }
   }
   else {
      setStatus("Timeout for " + expectedResponse);
      return false;
   }

}
*/


void SerialPortConnectionService::disconnectDataSource()
{
   serialPort_.close();
   connected_ = false;
}

QString SerialPortConnectionService::failed()
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

   return "check SerialPortConnectionService class";
}

void SerialPortConnectionService::succeeded()
{
   connected_ = false;
}

bool SerialPortConnectionService::isConnected()
{
   return connected_;
}

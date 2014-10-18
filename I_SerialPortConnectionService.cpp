#include "I_SerialPortConnectionService.h"

I_SerialPortConnectionService::I_SerialPortConnectionService(QString portName, int baudrate)
{
   serialPort_.setBaudRate(baudrate);
   serialPort_.setPortName(portName);
}

void  I_SerialPortConnectionService::connectDataSource()
{

}

QString I_SerialPortConnectionService::checkStatus()
{
   return status_;
}

void I_SerialPortConnectionService::setStatus(char* status)
{
   status_.clear();
   status_.append(status);
}

QString I_SerialPortConnectionService::failed()
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

   return "check I_SerialPortConnectionService class";
}

void I_SerialPortConnectionService::succeeded()
{
   setStatus("Connected");
}

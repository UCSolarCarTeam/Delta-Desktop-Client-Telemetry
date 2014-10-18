#include "I_SerialPortConnectionService.h"

I_SerialPortConnectionService::I_SerialPortConnectionService(QString portName, int baudrate)
{
   serialPort_.setBaudRate(baudrate);
   serialPort_.setPortName(portName);
}

void  I_SerialPortConnectionService::connectDataSource()
{

}

bool I_SerialPortConnectionService::checkStatus()
{

}

void I_SerialPortConnectionService::failed(QString failureReason)
{

}

void I_SerialPortConnectionService::succeeded()
{

}

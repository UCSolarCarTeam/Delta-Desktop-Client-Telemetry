#include "SerialPortConnectionService.h"
#include <QDebug>

namespace
{
   const int READING_FREQUENCY = 500;
   const QByteArray CAR_PORT_ADDRESS = "00:07:80:6e:f7:e4";
   const QByteArray FIRST_COMMAND = "AT";
   const QByteArray FIRST_RESPONSE = "OK\r";
   const int FIRST_RESPONSE_MAXTIME = 2000;
   const QByteArray SECOND_COMMAND = "PAIR " + CAR_PORT_ADDRESS;
   const QByteArray SECOND_RESPONSE = "PAIR " + CAR_PORT_ADDRESS + " OK\r";
   const int SECOND_RESPONSE_MAXTIME = 10000;
   const QByteArray THIRD_COMMAND = "CALL " + CAR_PORT_ADDRESS + " 1101 RFCOMM";
   const QByteArray THIRD_RESPONSE = "CALL 0\r";
   const int THIRD_RESPONSE_MAXTIME = 10000;
}

SerialPortConnectionService::SerialPortConnectionService(QString portName,
                                                         int baudRate,
                                                         QSerialPort& serialPort)
: serialPort_(serialPort)
{
   serialPort_.setBaudRate(baudRate);
   serialPort_.setPortName(portName);
   sendDebugMessage("Port " + portName +" created with baudrate of " + baudRate);
}

SerialPortConnectionService::~SerialPortConnectionService()
{
   disconnectDataSource();
}

void  SerialPortConnectionService::connectDataSource(QString portName, int baudRate)
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

   setUpBlueGigaWT41Connection();
}

void SerialPortConnectionService::disconnectDataSource()
{
   disconnect(&serialPort_, 0, this, 0);
   disconnect(&responseTimer_, 0, this, 0);
   disconnect(&readingTimer_, 0, this, 0);

   serialPort_.close();
   emit sendDebugMessage("Disconnected");
   emit connectionFailed("Disconnected");
}

//For use only with the BlueGiga WT41 bluetooth chip
//This code was written for the Schulich Delta
void SerialPortConnectionService::setUpBlueGigaWT41Connection()
{
   emit sendDebugMessage("Beginning connection setup with BlueGigaWT41");
   serialPort_.write(FIRST_COMMAND + "\n");
   emit sendDebugMessage("Wrote to port:\n" + FIRST_COMMAND + "\n");
   responseTimer_.start(FIRST_RESPONSE_MAXTIME);
   firstStep();
   connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(firstStep()));
   connect(&responseTimer_, SIGNAL(timeout()), this, SLOT(responseTimedOut()));
}

void SerialPortConnectionService::firstStep()
{
   readingTimer_.start(READING_FREQUENCY);

   QByteArray receivedResponse = serialPort_.readLine();
   if (receivedResponse.contains(FIRST_RESPONSE)){
      serialPort_.write(SECOND_COMMAND + "\n");
      responseTimer_.start(SECOND_RESPONSE_MAXTIME);

      emit sendDebugMessage("Successfully received:\n" + receivedResponse);
      emit sendDebugMessage("Wrote to port:\n" + SECOND_COMMAND + "\n");

      disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(firstStep()));
      connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(secondStep()));
      secondStep();
      return;
   }
   sendDebugMessage("Received:\n" + receivedResponse);
   return;
}

void SerialPortConnectionService::secondStep()
{
   readingTimer_.start(READING_FREQUENCY);

   QByteArray receivedResponse = serialPort_.readLine();
   if (receivedResponse.contains(SECOND_RESPONSE)){
      serialPort_.write(THIRD_COMMAND + "\n");
      responseTimer_.start(THIRD_RESPONSE_MAXTIME);

      emit sendDebugMessage("Successfully received:\n" + receivedResponse);
      emit sendDebugMessage("Wrote to port:\n" + THIRD_COMMAND + "\n");

      disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(secondStep()));
      connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(thirdStep()));
      thirdStep();
      return;
   }
   sendDebugMessage("Received:\n" + receivedResponse);
   return;
}

void SerialPortConnectionService::thirdStep()
{
   readingTimer_.start(READING_FREQUENCY);

   QByteArray receivedResponse = serialPort_.readLine();
   if (receivedResponse.contains(THIRD_RESPONSE)){
      emit sendDebugMessage("Successfully received:\n" + receivedResponse);

      disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(thirdStep()));
      fourthStep();
      return;
   }
   sendDebugMessage("Received:\n" + receivedResponse);
   return;
}

void SerialPortConnectionService::fourthStep()
{
   emit sendDebugMessage("Connected");
   emit connectionSucceeded("Connected");

   disconnect(&serialPort_, 0, this, 0);
   disconnect(&responseTimer_, 0, this, 0);
   disconnect(&readingTimer_, 0, this, 0);

   responseTimer_.stop();
   readingTimer_.stop();
}

void SerialPortConnectionService::responseTimedOut()
{
   emit sendDebugMessage("Response timed out");
   emit connectionFailed("Response timed out");
   disconnect(&serialPort_, 0, this, 0);
   disconnect(&responseTimer_, 0, this, 0);
   disconnectDataSource();
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
   return "Check SerialPortConnectionService class";
}

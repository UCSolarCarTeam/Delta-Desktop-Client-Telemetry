#include "SerialPortConnectionService.h"
#include <QDebug>

namespace
{
   const int READING_FREQUENCY = 500;
   const QByteArray CAR_PORT_ADDRESS = "00:07:80:6E:F7:E4";
   const QByteArray FIRST_COMMAND = "AT\n";
   const QByteArray FIRST_RESPONSE = "OK\r\n";
   const int FIRST_RESPONSE_MAXTIME = 1000;
   const QByteArray SECOND_COMMAND = "PAIR " + CAR_PORT_ADDRESS + "\n";
   const QByteArray SECOND_RESPONSE = "PAIR " + CAR_PORT_ADDRESS + " OK\n";
   const int SECOND_RESPONSE_MAXTIME = 10000;
   const QByteArray THIRD_COMMAND = "CALL " + CAR_PORT_ADDRESS + " 1101 RFCOMM\n";
   const QByteArray THIRD_RESPONSE = "CALL 0\n";
   const int THIRD_RESPONSE_MAXTIME = 10000;
}

SerialPortConnectionService::SerialPortConnectionService(QString portName, int baudRate)
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
   if(!portName.isEmpty()){
      serialPort_.setPortName(portName);
   }
   serialPort_.setBaudRate(baudRate);
   if (serialPort_.open(QIODevice::ReadWrite) == 0){
      emit connectionFailed(failed());
      return;
   }
   emit sendDebugMessage("Port name set to " + portName + " with baudrate of " + baudRate);
   //Bluetooth Connection
   setUpBlueGigaWT41Connection();
}

//For use only with the BlueGiga WT41 bluetooth chip
//This code was written for the Schulich Delta
void SerialPortConnectionService::setUpBlueGigaWT41Connection()
{
   emit sendDebugMessage("Beginning connection setup with BlueGigaWT41");
   serialPort_.write(FIRST_COMMAND);
   responseTimer_.start(FIRST_RESPONSE_MAXTIME);
   firstStep();
   connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(firstStep()));
   connect(&responseTimer_, SIGNAL(timeout()), this, SLOT(responseTimedOut()));
}

void SerialPortConnectionService::firstStep()
{
   readingTimer_.start(READING_FREQUENCY);
   if (serialPort_.canReadLine())
   {
      QByteArray receivedResponse = serialPort_.readLine();
      if (receivedResponse == FIRST_RESPONSE){
         serialPort_.write(SECOND_COMMAND);
         responseTimer_.start(SECOND_RESPONSE_MAXTIME);

         emit sendDebugMessage("Successfully received " + receivedResponse);
         emit sendDebugMessage("Wrote " + SECOND_COMMAND + " to port");

         disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(firstStep()));
         connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(secondStep()));
         secondStep();
      }
      sendDebugMessage("Received " + receivedResponse);
      return;
   }
   else
   {
      disconnect(&serialPort_, 0, this, 0);
      disconnect(&readingTimer_, 0, this, 0);
      disconnect(&responseTimer_, 0, this, 0);

      readingTimer_.stop();
      responseTimer_.stop();

      sendDebugMessage("Could not read line");
      connectionFailed("Could not read line");
      disconnectDataSource();
   }
}


void SerialPortConnectionService::secondStep()
{
   readingTimer_.start(READING_FREQUENCY);
   if (serialPort_.canReadLine())
   {
      QByteArray receivedResponse = serialPort_.readLine();
      if (receivedResponse == SECOND_RESPONSE){
         serialPort_.write(THIRD_COMMAND);
         responseTimer_.start(THIRD_RESPONSE_MAXTIME);

         emit sendDebugMessage("Successfully received " + receivedResponse);
         emit sendDebugMessage("Wrote " + THIRD_COMMAND + " to port");

         disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(secondStep()));
         connect(&readingTimer_, SIGNAL(timeout()), this, SLOT(thirdStep()));
         thirdStep();
      }
      sendDebugMessage("Received " + receivedResponse);
      return;
   }
   else
   {
      disconnect(&serialPort_, 0, this, 0);
      disconnect(&readingTimer_, 0, this, 0);
      disconnect(&responseTimer_, 0, this, 0);

      readingTimer_.stop();
      responseTimer_.stop();

      sendDebugMessage("Could not read line");
      connectionFailed("Could not read line");
      disconnectDataSource();
   }
}

void SerialPortConnectionService::thirdStep()
{
   readingTimer_.start(READING_FREQUENCY);
   if (serialPort_.canReadLine())
   {
      QByteArray receivedResponse = serialPort_.readLine();
      if (receivedResponse == THIRD_RESPONSE){
         emit sendDebugMessage("Successfully received " + receivedResponse);

         disconnect(&readingTimer_, SIGNAL(timeout()), this, SLOT(secondStep()));
         fourthStep();
      }
      sendDebugMessage("Received " + receivedResponse);
      return;
   }
   else
   {
      disconnect(&serialPort_, 0, this, 0);
      disconnect(&readingTimer_, 0, this, 0);
      disconnect(&responseTimer_, 0, this, 0);

      readingTimer_.stop();
      responseTimer_.stop();

      sendDebugMessage("Could not read line");
      connectionFailed("Could not read line");
      disconnectDataSource();
   }
}

void SerialPortConnectionService::fourthStep()
{
   if (serialPort_.canReadLine())
   {
      emit connectionSucceeded("Connected");

      disconnect(&serialPort_, 0, this, 0);
      responseTimer_.stop();
      disconnect(&responseTimer_, 0, this, 0);
   }


}

void SerialPortConnectionService::responseTimedOut()
{
   emit connectionFailed("Response timed out");
   disconnect(&serialPort_, 0, this, 0);
   disconnect(&responseTimer_, 0, this, 0);
   disconnectDataSource();
}


void SerialPortConnectionService::disconnectDataSource()
{
   serialPort_.close();
   emit sendDebugMessage("Disconnected");
   emit connectionFailed("Disconnected");
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

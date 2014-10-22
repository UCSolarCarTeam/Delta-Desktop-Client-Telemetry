#include "SerialPortConnectionService.h"

namespace
{
   const QByteArray CAR_PORT_ADDRESS = "00:07:80:6E:F7:E4";
   const QByteArray FIRST_COMMAND = "AT";
   const QByteArray FIRST_RESPONSE = "OK";
   const int FIRST_REPONSE_MAXTIME = 100;
   const QByteArray SECOND_COMMAND = "PAIR " + CAR_PORT_ADDRESS;
   const QByteArray SECOND_RESPONSE = "PAIR " + CAR_PORT_ADDRESS + " OK";
   const int SECOND_RESPONSE_MAXTIME = 5000;
   const QByteArray THIRD_COMMAND = "CALL " + CAR_PORT_ADDRESS + " 1101 RFCOMM";
   const QByteArray THIRD_RESPONSE = "CALL 0";
   const int THIRD_RESPONSE_MAXTIME = 5000;
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

   //Bluetooth Connection
   setUpBlueGigaWT41Connection();
}

//For use only with the BlueGiga WT41 bluetooth chip
//This code was written for the Schulich Delta
void SerialPortConnectionService::setUpBlueGigaWT41Connection()
{
   serialPort_.write(FIRST_COMMAND);
   responseTimer_.start(FIRST_REPONSE_MAXTIME);
   connect(&serialPort_, SIGNAL(readyRead()), this, SLOT(firstStep()));
   connect(&responseTimer_, SIGNAL(timeout()), this, SLOT(responseTimedOut()));
}

void SerialPortConnectionService::firstStep()
{
   if (serialPort_.canReadLine())
   {
      if (serialPort_.readLine() == FIRST_RESPONSE){
         serialPort_.write(SECOND_COMMAND);
         responseTimer_.start(SECOND_RESPONSE_MAXTIME);
         disconnect(&serialPort_, SIGNAL(readyRead()), this, SLOT(firstStep()));
         connect(&serialPort_, SIGNAL(readyRead()), this, SLOT(secondStep()));

      }
      else{
         disconnect(&serialPort_, 0, this, 0);
         disconnect(&responseTimer_, 0, this, 0);
         responseTimer_.stop();
         emit connectionFailed("Did not receive " + FIRST_RESPONSE
                               + " after " + FIRST_COMMAND);
      }
   }
}

void SerialPortConnectionService::secondStep()
{
   if (serialPort_.canReadLine())
   {
      if (serialPort_.readLine() == SECOND_RESPONSE){
         serialPort_.write(THIRD_COMMAND);
         responseTimer_.start(THIRD_RESPONSE_MAXTIME);
         disconnect(&serialPort_, SIGNAL(readyRead()), this, SLOT(secondStep()));
         connect(&serialPort_, SIGNAL(readyRead()), this, SLOT(thirdStep()));

      }
      else{
         disconnect(&serialPort_, 0, this, 0);
         disconnect(&responseTimer_, 0, this, 0);
         responseTimer_.stop();
         emit connectionFailed("Did not receive " + SECOND_RESPONSE
                               + " after " + SECOND_COMMAND);
      }
   }
}


void SerialPortConnectionService::thirdStep()
{
   if (serialPort_.canReadLine())
   {
      if (serialPort_.readLine() == THIRD_RESPONSE){
         responseTimer_.start(THIRD_RESPONSE_MAXTIME);
         disconnect(&serialPort_, SIGNAL(readyRead()), this, SLOT(thirdStep()));
         connect(&serialPort_, SIGNAL(readyRead()), this, SLOT(fourthStep()));
      }
      else{
         responseTimer_.stop();
         emit connectionFailed("Did not receive " + THIRD_RESPONSE
                               + " after " + THIRD_COMMAND);
      }
      disconnect(&serialPort_, 0, this, 0);
      disconnect(&responseTimer_, 0, this, 0);
   }
}

void SerialPortConnectionService::fourthStep()
{
   if (serialPort_.canReadLine())
   {
      //Throws away first line to ensure all the following
      //serialPort.readLine()'s are not cut off.
      serialPort_.readLine();
      connected_ = true;
      emit connectionSucceeded();

      disconnect(&serialPort_, SIGNAL(readyRead()), this, SLOT(fourthStep()));
      responseTimer_.stop();
      disconnect(&responseTimer_, 0, this, 0);
   }


}

void SerialPortConnectionService::responseTimedOut()
{
   emit connectionFailed("Response timed out");
   disconnect(&serialPort_, 0, this, 0);
   disconnect(&responseTimer_, 0, this, 0);
}


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

   return "Check SerialPortConnectionService class";
}

void SerialPortConnectionService::succeeded()
{
   connected_ = false;
}

bool SerialPortConnectionService::isConnected()
{
   return connected_;
}

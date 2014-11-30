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
   SerialPortConnectionService(QString portName, int baudrate, QSerialPort& serialPort_);
   ~SerialPortConnectionService();

public slots:
   void connectDataSource(QString serialPortName, int baudRate);
   void disconnectDataSource();

private slots:
   void firstStep();
   void secondStep();
   void thirdStep();
   void fourthStep();
   void responseTimedOut();

private:
   void setUpBlueGigaWT41Connection();
   QString failed();
   QTimer responseTimer_;
   QTimer readingTimer_;
   QSerialPort &serialPort_;
};


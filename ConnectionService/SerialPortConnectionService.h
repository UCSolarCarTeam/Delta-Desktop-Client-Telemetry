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
   SerialPortConnectionService(QString portName, int baudrate);
   ~SerialPortConnectionService();
   bool isConnected();

public slots:
   /*connectDataSource() will ensure connection is complete
     and that the first readLine will return a full valid line. */
   void connectDataSource();
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
   void succeeded();
   QTimer responseTimer_;
   QSerialPort serialPort_;
   bool connected_;

};


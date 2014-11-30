#pragma once

#include "I_ConnectionService.h"

class FakeConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   FakeConnectionService();

   bool isConnected();
   void emitSignalConnectionSucceeded();

public slots:
   void connectDataSource(QString portName, int baudRate);
   void disconnectDataSource();
};

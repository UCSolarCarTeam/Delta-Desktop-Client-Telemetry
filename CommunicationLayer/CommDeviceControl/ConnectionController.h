#pragma once

#include "I_ConnectionService.h"
#include "CommDefines.h"

class ConnectionController : public I_ConnectionService
{
   Q_OBJECT
public:
   ConnectionController(
      I_ConnectionService& serial,
      I_ConnectionService& udp);
   virtual ~ConnectionController();

public:
   void setDeviceType(CommDefines::Type type);

   bool connectToDataSource();
   void disconnectFromDataSource();

private:
   void connectToConnectionService(I_ConnectionService& service);
   void disconnectFromConnectionService(I_ConnectionService& service);

private:
   CommDefines::Type type_;
   I_ConnectionService& serial_;
   I_ConnectionService& udp_;
};

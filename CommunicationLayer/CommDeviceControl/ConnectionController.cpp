#include "ConnectionController.h"

ConnectionController::ConnectionController(
   I_ConnectionService& serial,
   I_ConnectionService& udp)
: type_(CommDefines::Serial)
, serial_(serial)
, udp_(udp)
{
}

ConnectionController::~ConnectionController()
{
}

void ConnectionController::setDeviceType(CommDefines::Type type)
{
   type_ = type;
}

bool ConnectionController::connectToDataSource()
{
   disconnectFromDataSource();

   if (type_ == CommDefines::Udp)
   {
      connectToConnectionService(udp_);
      return udp_.connectToDataSource();
   }
   else
   {
      connectToConnectionService(serial_);
      return serial_.connectToDataSource();
   }
}

void ConnectionController::disconnectFromDataSource()
{
   udp_.disconnectFromDataSource();
   serial_.disconnectFromDataSource();
   disconnectFromConnectionService(udp_);
   disconnectFromConnectionService(serial_);
}

void ConnectionController::connectToConnectionService(I_ConnectionService& service)
{
   connect(&service, SIGNAL(connectionFailed(QString)),
      this, SIGNAL(connectionFailed(QString)), Qt::UniqueConnection);
   connect(&service, SIGNAL(connectionSucceeded()),
      this, SIGNAL(connectionSucceeded()), Qt::UniqueConnection);
}

void ConnectionController::disconnectFromConnectionService(I_ConnectionService& service)
{
   disconnect(&service, 0, this, 0);
}

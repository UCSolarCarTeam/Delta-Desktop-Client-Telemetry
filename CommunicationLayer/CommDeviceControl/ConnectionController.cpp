#include "ConnectionController.h"

ConnectionController::ConnectionController(
   I_ConnectionService& radio,
   I_ConnectionService& udp)
: type_(CommDefines::Serial)
, radio_(radio)
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
      connectToConnectionService(radio_);
      return radio_.connectToDataSource();
   }
}

void ConnectionController::disconnectFromDataSource()
{
   udp_.disconnectFromDataSource();
   radio_.disconnectFromDataSource();
   disconnectFromConnectionService(udp_);
   disconnectFromConnectionService(radio_);
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

#include <QUdpSocket>
#include "UdpConnectionService.h"

UdpConnectionService::UdpConnectionService(QUdpSocket& socket)
: port_(0)
, socket_(socket)
{
}

UdpConnectionService::~UdpConnectionService()
{
}

void  UdpConnectionService::setMulticastNetwork(QHostAddress groupAddress, quint16 port)
{
   groupAddress_ = groupAddress;
   port_ = port;
}

bool UdpConnectionService::connectToDataSource()
{
   if (groupAddress_.isNull() || port_ == 0)
   {
      emit connectionFailed("Group address and port number is not set!");
      return false;
   }

   if (socket_.bind(QHostAddress::AnyIPv4, port_, QUdpSocket::ShareAddress) &&
      socket_.joinMulticastGroup(groupAddress_))
   {
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(socket_.errorString());
      return false;
   }
}

void UdpConnectionService::disconnectFromDataSource()
{
   socket_.leaveMulticastGroup(groupAddress_);
   socket_.close();

   emit connectionFailed("DISCONNECTED");
}

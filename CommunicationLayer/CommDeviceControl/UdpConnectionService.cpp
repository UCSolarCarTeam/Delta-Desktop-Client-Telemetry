#include <QUdpSocket>
#include "UdpConnectionService.h"
#include <QDebug>

UdpConnectionService::UdpConnectionService(QUdpSocket& socket)
: port_(0)
, socket_(socket)
{
}

UdpConnectionService::~UdpConnectionService()
{
}

void  UdpConnectionService::setMulticastNetwork(QHostAddress ipAddress, quint16 port)
{
   ipAddress_ = ipAddress;
   port_ = port;
}

bool UdpConnectionService::connectToDataSource()
{
   if (ipAddress_.isNull() || port_ == 0)
   {
      emit connectionFailed("Group address and port number is not set!");
      return false;
   }
   if(socket_.bind(QHostAddress::AnyIPv4, port_, QUdpSocket::ShareAddress))
   {
      sendHeartbeat();
      connect(&heartbeatTimer_, SIGNAL(timeout()), this, SLOT(sendHeartbeat()));
      heartbeatTimer_.setInterval(1000);
      heartbeatTimer_.start();
      emit connectionSucceeded();
      return true;
   }
   else
   {
      emit connectionFailed(socket_.errorString());
      qDebug() << socket_.error();
      return false;
   }
}

void UdpConnectionService::disconnectFromDataSource()
{
   disconnect(&heartbeatTimer_, SIGNAL(timeout()), this, SLOT(sendHeartbeat()));
   heartbeatTimer_.stop();
   if (socket_.state() != QUdpSocket::UnconnectedState)
   {
      socket_.disconnectFromHost();
   }
   socket_.close();

   emit connectionFailed("DISCONNECTED");
}

bool UdpConnectionService::sendHeartbeat()
{  
   QByteArray data = QByteArray("Heartbeat");
   const quint64 dataWritten = socket_.writeDatagram(data, ipAddress_, port_);
   if (dataWritten != static_cast<quint64>(data.size()))
   {
      return false;
   }
   else
   {
      return true;
   }
}

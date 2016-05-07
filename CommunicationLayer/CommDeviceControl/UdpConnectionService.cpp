#include <QUdpSocket>
#include "UdpConnectionService.h"
#include <QDebug>

UdpConnectionService::UdpConnectionService(QUdpSocket& socket)
: port_(0)
, socket_(socket)
{
   connect(&heartbeatTimer_, SIGNAL(timeout()), this, SLOT(sendHeartbeat()));
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
   if (socket_.bind(ipAddress_, port_))
   {
      heartbeatTimer_.setInterval(1000);
      heartbeatTimer_.start();
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
   heartbeatTimer_.stop();
   if (socket_.state() != QUdpSocket::UnconnectedState)
   {
      socket_.disconnectFromHost();
   }
   socket_.close();

   emit connectionFailed("DISCONNECTED");
}

void UdpConnectionService::sendHearbeat()
{  
   QByteArray data = QByteArray("Heartbeat from the desktop telemetry");
   const quint64 dataWritten = socket_.writeDatagram(data, ipAddress_, port_);
   if (dataWritten != static_cast<quint64>(data.size()))
   {
      qWarning() << "Unable to send heartbeat";
   }
   else
   {
      qDebug() << "Successfully sent heartbeat" ;
   }
}

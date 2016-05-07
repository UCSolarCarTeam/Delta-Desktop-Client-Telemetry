#include <QByteArray>
#include <QDebug>

#include "I_CommDevice.h"
#include "UdpMessageForwarder.h"

UdpMessageForwarder::UdpMessageForwarder(const I_CommDevice& device)
: device_(device)
{
}

UdpMessageForwarder::~UdpMessageForwarder()
{
}

void UdpMessageForwarder::setMulticastNetwork(const QHostAddress& ipAddress, quint16 port)
{
   ipAddress_ = ipAddress;
   port_ = port;
}

void UdpMessageForwarder::start()
{
   connect(&device_, SIGNAL(dataReceived(QByteArray)),
      this, SLOT(forwardData(QByteArray)), Qt::UniqueConnection);
}

void UdpMessageForwarder::stop()
{
   disconnect(&device_, 0, this, 0);
}

void UdpMessageForwarder::forwardData(QByteArray data)
{
   const quint64 dataWritten = socket_.writeDatagram(data, ipAddress_, port_);
   if (dataWritten != static_cast<quint64>(data.size()))
   {
      qWarning() << "Unable to forward data";
   }
   else
   {
      qDebug() << "Successfully forwarded data";
   }
}

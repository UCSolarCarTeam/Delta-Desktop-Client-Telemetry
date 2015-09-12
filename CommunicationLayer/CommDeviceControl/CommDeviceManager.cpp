#include <QUdpSocket>

#include "CommDeviceManager.h"
#include <QDebug>

CommDeviceManager::CommDeviceManager(QUdpSocket& udpSocket, QIODevice& serialDevice)
: udpSocket_(udpSocket)
, serialDevice_(serialDevice)
{
}

CommDeviceManager::~CommDeviceManager()
{
}

void CommDeviceManager::connectToDevice(CommDefines::Type type)
{
   disconnectFromDevices();
   if (type == CommDefines::Udp)
   {
      connect(&udpSocket_, SIGNAL(readyRead()), this, SLOT(handleUdpDataIncoming()), Qt::UniqueConnection);
   }
   else
   {
      connect(&serialDevice_, SIGNAL(readyRead()), this, SLOT(handleSerialDataIncoming()), Qt::UniqueConnection);
   }
}

void CommDeviceManager::disconnectFromDevices()
{
   disconnect(&udpSocket_, 0, this, 0);
   disconnect(&serialDevice_, 0, this, 0);
}

void CommDeviceManager::handleUdpDataIncoming()
{
   while (udpSocket_.hasPendingDatagrams())
   {
      QByteArray datagram;
      datagram.resize(udpSocket_.pendingDatagramSize());
      udpSocket_.readDatagram(datagram.data(), datagram.size());

      if (!datagram.isEmpty())
      {
         emit dataReceived(datagram);
      }
   }
}

void CommDeviceManager::handleSerialDataIncoming()
{
   QByteArray incomingData = serialDevice_.readAll();
   if (incomingData.isEmpty())
   {
      return;
   }
   emit dataReceived(incomingData);
}

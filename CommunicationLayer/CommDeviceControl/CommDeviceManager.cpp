#include <QUdpSocket>

#include "CommDeviceManager.h"

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
      connect(&udpSocket_, SIGNAL(readyRead()), this, SLOT(handleUdpDataIncomming()));
   }
   else
   {
      connect(&serialDevice_, SIGNAL(readyRead()), this, SLOT(handleSerialDataIncomming()));
   }
}

void CommDeviceManager::disconnectFromDevices()
{
   disconnect(&udpSocket_, 0, this, 0);
   disconnect(&serialDevice_, 0, this, 0);
}

void CommDeviceManager::handleUdpDataIncomming()
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

void CommDeviceManager::handleSerialDataIncomming()
{
   QByteArray incommingData = serialDevice_.readAll();
   if (incommingData.isEmpty())
   {
      return;
   }
   emit dataReceived(incommingData);
}

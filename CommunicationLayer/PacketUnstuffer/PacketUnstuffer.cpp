#include <QDebug>

#include "PacketUnstuffer.h"
#include "../PacketSynchronizer/I_PacketSynchronizer.h"

namespace
{
   const int MINIMUM_LENGTH_OF_A_PACKET = 4;
}

PacketUnstuffer::PacketUnstuffer(const I_PacketSynchronizer& packetSynchronizer)
{
   connect(&packetSynchronizer, SIGNAL(framedPacket(QByteArray)),
      this, SLOT(handleFramedPacket(QByteArray)));
}

PacketUnstuffer::~PacketUnstuffer()
{
}

void PacketUnstuffer::handleFramedPacket(QByteArray packet)
{
   if (!isPacketAtLeastMinimumSize(packet))
   {
      qDebug() << "Incoming packet is less that " << MINIMUM_LENGTH_OF_A_PACKET << " bytes";
      return;
   }

   const int length = packet.size();
   QByteArray decodedData;
   for (int indexOfCode = 0; indexOfCode < length; indexOfCode++)
   {
      int indexOfNextCode = packet.at(indexOfCode) + 1;
      for (int j = indexOfCode + 1; j < indexOfNextCode && j < length; j++)
      {
         decodedData.append(packet.at(j));
      }
      if (indexOfNextCode < 0xFF)
      {
         decodedData.append(QChar(0x00));
      }
      indexOfCode = indexOfNextCode;
   }
   emit packetUnsuffed(decodedData);
}

bool PacketUnstuffer::isPacketAtLeastMinimumSize(const QByteArray& packet)
{
   return packet.size() >= MINIMUM_LENGTH_OF_A_PACKET;
}

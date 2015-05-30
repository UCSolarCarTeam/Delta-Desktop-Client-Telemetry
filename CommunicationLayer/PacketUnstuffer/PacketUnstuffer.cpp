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

   const unsigned int length = packet.size();
   QByteArray decodedData;
   unsigned int indexOfCode = 0;
   while (indexOfCode < length)
   {
      unsigned int indexOfNextCode = (unsigned)packet.at(indexOfCode) + indexOfCode;
      for (unsigned int j = indexOfCode + 1; j < indexOfNextCode && j < length; j++)
      {
         decodedData.append(packet.at(j));
      }
      if (indexOfNextCode < 0xFF && indexOfNextCode < length)
      {
         decodedData.append(QChar(0x00));
      }
      indexOfCode = indexOfNextCode;
   }
   emit packetUnstuffed(decodedData);
}

bool PacketUnstuffer::isPacketAtLeastMinimumSize(const QByteArray& packet)
{
   return packet.size() >= MINIMUM_LENGTH_OF_A_PACKET;
}

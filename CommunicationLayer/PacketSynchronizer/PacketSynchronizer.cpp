#include <QChar>

#include "PacketSynchronizer.h"
#include "../ConnectionService/I_ConnectionService.h"

namespace
{
   const QChar FRAMING_BYTE = 0x00;
}

PacketSynchronizer::PacketSynchronizer(
   QIODevice& inputDevice,
   I_ConnectionService& connectionService)
: inputDevice_(inputDevice)
, buffer_()
{
   connect(&connectionService, SIGNAL(connectionSucceeded(QString)),
      this, SLOT(handleConnectionCreated()));
}

PacketSynchronizer::~PacketSynchronizer()
{
}

void PacketSynchronizer::handleConnectionCreated()
{
   connect(&inputDevice_, SIGNAL(readyRead()),
      this, SLOT(handleIncommingSerialData()));
}

void PacketSynchronizer::handleIncommingSerialData()
{
   QByteArray incommingSerialData = inputDevice_.readAll();

   if (incommingSerialData.isEmpty())
   {
      return;
   }

   buffer_.append(incommingSerialData);
   if (alignStartOfPacketToBeginningOfBuffer())
   {
      while(extractPacketIfComplete());
   }
}

bool PacketSynchronizer::alignStartOfPacketToBeginningOfBuffer()
{
   int indexOfStartOfPacket = buffer_.indexOf(FRAMING_BYTE);
   if (indexOfStartOfPacket == -1)
   {
      return false;
   }
   else if (indexOfStartOfPacket > 0)
   {
      buffer_ = buffer_.mid(indexOfStartOfPacket);
   }
   return true;
}

bool PacketSynchronizer::extractPacketIfComplete()
{
   int indexOfEndOfPacket = buffer_.indexOf(FRAMING_BYTE, 1); // Find if there is an end.
   if (indexOfEndOfPacket == -1)
   {
      return false;
   }

   QByteArray packet = buffer_.left(indexOfEndOfPacket);
   packet = packet.mid(1); // remove the leading 0x00
   buffer_.remove(0, indexOfEndOfPacket);
   emit framedPacket(packet);
   return true;
}

#include <QChar>

#include "PacketSynchronizer.h"
#include "CommunicationLayer/CommDeviceControl/I_CommDevice.h"

namespace
{
   const QChar FRAMING_BYTE = 0x00;
}

PacketSynchronizer::PacketSynchronizer(
   I_CommDevice& inputDevice)
: buffer_()
{
   connect(&inputDevice, SIGNAL(dataReceived(QByteArray)),
      this, SLOT(handleIncomingData(QByteArray)));
}

PacketSynchronizer::~PacketSynchronizer()
{
}

void PacketSynchronizer::handleIncomingData(QByteArray incomingData)
{
   if (incomingData.isEmpty())
   {
      return;
   }

   buffer_.append(incomingData);
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

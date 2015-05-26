#include "PacketDecoder.h"
#include "../PacketSynchronizer/I_PacketSynchronizer.h"
#include "../MessagingFramework/MessageDefines.h"

namespace
{
   const int INDEX_OF_PACKET_TYPE = 0;
   const int MINIMUM_LENGTH_OF_A_PACKET = 4;
}

PacketDecoder::PacketDecoder(const I_PacketSynchronizer& packetSynchronizer)
{
   connect(&packetSynchronizer, SIGNAL(framedPacket(QByteArray)),
      this, SLOT(handleFramedPacket(QByteArray)));
}

void PacketDecoder::handleFramedPacket(QByteArray packet)
{
   if (!isPacketAtLeastMinimumSize(packet))
   {
      qDebug() << "Incoming packet is less that " << MINIMUM_LENGTH_OF_A_PACKET << " bytes";
      return;
   }

   QByteArray decodedData = unstuffPacket(packet);

   const quint16 checksum = retrieveChecksumFromPacket(decodedData);
   const int lastIndexOfData = decodedData.size() - 1;
   decodedData.truncate(lastIndexOfData - sizeof(checksum));

   const bool isPacketValid = checkChecksum(decodedData, checksum);

   if (isPacketValid)
   {
      createAndNotifyMessageReceived(decodedData);
   }
   else
   {
      qDebug() << "Error decoding data, raw data is: " << QString(packet.toHex());
   }
}

bool PacketDecoder::isPacketAtLeastMinimumSize(const QByteArray& packet)
{
   return packet.size() >= MINIMUM_LENGTH_OF_A_PACKET;
}

QByteArray PacketDecoder::unstuffPacket(const QByteArray& encodedData)
{
   const int length = encodedData.size();
   QByteArray decodedData;
   for (int indexOfCode = 0; indexOfCode < length; indexOfCode++)
   {
      int indexOfNextCode = encodedData.at(indexOfCode) + 1;
      for (int j = indexOfCode + 1; j < indexOfNextCode && j < length; j++)
      {
         decodedData.append(encodedData.at(j));
      }
      if (indexOfNextCode < 0xFF)
      {
         decodedData.append(QChar(0x00));
      }
      indexOfCode = indexOfNextCode;
   }
   return decodedData;
}

bool PacketDecoder::checkChecksum(const QByteArray& messageData, const quint16 checksum)
{
   quint16 calculatedChecksum = qChecksum(messageData.constData(), messageData.size());
   return calculatedChecksum == checksum;
}

quint16 PacketDecoder::retrieveChecksumFromPacket(const QByteArray& decodedData)
{
   const int lastIndexOfData = decodedData.size() - 1;
   return (decodedData.at(lastIndexOfData) << 8) |
      decodedData.at(lastIndexOfData - 1);
}

void PacketDecoder::createAndNotifyMessageReceived(const QByteArray& messageData)
{
   MessageDefines::Type messageType =
      static_cast<MessageDefines::Type>(messageData.at(INDEX_OF_PACKET_TYPE));

   if (MessageDefines::getLengthForMessage(messageType) == messageData.size())
   {
      switch(messageType)
      {
      case MessageDefines::KeyDriverControlTelemetry:
         emit packetDecoded(KeyDriverControlTelemetry(messageData));
         return;
      case MessageDefines::DriverControlDetails:
         emit packetDecoded(DriverControlDetails(messageData));
         return;
      case MessageDefines::Faults:
         emit packetDecoded(FaultsMessage(messageData));
         return;
      case MessageDefines::BatteryData:
         emit packetDecoded(BatteryDataMessage(messageData));
         return;
      case MessageDefines::CmuData:
         emit packetDecoded(CmuDataMessage(messageData));
         return;
      }
   }
}

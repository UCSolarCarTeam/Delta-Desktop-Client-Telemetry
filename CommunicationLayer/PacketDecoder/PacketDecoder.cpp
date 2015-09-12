#include <QDebug>

#include "PacketDecoder.h"
#include "../PacketChecksumChecker/I_PacketChecksumChecker.h"
#include "../MessagingFramework/MessageDefines.h"

namespace
{
   const int INDEX_OF_PACKET_TYPE = 0;
}

PacketDecoder::PacketDecoder(const I_PacketChecksumChecker& checksumChecker)
{
   connect(&checksumChecker, SIGNAL(validDataReceived(QByteArray)),
      this, SLOT(handleValidData(QByteArray)));
}

PacketDecoder::~PacketDecoder()
{
}

void PacketDecoder::handleValidData(QByteArray messageData)
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
      case MessageDefines::MpptData:
         emit packetDecoded(MpptDataMessage(messageData));
         return;
      }
   }
   else
   {
      qDebug() << "Message length is not correct for type" << static_cast<quint8>(messageType);
      qDebug() << "Actual" << messageData.size() << "Expected" << MessageDefines::getLengthForMessage(messageType);
   }
}

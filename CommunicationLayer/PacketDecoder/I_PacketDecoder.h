#pragma once

#include <QObject>
#include "CommunicationLayer/MessagingFramework/BatteryDataMessage.h"
#include "CommunicationLayer/MessagingFramework/CmuDataMessage.h"
#include "CommunicationLayer/MessagingFramework/DriverControlDetails.h"
#include "CommunicationLayer/MessagingFramework/FaultsMessage.h"
#include "CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h"

class I_PacketDecoder : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketDecoder() {}

signals:
   void packetDecoded(const KeyDriverControlTelemetry message);
   void packetDecoded(const DriverControlDetails message);
   void packetDecoded(const FaultsMessage message);
   void packetDecoded(const BatteryDataMessage message);
   void packetDecoded(const CmuDataMessage message);
};

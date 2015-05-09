#pragma once

#include <QObject>
#include "../MessagingFramework/BatteryDataMessage.h"
#include "../MessagingFramework/CmuDataMessage.h"
#include "../MessagingFramework/DriverControlDetails.h"
#include "../MessagingFramework/FaultsMessage.h"
#include "../MessagingFramework/KeyDriverControlTelemetry.h"

class I_PacketDecoder : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketDecoder() {}

signals:
   void packetDecoded(const BatteryDataMessage message);
   void packetDecoded(const CmuDataMessage message);
   void packetDecoded(const DriverControlDetails message);
   void packetDecoded(const FaultsMessage message);
   void packetDecoded(const KeyDriverControlTelemetry message);
};

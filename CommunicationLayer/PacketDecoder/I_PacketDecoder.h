#pragma once

#include <QObject>
#include "../MessagingFramework/DriverControlDetails.h"
#include "../MessagingFramework/FaultsMessage.h"
#include "../MessagingFramework/KeyDriverControlTelemetry.h"

class I_PacketDecoder : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketDecoder() {}

signals:
   void packetDecoded(const KeyDriverControlTelemetry message);
   void packetDecoded(const DriverControlDetails message);
   void packetDecoded(const FaultsMessage message);
};

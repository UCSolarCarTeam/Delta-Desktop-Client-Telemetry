#pragma once

#include "I_PacketSynchronizer.h"

class FakePacketSynchronizer : public I_PacketSynchronizer
{
   Q_OBJECT
public:
   FakePacketSynchronizer();
   virtual ~FakePacketSynchronizer();

   void emitFramedPacket(const QByteArray& packet);
};

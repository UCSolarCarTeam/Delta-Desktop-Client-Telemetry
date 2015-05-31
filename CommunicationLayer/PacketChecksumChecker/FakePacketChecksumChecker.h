#pragma once

#include "I_PacketChecksumChecker.h"

class FakePacketChecksumChecker : public I_PacketChecksumChecker
{
   Q_OBJECT
public:
   FakePacketChecksumChecker();
   virtual ~FakePacketChecksumChecker();

   void emitValidDataReceived(QByteArray validData);
};

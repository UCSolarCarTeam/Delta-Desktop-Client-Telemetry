#include "I_PacketUnstuffer.h"

class FakePacketUnstuffer : public I_PacketUnstuffer
{
   Q_OBJECT
public:
   FakePacketUnstuffer();
   virtual ~FakePacketUnstuffer();

   void emitPacketUnstuffed(QByteArray decodedData);
};

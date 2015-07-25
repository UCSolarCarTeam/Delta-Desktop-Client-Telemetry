#pragma once

#include "I_PacketSynchronizer.h"
class I_CommDevice;

class PacketSynchronizer : public I_PacketSynchronizer
{
   Q_OBJECT
public:
   PacketSynchronizer(I_CommDevice& inputDevice);
   virtual ~PacketSynchronizer();

private slots:
   void handleIncommingData(QByteArray incommingData);

private:
   bool alignStartOfPacketToBeginningOfBuffer();
   bool extractPacketIfComplete();

private:
   QByteArray buffer_;
};

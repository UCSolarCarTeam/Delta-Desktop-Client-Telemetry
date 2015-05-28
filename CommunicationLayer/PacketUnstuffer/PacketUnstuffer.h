#pragma once

#include "I_PacketUnstuffer.h"
class I_PacketSynchronizer;

class PacketUnstuffer : public I_PacketUnstuffer
{
   Q_OBJECT
public:
   explicit PacketUnstuffer(const I_PacketSynchronizer& packetSynchronizer);
   virtual ~PacketUnstuffer();

private slots:
   void handleFramedPacket(QByteArray packet);

private:
   bool isPacketAtLeastMinimumSize(const QByteArray& packet);
   QByteArray unstuffPacket(const QByteArray& encodedData);
};

#pragma once

#include "I_PacketUnstuffer.h"
#include "I_DataInjectionService.h"
class I_PacketSynchronizer;

class PacketUnstuffer : public I_PacketUnstuffer, public I_DataInjectionService
{
   Q_OBJECT
public:
   explicit PacketUnstuffer(const I_PacketSynchronizer& packetSynchronizer);
   virtual ~PacketUnstuffer();

   void injectFramedData(const QByteArray& data);

private slots:
   void handleFramedPacket(QByteArray packet);

private:
   bool isPacketAtLeastMinimumSize(const QByteArray& packet);
   QByteArray unstuffPacket(const QByteArray& encodedData);
};

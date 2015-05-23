#pragma once

#include <QObject>
#include "I_PacketDecoder.h"
class I_PacketSynchronizer;

class PacketDecoder : public I_PacketDecoder
{
   Q_OBJECT
public:
   explicit PacketDecoder(const I_PacketSynchronizer& packetSynchronizer);

private slots:
   void handleFramedPacket(QByteArray packet);

private:
   QByteArray unstuffPacket(const QByteArray& encodedData);
   bool checkChecksum(const QByteArray& messageData, const quint16 checksum);
   quint16 retrieveChecksumFromPacket(const QByteArray& decodedData);
   void createAndNotifyMessageReceived(const QByteArray& messageData);
};

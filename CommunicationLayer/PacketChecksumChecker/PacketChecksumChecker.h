#pragma once

#include "I_PacketChecksumChecker.h"
class I_PacketUnstuffer;

class PacketChecksumChecker : public I_PacketChecksumChecker
{
   Q_OBJECT
public:
   explicit PacketChecksumChecker(const I_PacketUnstuffer& unstuffer);
   virtual ~PacketChecksumChecker();

private slots:
   void checkChecksum(QByteArray decodedData);

private:
   quint16 retrieveChecksumFromPacket(const QByteArray& decodedData);
};

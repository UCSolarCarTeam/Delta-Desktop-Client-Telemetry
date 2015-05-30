#include <QDebug>

#include "PacketChecksumChecker.h"
#include "../PacketUnstuffer/I_PacketUnstuffer.h"

PacketChecksumChecker::PacketChecksumChecker(const I_PacketUnstuffer& unstuffer)
{
   connect(&unstuffer, SIGNAL(packetUnstuffed(QByteArray)),
      this, SLOT(checkChecksum(QByteArray)));
}

PacketChecksumChecker::~PacketChecksumChecker()
{
}

void PacketChecksumChecker::checkChecksum(QByteArray decodedData)
{
   const quint16 checksum = retrieveChecksumFromPacket(decodedData);
   const int lastIndexOfData = decodedData.size() - 1;
   decodedData.truncate(lastIndexOfData - sizeof(checksum));

   quint16 calculatedChecksum = qChecksum(decodedData.constData(), decodedData.size());
   if (calculatedChecksum == checksum)
   {
      emit validDataReceived(decodedData);
   }
   else
   {
      qDebug() << "Error decoding data, checksum doesn't match. Data is: " << decodedData.toHex();
   }
}

quint16 PacketChecksumChecker::retrieveChecksumFromPacket(const QByteArray& decodedData)
{
   const int lastIndexOfData = decodedData.size() - 1;
   return (decodedData.at(lastIndexOfData) << 8) |
      decodedData.at(lastIndexOfData - 1);
}

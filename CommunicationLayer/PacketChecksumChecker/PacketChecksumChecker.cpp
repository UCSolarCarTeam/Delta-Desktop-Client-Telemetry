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
   decodedData.chop(sizeof(checksum));

   quint16 calculatedChecksum = qChecksum(decodedData.constData(), decodedData.size());
   if (calculatedChecksum == checksum)
   {
      emit validDataReceived(decodedData);
   }
   else
   {
      qDebug() << "Calculated =" << QByteArray::number(calculatedChecksum, 16) << "retrieved ="
         << QByteArray::number(checksum, 16);
      qDebug() << "Error decoding data, checksum doesn't match. Data is: " << decodedData;
   }
}

quint16 PacketChecksumChecker::retrieveChecksumFromPacket(const QByteArray& decodedData)
{
   const int lastIndexOfData = decodedData.size() - 1;
   unsigned char upper = decodedData.at(lastIndexOfData);
   unsigned char lower = decodedData.at(lastIndexOfData - 1);
   quint16 checksum = ((upper << 8) & 0xFF00) | lower;
   return checksum;
}

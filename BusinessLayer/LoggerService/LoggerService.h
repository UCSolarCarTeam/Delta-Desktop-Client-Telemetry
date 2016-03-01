#pragma once

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDateTime>
#include <QDir>

#include "CommunicationLayer/PacketDecoder/I_PacketDecoder.h"
class I_PacketDecoder;
class I_PacketSynchronizer;

class LoggerService : public QObject
{
   Q_OBJECT
public:
   LoggerService(const I_PacketSynchronizer& packetSynchronizer,
      const I_PacketDecoder& packetDecoder);
   virtual ~LoggerService();

private slots:
   void handleFramedPacket(QByteArray packet);
   void handlePacketDecoded(const KeyDriverControlTelemetry message);
   void handlePacketDecoded(const DriverControlDetails message);
   void handlePacketDecoded(const FaultsMessage message);
   void handlePacketDecoded(const BatteryDataMessage message);
   void handlePacketDecoded(const CmuDataMessage message);

private:
   void connectToPacketDecoder(const I_PacketDecoder& decoder);
   template <class T>
   void printReceivedMessage(const T& message);
   void markStartOfDebugLog() const;
   void markEndOfDebugLog() const;

   QFile logCsvFile_;
   QTextStream csvFileWriter_;

   QFile rawDataFile_;
   QDataStream dataWriter_;
};

#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QTest>
#include "../../PacketChecksumChecker/FakePacketChecksumChecker.h"
#include "../PacketDecoder.h"

class TestPacketDecoder : public QObject
{
   Q_OBJECT
private slots:
   void init();
   void cleanup();

   void willReceiveKeyDriverControlTelemetry();
   void willReceiveDriverControlDetails();
   void willReceiveFaultsMessage();
   void willReceiveBatteryDataMessage();
   void willReceiveCmuDataMessage();
   void willReceiveMpptDataMessage();

protected slots:
   void handlePacketDecoded(const KeyDriverControlTelemetry message);
   void handlePacketDecoded(const DriverControlDetails message);
   void handlePacketDecoded(const FaultsMessage message);
   void handlePacketDecoded(const BatteryDataMessage message);
   void handlePacketDecoded(const CmuDataMessage message);
   void handlePacketDecoded(const MpptDataMessage message);

private:
   void connectPacketDecodedSignals();
   QByteArray createValidKeyDriverControlTelemetry() const;
   QByteArray createValidDriverControlDetails() const;
   QByteArray createValidFaultsMessage() const;
   QByteArray createValidBatteryDataMessage() const;
   QByteArray createValidCmuDataMessage() const;
   QByteArray createValidMpptDataMessage() const;
   QByteArray floatToByteArray(float value) const;

private:
   QScopedPointer<FakePacketChecksumChecker> checksumChecker_;
   QScopedPointer<PacketDecoder> patient_;
   QList<KeyDriverControlTelemetry> receivedKeyDriverControlTelemetry_;
   QList<DriverControlDetails> receivedDriverControlDetails_;
   QList<FaultsMessage> receivedFaultsMessages_;
   QList<BatteryDataMessage> receivedBatteryDataMessages_;
   QList<CmuDataMessage> receivedCmuDataMessages_;
   QList<MpptDataMessage> receivedMpptDataMessages_;
};

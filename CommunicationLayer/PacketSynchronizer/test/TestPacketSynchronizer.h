#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QTest>
#include "../../ConnectionService/FakeConnectionService.h"
#include "../PacketSynchronizer.h"
#include "FakeSerialPort.h"

class TestPacketSynchronizer : public QObject
{
   Q_OBJECT
private slots:
   void init();
   void cleanup();

   void willHandleIncommingSerialData();
   void willHandleIncommingSerialData_data();

   void willNotEmitPacketIfNotCompletePacket();
   void willNotEmitPacketIfNotCompletePacket_data();
   void willNotEmitIfNotConnected();

   void willHandleIncommingDataSplitBetweenReads();
   void willHandleMultiplePacketsInOneRead();

private:
   QScopedPointer<FakeConnectionService> connectionService_;
   QScopedPointer<FakeSerialPort> serialPort_;
   QScopedPointer<PacketSynchronizer> patient_;
};

#include <QCoreApplication>
#include <QSignalSpy>
#include "TestPacketSynchronizer.h"
QTEST_MAIN(TestPacketSynchronizer)

void TestPacketSynchronizer::init()
{
   connectionService_.reset(new FakeConnectionService);
   serialPort_.reset(new FakeSerialPort);
   patient_.reset(new PacketSynchronizer(*serialPort_, *connectionService_));

   serialPort_->open(QIODevice::ReadWrite);
   serialPort_->seek(0);
}

void TestPacketSynchronizer::cleanup()
{
   patient_.reset();
   serialPort_.reset();
   connectionService_.reset();
}

void TestPacketSynchronizer::willHandleIncomingSerialData()
{
   QFETCH(QByteArray, incomingData);
   connectionService_->emitSignalConnectionSucceeded();
   serialPort_->setData(incomingData);

   QSignalSpy spy(patient_.data(), SIGNAL(framedPacket(QByteArray)));
   serialPort_->emitReadyRead();

   QCOMPARE(spy.count(), 1);
   QTEST(spy[0][0].toByteArray(), "expectedData");
}

void TestPacketSynchronizer::willHandleIncomingSerialData_data()
{
   QTest::addColumn<QByteArray>("incomingData");
   QTest::addColumn<QByteArray>("expectedData");
   QTest::newRow("Start of packet at index 0") << QByteArray::fromHex("0023456789abcdef00")
      << QByteArray::fromHex("23456789abcdef");
   QTest::newRow("Trailing data") << QByteArray::fromHex("0023456789ab00cdef")
      << QByteArray::fromHex("23456789ab");
   QTest::newRow("Preceding data") << QByteArray::fromHex("2345006789abcdef00")
      << QByteArray::fromHex("6789abcdef");
   QTest::newRow("No data") << QByteArray::fromHex("0000") << QByteArray();
}

void TestPacketSynchronizer::willNotEmitPacketIfNotCompletePacket()
{
   QFETCH(QByteArray, incomingData);
   connectionService_->emitSignalConnectionSucceeded();
   serialPort_->setData(incomingData);

   QSignalSpy spy(patient_.data(), SIGNAL(framedPacket(QByteArray)));
   serialPort_->emitReadyRead();

   QCOMPARE(spy.count(), 0);
}

void TestPacketSynchronizer::willNotEmitPacketIfNotCompletePacket_data()
{
   QTest::addColumn<QByteArray>("incomingData");
   QTest::newRow("No framing packets") << QByteArray::fromHex("23456789abcdef");
   QTest::newRow("One midway through") << QByteArray::fromHex("23456789ab00cdef");
}

void TestPacketSynchronizer::willNotEmitIfNotConnected()
{
   serialPort_->setData(QByteArray::fromHex("0023456789abcdef00"));

   QSignalSpy spy(patient_.data(), SIGNAL(framedPacket(QByteArray)));
   serialPort_->emitReadyRead();

   QCOMPARE(spy.count(), 0);
}

void TestPacketSynchronizer::willHandleIncomingDataSplitBetweenReads()
{
   connectionService_->emitSignalConnectionSucceeded();
   serialPort_->setData(QByteArray::fromHex("45006789ab"));
   serialPort_->emitReadyRead();
   serialPort_->setData(QByteArray::fromHex("cdef001234"));

   QSignalSpy spy(patient_.data(), SIGNAL(framedPacket(QByteArray)));
   serialPort_->emitReadyRead();

   QCOMPARE(spy.count(), 1);
   QCOMPARE(spy[0][0].toByteArray(), QByteArray::fromHex("6789abcdef"));
}

void TestPacketSynchronizer::willHandleMultiplePacketsInOneRead()
{
   connectionService_->emitSignalConnectionSucceeded();
   serialPort_->setData(QByteArray::fromHex("45006789ab001234567800cf"));

   QSignalSpy spy(patient_.data(), SIGNAL(framedPacket(QByteArray)));
   serialPort_->emitReadyRead();

   QCOMPARE(spy.count(), 2);
   QCOMPARE(spy[0][0].toByteArray(), QByteArray::fromHex("6789ab"));
   QCOMPARE(spy[1][0].toByteArray(), QByteArray::fromHex("12345678"));
}

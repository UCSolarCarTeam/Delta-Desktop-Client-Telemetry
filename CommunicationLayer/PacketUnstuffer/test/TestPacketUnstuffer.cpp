#include <QCoreApplication>
#include <QSignalSpy>
#include "TestPacketUnstuffer.h"
QTEST_MAIN(TestPacketUnstuffer)

namespace
{
   const int MINIMUM_LENGTH_OF_A_PACKET = 4;
}

void TestPacketUnstuffer::init()
{
   synchronizer_.reset(new FakePacketSynchronizer);
   patient_.reset(new PacketUnstuffer(*synchronizer_));
}

void TestPacketUnstuffer::cleanup()
{
   patient_.reset();
   synchronizer_.reset();
}

void TestPacketUnstuffer::willNotUnstuffPacketsUnderMinimumSize()
{
   QByteArray testData;
   testData.fill('0', MINIMUM_LENGTH_OF_A_PACKET - 1);

   QSignalSpy spy(patient_.data(), SIGNAL(packetUnstuffed(QByteArray)));
   synchronizer_->emitFramedPacket(testData);

   QCOMPARE(spy.count(), 0);
}

void TestPacketUnstuffer::willUnstuffPackets()
{
   QFETCH(QByteArray, framedPacket);

   QSignalSpy spy(patient_.data(), SIGNAL(packetUnstuffed(QByteArray)));
   synchronizer_->emitFramedPacket(framedPacket);

   QCOMPARE(spy.count(), 1);
   QTEST(spy[0][0].toByteArray(), "expectedResult");
}

void TestPacketUnstuffer::willUnstuffPackets_data()
{
   QTest::addColumn<QByteArray>("framedPacket");
   QTest::addColumn<QByteArray>("expectedResult");
   QTest::newRow("All Zeros") << QByteArray::fromHex("0101010101")
      << QByteArray::fromHex("00000000");
   QTest::newRow("No Zeros") << QByteArray::fromHex("0501010101")
      << QByteArray::fromHex("01010101");
   QTest::newRow("Some Zeros") << QByteArray::fromHex("020303FFAA")
      << QByteArray::fromHex("0300FFAA");
}

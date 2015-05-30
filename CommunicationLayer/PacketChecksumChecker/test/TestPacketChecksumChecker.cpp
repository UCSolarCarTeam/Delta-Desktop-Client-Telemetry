#include <QCoreApplication>
#include <QSignalSpy>
#include "TestPacketChecksumChecker.h"
QTEST_MAIN(TestPacketChecksumChecker)

void TestPacketChecksumChecker::init()
{
   unstuffer_.reset(new FakePacketUnstuffer);
   patient_.reset(new PacketChecksumChecker(*unstuffer_));
}

void TestPacketChecksumChecker::cleanup()
{
   patient_.reset();
   unstuffer_.reset();
}

void TestPacketChecksumChecker::willValidateChecksumOfPacket()
{
   QFETCH(QByteArray, unstuffedData);

   QSignalSpy spy(patient_.data(), SIGNAL(validDataReceived(QByteArray)));
   unstuffer_->emitPacketUnstuffed(unstuffedData);

   QCOMPARE(spy.count(), 1);
   QTEST(spy[0][0].toByteArray(), "expectedResult");
}

void TestPacketChecksumChecker::willValidateChecksumOfPacket_data()
{
   QTest::addColumn<QByteArray>("unstuffedData");
   QTest::addColumn<QByteArray>("expectedResult");
   {
      QByteArray test("Batman");
      QTest::newRow("data Batman") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("123456789");
      QTest::newRow("data 123456789") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("9jsdf83sda");
      QTest::newRow("data 9jsdf83sda") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("0000000000");
      QTest::newRow("data 0000000000") << calculateChecksumAndAddToData(test) << test;
   }
   {
      QByteArray test("U of C Solar Car team");
      QTest::newRow("data U of C Solar Car team") << calculateChecksumAndAddToData(test) << test;
   }
}

void TestPacketChecksumChecker::willNotValidateIfChecksumIsIncorrect()
{
   QByteArray unstuffedData(calculateChecksumAndAddToData(QByteArray("123456789")));
   ++unstuffedData.data()[unstuffedData.size() - 1];

   QSignalSpy spy(patient_.data(), SIGNAL(validDataReceived(QByteArray)));
   unstuffer_->emitPacketUnstuffed(unstuffedData);

   QCOMPARE(spy.count(), 0);
}

QByteArray TestPacketChecksumChecker::calculateChecksumAndAddToData(const QByteArray& data)
{
   quint16 checksum =  qChecksum(data.constData(), data.size());
   QByteArray dataWithChecksum(data);
   dataWithChecksum.append(checksum & 0xFF);
   dataWithChecksum.append((checksum >> 8) & 0xFF);
   return dataWithChecksum;
}

#include "TestDataParser.h"
#include <QSignalSpy>

QTEST_MAIN(TestDataParser)


TestDataParser::TestDataParser()
{
}

void TestDataParser::init()
{
   connection_.reset(new FakeConnectionService);
   device_.reset(new QBuffer);
   patient_.reset(new DataParser(device_, connection_));
}

void TestDataParser::cleanup()
{
   connection_.reset();
   device_.reset();
   patient_.reset();
}


void TestDataParser::willEmitDataReceived()
{
   QSignalSpy spy(patient_, SIGNAL(dataReceived(id, value)));

   connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
                                                   //DataParser should now run connectionOK()
   device_->write("#01817");

   QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly one time

   QList<QVariant> signalReturn = spy.takeFirst();
   QVERIFY(signalReturn.at(0).toInt() == 01); // verify the id;
   QVERIFY(signalReturn.at(1).toInt() == 817); // verify the id;
}

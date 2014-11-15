#include "TestDataParser.h"
#include <QSignalSpy>
#include <QDebug>

QTEST_MAIN(TestDataParser)

/*Cases to Test:
 *    1) Perfect Condition
 *    2) More than 1 "#"
 *    3) No "#"
 *    4) No ascii numbers
 *    5) no emitSignalConnectionSucceeded
 *    6) Invalid chars
 */

TestDataParser::TestDataParser()
{
}

void TestDataParser::init()
{
   connection_.reset(new FakeConnectionService);
   device_.reset(new QBuffer);
   patient_.reset(new DataParser(*device_, *connection_));
}

void TestDataParser::cleanup()
{
   connection_.reset();
   device_.reset();
   patient_.reset();
}



/**
 * Test Condition:       Given a valid transmission
 * Appropriate Response: Should Emit dataReceived
 */
void TestDataParser::willEmitDataReceived()
{
   QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
   connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
   QTest::qWait(1);                                //DataParser should now run connectionOK()

   QFETCH(QString, transmission);
   QFETCH(int, id);
   QFETCH(int, value);
   device_->open(QIODevice::ReadWrite);
   device_->setTextModeEnabled(true);
   device_->write(transmission.toLocal8Bit());
   QTest::qWait(1); // These waits are needed when dealing with
                    // signals and slots. Whenever you want
                    // a signal and slot to perform you need a qWait in tests.

   QCOMPARE(spy.count(), 1); //check dataParser sent dataReceived
   QList<QVariant> signalReturn = spy.takeFirst();
   QCOMPARE(signalReturn.at(0).toInt(), id); // verify the id;
   QCOMPARE(signalReturn.at(1).toInt(), value); // verify the value;
}
void TestDataParser::willEmitDataReceived_data()
{
   QTest::addColumn<QString>("transmission");
   QTest::addColumn<int>("id");
   QTest::addColumn<int>("value");

   QTest::newRow("Perfect1") << "#01817\n"      << 01 << 817;
   QTest::newRow("Perfect2") << "#01-999\n"      << 01 << -999;
   QTest::newRow("Perfect3") << "#99999\n"      << 99 << 999;
   QTest::newRow("Perfect4") << "#0056\n"       << 00 << 56;
   QTest::newRow("Perfect5") << "#255667889\n"  << 25 << 5667889;
}


/**
 * Test Condition:       Given a transmission with more than one "#"
 * Appropriate Response: Should ignore the line with more than one "#"
 */
void TestDataParser::moreThanOneHash()
{
    QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
    connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
    QTest::qWait(1);                                //DataParser should now run connectionOK()

    QFETCH(QString, transmission);
    device_->open(QIODevice::ReadWrite);
    device_->setTextModeEnabled(true);
    device_->write(transmission.toLocal8Bit());
    QTest::qWait(1); // These waits are needed when dealing with
                     // signals and slots. Whenever you want
                     // a signal and slot to perform you need a qWait in tests.

    QCOMPARE(spy.count(), 0); //check dataParser sent dataReceived
}
void TestDataParser::moreThanOneHash_data()
{
    QTest::addColumn<QString>("transmission");

    QTest::newRow("MoreHash1") << "##01817\n";
    QTest::newRow("MoreHash2") << "#0#-999\n";
    QTest::newRow("MoreHash3") << "#999#9\n";
    QTest::newRow("MoreHash4") << "#00#6\n";
    QTest::newRow("MoreHash5") << "####255667889##\n";
}



/**
 * Test Condition:       Given a transmission with no "#"
 * Appropriate Response: Should ignore the line with no "#"
 */
void TestDataParser::noHash()
{
    QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
    connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
    QTest::qWait(1);                                //DataParser should now run connectionOK()

    QFETCH(QString, transmission);
    device_->open(QIODevice::ReadWrite);
    device_->setTextModeEnabled(true);
    device_->write(transmission.toLocal8Bit());
    QTest::qWait(1); // These waits are needed when dealing with
                     // signals and slots. Whenever you want
                     // a signal and slot to perform you need a qWait in tests.

    QCOMPARE(spy.count(), 0); //check dataParser sent dataReceived
}
void TestDataParser::noHash_data()
{
    QTest::addColumn<QString>("transmission");

    QTest::newRow("NoHash") << "01817\n";
}



/**
 * Test Condition:       Given a transmission with no ASCII numbers
 * Appropriate Response: Should ignore the line with no ASCII numbers
 */
void TestDataParser::noASCIINumbers()
{
    QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
    connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
    QTest::qWait(1);                                //DataParser should now run connectionOK()

    QFETCH(QString, transmission);
    device_->open(QIODevice::ReadWrite);
    device_->setTextModeEnabled(true);
    device_->write(transmission.toLocal8Bit());
    QTest::qWait(1); // These waits are needed when dealing with
                     // signals and slots. Whenever you want
                     // a signal and slot to perform you need a qWait in tests.

    QCOMPARE(spy.count(), 0); //check dataParser sent dataReceived
}
void TestDataParser::noASCIINumbers_data()
{
    QTest::addColumn<QString>("transmission");

    QTest::newRow("NoASCII") << "#";
}



/**
 * Test Condition:       Given a transmission with no emitSignalConnectionSucceeded
 * Appropriate Response: Should ignore the line with no emitSignalConnectionSucceeded
 */
void TestDataParser::noEmitSignalConnectionSucceeded()
{
    QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
    QTest::qWait(1);                                //DataParser should now run connectionOK()

    QFETCH(QString, transmission);
    device_->open(QIODevice::ReadWrite);
    device_->setTextModeEnabled(true);
    device_->write(transmission.toLocal8Bit());
    QTest::qWait(1); // These waits are needed when dealing with
                     // signals and slots. Whenever you want
                     // a signal and slot to perform you need a qWait in tests.

    QCOMPARE(spy.count(), 0); //check dataParser sent dataReceived
}
void TestDataParser::noEmitSignalConnectionSucceeded_data()
{
    QTest::addColumn<QString>("transmission");

    QTest::newRow("NoSucced") << "#01817\n";
}



/**
 * Test Condition:       Given a transmission with invalid chars
 * Appropriate Response: Should ignore the line with invalid chars
 */
void TestDataParser::invalidChars()
{
    QSignalSpy spy(patient_.data(), SIGNAL(dataReceived(int, int)));
    connection_->emitSignalConnectionSucceeded();   //emits the "connectionSucceeded()" signal
    QTest::qWait(1);                                //DataParser should now run connectionOK()

    QFETCH(QString, transmission);
    device_->open(QIODevice::ReadWrite);
    device_->setTextModeEnabled(true);
    device_->write(transmission.toLocal8Bit());
    QTest::qWait(1); // These waits are needed when dealing with
                     // signals and slots. Whenever you want
                     // a signal and slot to perform you need a qWait in tests.

    QCOMPARE(spy.count(), 0); //check dataParser sent dataReceived
}
void TestDataParser::invalidChars_data()
{
    QTest::addColumn<QString>("transmission");

    QTest::newRow("InvalidChars1") << "#j1817\n";
    QTest::newRow("InvalidChars2") << "#j!-999\n";
    QTest::newRow("InvalidChars3") << "#99j9\n";
    QTest::newRow("InvalidChars4") << "#00j!\n";
    QTest::newRow("InvalidChars5") << "#jjjj\n";
}

/*
void TestDataParser::willNotEmitDataReceivedMoreThanOneHash()
{
   QSignalSpy spy(patient_, SIGNAL(dataReceived(id, value)));

   connection_->emitSignalConnectionSucceeded();


}
*/


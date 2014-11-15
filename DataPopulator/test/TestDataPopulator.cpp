#include "TestDataPopulator.h"
#include <QSignalSpy>
#include <QDebug>
typedef int (TelemetryData::*GetterFunctionInt)() const;
typedef double (TelemetryData::*GetterFunctionDouble)() const;
QTEST_MAIN(TestDataPopulator)
Q_DECLARE_METATYPE(GetterFunctionInt)
Q_DECLARE_METATYPE(GetterFunctionDouble)
/*Cases to Test:
 *    1) Perfect Condition
 *    2) More than 1 "#"
 *    3) No "#"
 *    4) No ascii numbers
 *    5) no emitSignalConnectionSucceeded
 *    6) Invalid chars
 */
TestDataPopulator::TestDataPopulator()
{
    //qRegisterMetaType("GetterFunctionInt");
    //qRegisterMetaType("GetterFunctionDouble");
}

void TestDataPopulator::init()
{
   dataParser_.reset(new FakeDataParser);
   telemetry_.reset(new TelemetryData);
   patient_.reset(new DataPopulator(*dataParser_ , *telemetry_));
}

void TestDataPopulator::cleanup()
{
   dataParser_.reset();
   telemetry_.reset();
   patient_.reset();
}
void TestDataPopulator::functionTestsInt()
{
    int value = qrand();
    QFETCH(int,id);
    dataParser_->emitDataReceiver(id,value);

    QFETCH(GetterFunctionInt,function);
    QCOMPARE((telemetry_.data()->*function)(), value);
}
void TestDataPopulator::functionTestsInt_data()
{
    QTest::addColumn<int>("id");
    QTest::addColumn<GetterFunctionInt>("function");

    QTest::newRow("mod0PCBTemperature") << 15 << &TelemetryData::mod0PcbTemperature;
}
void TestDataPopulator::functionTestsDouble()
{
    double value = ((double)qrand()/(double)RAND_MAX);
    QFETCH(int,id);
    dataParser_->emitDataReceiver(id,value*1000);

    QFETCH(GetterFunctionDouble,function);
    qFuzzyCompare((telemetry_.data()->*function)(), value);
}
void TestDataPopulator::functionTestsDouble_data()
{
    QTest::addColumn<int>("id");
    QTest::addColumn<GetterFunctionDouble>("function");

    QTest::newRow("driverSetSpeedRPM") << 1 << &TelemetryData::driverSetSpeedRPM;
}


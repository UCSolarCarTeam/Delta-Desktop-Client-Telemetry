#include "TestDataPopulator.h"
#include <QSignalSpy>
#include <QDebug>
typedef int (TelemetryData::*GetterFunctionInt)() const;
typedef double (TelemetryData::*GetterFunctionDouble)() const;
QTEST_MAIN(TestDataPopulator)
Q_DECLARE_METATYPE(GetterFunctionInt)
Q_DECLARE_METATYPE(GetterFunctionDouble)

#define FUZZY_COMPARE(actual, expected, epsilon) \
{\
    QVERIFY(qAbs(actual - expected) <= epsilon);\
}

TestDataPopulator::TestDataPopulator()
{
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

void TestDataPopulator::functionTestsDouble()
{
    double value = ((double)qrand() / (double)RAND_MAX);
    QFETCH(int,id);
    dataParser_->emitDataReceiver(id, value);

    QFETCH(GetterFunctionDouble, function);
    FUZZY_COMPARE((telemetry_.data()->*function)(), value, 0.001);
}
void TestDataPopulator::functionTestsDouble_data()
{
    QTest::addColumn<int>("id");
    QTest::addColumn<GetterFunctionDouble>("function");

    QTest::newRow("driverSetSpeedRPM") << 0 << &TelemetryData::driverSetSpeedRPM;
    QTest::newRow("driverSetCurrent") << 1 << &TelemetryData::driverSetCurrent;
    QTest::newRow("vehicleVelocityKph") << 2 << &TelemetryData::vehicleVelocityKph;
    QTest::newRow("busCurrentA") << 3 << &TelemetryData::busCurrentA;
    QTest::newRow("busVoltage") << 4 << &TelemetryData::busVoltage;
    QTest::newRow("motorVelocityRpm") << 5 << &TelemetryData::motorVelocityRpm;
    QTest::newRow("motorVoltageReal") << 6 << &TelemetryData::motorVoltageReal;
    QTest::newRow("motorCurrentReal") << 7 << &TelemetryData::motorCurrentReal;
    QTest::newRow("backEmfImaginary") << 8 << &TelemetryData::backEmfImaginary;
    QTest::newRow("ipmHeatSinkTemp") << 9 << &TelemetryData::ipmHeatSinkTemp;
    QTest::newRow("dspBoardTemp") << 10 << &TelemetryData::dspBoardTemp;
    QTest::newRow("dcBusAmpHours") << 11 << &TelemetryData::dcBusAmpHours;

    QTest::newRow("receivedErrorCount") << 12 << &TelemetryData::receivedErrorCount;
    QTest::newRow("transmittedErrorCount") << 13 << &TelemetryData::transmittedErrorCount;
    QTest::newRow("mod0PCBTemperature") << 14 << &TelemetryData::mod0PcbTemperature;
    QTest::newRow("mod0CellTemperature") << 15 << &TelemetryData::mod0CellTemperature;
    QTest::newRow("mod0CellVoltage0") << 16 << &TelemetryData::mod0CellVoltage0;
    QTest::newRow("mod0CellVoltage1") << 17 << &TelemetryData::mod0CellVoltage1;
    QTest::newRow("mod0CellVoltage2") << 18 << &TelemetryData::mod0CellVoltage2;
    QTest::newRow("mod0CellVoltage3") << 19 << &TelemetryData::mod0CellVoltage3;
    QTest::newRow("mod0CellVoltage4") << 20 << &TelemetryData::mod0CellVoltage4;
    QTest::newRow("mod0CellVoltage5") << 21 << &TelemetryData::mod0CellVoltage5;
    QTest::newRow("mod0CellVoltage6") << 22 << &TelemetryData::mod0CellVoltage6;
    QTest::newRow("mod0CellVoltage7") << 23 << &TelemetryData::mod0CellVoltage7;

    QTest::newRow("mod1PCBTemperature") << 24 << &TelemetryData::mod1PcbTemperature;
    QTest::newRow("mod1CellTemperature") << 25 << &TelemetryData::mod1CellTemperature;
    QTest::newRow("mod1CellVoltage0") << 26 << &TelemetryData::mod1CellVoltage0;
    QTest::newRow("mod1CellVoltage1") << 27 << &TelemetryData::mod1CellVoltage1;
    QTest::newRow("mod1CellVoltage2") << 28 << &TelemetryData::mod1CellVoltage2;
    QTest::newRow("mod1CellVoltage3") << 29 << &TelemetryData::mod1CellVoltage3;
    QTest::newRow("mod1CellVoltage4") << 30 << &TelemetryData::mod1CellVoltage4;
    QTest::newRow("mod1CellVoltage5") << 31 << &TelemetryData::mod1CellVoltage5;
    QTest::newRow("mod1CellVoltage6") << 32 << &TelemetryData::mod1CellVoltage6;
    QTest::newRow("mod1CellVoltage7") << 33 << &TelemetryData::mod1CellVoltage7;

    QTest::newRow("mod2PCBTemperature") << 34 << &TelemetryData::mod2PcbTemperature;
    QTest::newRow("mod2CellTemperature") << 35 << &TelemetryData::mod2CellTemperature;
    QTest::newRow("mod2CellVoltage0") << 36 << &TelemetryData::mod2CellVoltage0;
    QTest::newRow("mod2CellVoltage1") << 37 << &TelemetryData::mod2CellVoltage1;
    QTest::newRow("mod2CellVoltage2") << 38 << &TelemetryData::mod2CellVoltage2;
    QTest::newRow("mod2CellVoltage3") << 39 << &TelemetryData::mod2CellVoltage3;
    QTest::newRow("mod2CellVoltage4") << 40 << &TelemetryData::mod2CellVoltage4;
    QTest::newRow("mod2CellVoltage5") << 41 << &TelemetryData::mod2CellVoltage5;
    QTest::newRow("mod2CellVoltage6") << 42 << &TelemetryData::mod2CellVoltage6;
    QTest::newRow("mod2CellVoltage7") << 43 << &TelemetryData::mod2CellVoltage7;

    QTest::newRow("mod3PCBTemperature") << 44 << &TelemetryData::mod3PcbTemperature;
    QTest::newRow("mod3CellTemperature") << 45 << &TelemetryData::mod3CellTemperature;
    QTest::newRow("mod3CellVoltage0") << 46 << &TelemetryData::mod3CellVoltage0;
    QTest::newRow("mod3CellVoltage1") << 47 << &TelemetryData::mod3CellVoltage1;
    QTest::newRow("mod3CellVoltage2") << 48 << &TelemetryData::mod3CellVoltage2;
    QTest::newRow("mod3CellVoltage3") << 49 << &TelemetryData::mod3CellVoltage3;
    QTest::newRow("mod3CellVoltage4") << 50 << &TelemetryData::mod3CellVoltage4;
    QTest::newRow("mod3CellVoltage5") << 51 << &TelemetryData::mod3CellVoltage5;
    QTest::newRow("mod3CellVoltage6") << 52 << &TelemetryData::mod3CellVoltage6;
    QTest::newRow("mod3CellVoltage7") << 53 << &TelemetryData::mod3CellVoltage7;

    QTest::newRow("batteryVoltage") << 54 << &TelemetryData::batteryVoltage;
    QTest::newRow("batteryCurrent") << 55 << &TelemetryData::batteryCurrent;
    QTest::newRow("batteryVoltageThresholdRising") << 56 << &TelemetryData::batteryVoltageThresholdRising;
    QTest::newRow("batteryVoltageThresholdFalling") << 57 << &TelemetryData::batteryVoltageThresholdFalling;
}




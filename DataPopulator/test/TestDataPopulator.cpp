#include "TestDataPopulator.h"
#include <QSignalSpy>
#include <QDebug>
typedef int (TelemetryData::*GetterFunctionInt)() const;
typedef double (TelemetryData::*GetterFunctionDouble)() const;
QTEST_MAIN(TestDataPopulator)
Q_DECLARE_METATYPE(GetterFunctionInt)
Q_DECLARE_METATYPE(GetterFunctionDouble)


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
    QTest::newRow("mod0CellTemperature") << 16 << &TelemetryData::mod0CellTemperature;
    QTest::newRow("mod0CellVoltage0") << 17 << &TelemetryData::mod0CellVoltage0;
    QTest::newRow("mod0CellVoltage1") << 18 << &TelemetryData::mod0CellVoltage1;
    QTest::newRow("mod0CellVoltage2") << 19 << &TelemetryData::mod0CellVoltage2;
    QTest::newRow("mod0CellVoltage3") << 20 << &TelemetryData::mod0CellVoltage3;
    QTest::newRow("mod0CellVoltage4") << 21 << &TelemetryData::mod0CellVoltage4;
    QTest::newRow("mod0CellVoltage5") << 22 << &TelemetryData::mod0CellVoltage5;
    QTest::newRow("mod0CellVoltage6") << 23 << &TelemetryData::mod0CellVoltage6;
    QTest::newRow("mod0CellVoltage7") << 24 << &TelemetryData::mod0CellVoltage7;
    QTest::newRow("mod1PCBTemperature") << 25 << &TelemetryData::mod1PcbTemperature;
    QTest::newRow("mod1CellTemperature") << 26 << &TelemetryData::mod1CellTemperature;
    QTest::newRow("mod1CellVoltage0") << 27 << &TelemetryData::mod1CellVoltage0;
    QTest::newRow("mod1CellVoltage1") << 28 << &TelemetryData::mod1CellVoltage1;
    QTest::newRow("mod1CellVoltage2") << 29 << &TelemetryData::mod1CellVoltage2;
    QTest::newRow("mod1CellVoltage3") << 30 << &TelemetryData::mod1CellVoltage3;
    QTest::newRow("mod1CellVoltage4") << 31 << &TelemetryData::mod1CellVoltage4;
    QTest::newRow("mod1CellVoltage5") << 32 << &TelemetryData::mod1CellVoltage5;
    QTest::newRow("mod1CellVoltage6") << 33 << &TelemetryData::mod1CellVoltage6;
    QTest::newRow("mod1CellVoltage7") << 34 << &TelemetryData::mod1CellVoltage7;
    QTest::newRow("mod2PCBTemperature") << 35 << &TelemetryData::mod2PcbTemperature;
    QTest::newRow("mod2CellTemperature") << 36 << &TelemetryData::mod2CellTemperature;
    QTest::newRow("mod2CellVoltage0") << 37 << &TelemetryData::mod2CellVoltage0;
    QTest::newRow("mod2CellVoltage1") << 38 << &TelemetryData::mod2CellVoltage1;
    QTest::newRow("mod2CellVoltage2") << 39 << &TelemetryData::mod2CellVoltage2;
    QTest::newRow("mod2CellVoltage3") << 40 << &TelemetryData::mod2CellVoltage3;
    QTest::newRow("mod2CellVoltage4") << 41 << &TelemetryData::mod2CellVoltage4;
    QTest::newRow("mod2CellVoltage5") << 42 << &TelemetryData::mod2CellVoltage5;
    QTest::newRow("mod2CellVoltage6") << 43 << &TelemetryData::mod2CellVoltage6;
    QTest::newRow("mod2CellVoltage7") << 44 << &TelemetryData::mod2CellVoltage7;
    QTest::newRow("mod3PCBTemperature") << 45 << &TelemetryData::mod3PcbTemperature;
    QTest::newRow("mod3CellTemperature") << 46 << &TelemetryData::mod3CellTemperature;
    QTest::newRow("mod3CellVoltage0") << 47 << &TelemetryData::mod3CellVoltage0;
    QTest::newRow("mod3CellVoltage1") << 48 << &TelemetryData::mod3CellVoltage1;
    QTest::newRow("mod3CellVoltage2") << 49 << &TelemetryData::mod3CellVoltage2;
    QTest::newRow("mod3CellVoltage3") << 50 << &TelemetryData::mod3CellVoltage3;
    QTest::newRow("mod3CellVoltage4") << 51 << &TelemetryData::mod3CellVoltage4;
    QTest::newRow("mod3CellVoltage5") << 52 << &TelemetryData::mod3CellVoltage5;
    QTest::newRow("mod3CellVoltage6") << 53 << &TelemetryData::mod3CellVoltage6;
    QTest::newRow("mod3CellVoltage7") << 54 << &TelemetryData::mod3CellVoltage7;
    QTest::newRow("batteryVoltage") << 55 << &TelemetryData::batteryVoltage;
    QTest::newRow("batteryCurrent") << 56 << &TelemetryData::batteryCurrent;
    QTest::newRow("batteryVoltageThresholdRising") << 57 << &TelemetryData::batteryVoltageThresholdRising;
    QTest::newRow("batteryVoltageThresholdFalling") << 58 << &TelemetryData::batteryVoltageThresholdFalling;
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
    QTest::newRow("driverSetCurrent") << 2 << &TelemetryData::driverSetCurrent;
    QTest::newRow("vehicleVelocityKph") << 3 << &TelemetryData::vehicleVelocityKph;
    QTest::newRow("busCurrentA") << 4 << &TelemetryData::busCurrentA;
    QTest::newRow("busVoltage") << 5 << &TelemetryData::busVoltage;
    QTest::newRow("motorVelocityRpm") << 6 << &TelemetryData::motorVelocityRpm;
    QTest::newRow("motorVoltageReal") << 7 << &TelemetryData::motorVoltageReal;
    QTest::newRow("motorCurrentReal") << 8 << &TelemetryData::motorCurrentReal;
    QTest::newRow("backEmfImaginary") << 9 << &TelemetryData::backEmfImaginary;
    QTest::newRow("ipmHeatSinkTemp") << 10 << &TelemetryData::ipmHeatSinkTemp;
    QTest::newRow("dspBoardTemp") << 11 << &TelemetryData::dspBoardTemp;
    QTest::newRow("dcBusAmpHours") << 12 << &TelemetryData::dcBusAmpHours;
    QTest::newRow("receivedErrorCount") << 13 << &TelemetryData::receivedErrorCount;
    QTest::newRow("transmittedErrorCount") << 14 << &TelemetryData::transmittedErrorCount;
}


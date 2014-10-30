#include "SolarCarTestUI.h"
#include "ui_SolarCarTestUI.h"

SolarCarTestUI::SolarCarTestUI(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::SolarCarTestUI)
{
   ui->setupUi(this);
}

SolarCarTestUI::~SolarCarTestUI()
{
   delete ui;
}

QLCDNumber& SolarCarTestUI::setDriverSetSpeedRPM()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setDriverSetCurrent()
{
    return *ui->driverSetCurrentValue;
}


QLCDNumber& SolarCarTestUI::setVehicleVelocityKph()
{
    return *ui->vehicleVelocityKphValue;
}

QLCDNumber& SolarCarTestUI::setBusCurrentA()
{
    return *ui->busVoltageValue;
}

QLCDNumber& SolarCarTestUI::setBusVoltage()
{
    return *ui->busVoltageValue;
}

//QLCDNumber& SolarCarTestUI::setMotorVelocityRpm()
//{

//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setMotorVoltageReal()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setMotorCurrentReal()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setBackEmfImaginary()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setIpmHeatSinkTemp()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setDspBoardTemp()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setDcBusAmpHours()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setReceivedErrorCount()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setTransmittedErrorCount()
//{
//    return *ui->driverSetSpeedValue;
//}


QLCDNumber& SolarCarTestUI::setMod0PcbTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage0()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage1()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage2()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage3()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage4()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage5()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage6()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage7()
{
    return *ui->driverSetSpeedValue;
}


QLCDNumber& SolarCarTestUI::setMod1PcbTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage0()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage1()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage2()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage3()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage4()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage5()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage6()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage7()
{
    return *ui->driverSetSpeedValue;
}


QLCDNumber& SolarCarTestUI::setMod2PcbTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage0()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage1()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage2()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage3()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage4()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage5()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage6()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage7()
{
    return *ui->driverSetSpeedValue;
}


QLCDNumber& SolarCarTestUI::setMod3PcbTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellTemperature()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage0()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage1()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage2()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage3()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage4()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage5()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage6()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage7()
{
    return *ui->driverSetSpeedValue;
}


QLCDNumber& SolarCarTestUI::setBatteryVoltage()
{
    return *ui->driverSetSpeedValue;
}

QLCDNumber& SolarCarTestUI::setBatteryCurrent()
{
    return *ui->driverSetSpeedValue;
}

//QLCDNumber& SolarCarTestUI::setBatteryVoltageThresholdRising()
//{
//    return *ui->driverSetSpeedValue;
//}

//QLCDNumber& SolarCarTestUI::setBatteryVoltageThresholdFalling()
//{
//    return *ui->driverSetSpeedValue;
//}


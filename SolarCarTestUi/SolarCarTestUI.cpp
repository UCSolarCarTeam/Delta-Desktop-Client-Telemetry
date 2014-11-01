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

//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setMotorVoltageReal()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setMotorCurrentReal()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setBackEmfImaginary()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setIpmHeatSinkTemp()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setDspBoardTemp()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setDcBusAmpHours()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setReceivedErrorCount()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setTransmittedErrorCount()
//{
//   return *ui->NONEXISTENTLABEL;
//}

/*---------mod0---------*/
QLCDNumber& SolarCarTestUI::setMod0PcbTemperature()
{
   return *ui->mod0PcbTemperatureValue;
}

//QLCDNumber& SolarCarTestUI::setMod0CellTemperature()
//{
//   return *ui->NONEXISTENTLABEL;
//}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage0()
{
   return *ui->mod0CellVoltage0Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage1()
{
   return *ui->mod0CellVoltage1Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage2()
{
   return *ui->mod0CellVoltage2Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage3()
{
   return *ui->mod0CellVoltage3Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage4()
{
   return *ui->mod0CellVoltage4Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage5()
{
   return *ui->mod0CellVoltage5Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage6()
{
   return *ui->mod0CellVoltage6Value;
}

QLCDNumber& SolarCarTestUI::setMod0CellVoltage7()
{
   return *ui->mod0CellVoltage7Value;
}

/*---------mod1---------*/
QLCDNumber& SolarCarTestUI::setMod1PcbTemperature()
{
   return *ui->mod1PcbTemperatureValue;
}

//QLCDNumber& SolarCarTestUI::setMod1CellTemperature()
//{
//   return *ui->NONEXISTENTLABEL;
//}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage0()
{
   return *ui->mod1CellVoltage0Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage1()
{
   return *ui->mod1CellVoltage1Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage2()
{
   return *ui->mod1CellVoltage2Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage3()
{
   return *ui->mod1CellVoltage3Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage4()
{
   return *ui->mod1CellVoltage4Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage5()
{
   return *ui->mod1CellVoltage5Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage6()
{
   return *ui->mod1CellVoltage6Value;
}

QLCDNumber& SolarCarTestUI::setMod1CellVoltage7()
{
   return *ui->mod1CellVoltage7Value;
}

/*---------mod2---------*/
QLCDNumber& SolarCarTestUI::setMod2PcbTemperature()
{
   return *ui->mod2PcbTemperatureValue;
}

//QLCDNumber& SolarCarTestUI::setMod2CellTemperature()
//{
//   return *ui->NONEXISTENTLABEL;
//}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage0()
{
   return *ui->mod2CellVoltage0Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage1()
{
   return *ui->mod2CellVoltage1Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage2()
{
   return *ui->mod2CellVoltage2Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage3()
{
   return *ui->mod2CellVoltage3Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage4()
{
   return *ui->mod2CellVoltage4Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage5()
{
   return *ui->mod2CellVoltage5Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage6()
{
   return *ui->mod2CellVoltage6Value;
}

QLCDNumber& SolarCarTestUI::setMod2CellVoltage7()
{
   return *ui->mod2CellVoltage7Value;
}

/*---------mod3---------*/
QLCDNumber& SolarCarTestUI::setMod3PcbTemperature()
{
   return *ui->mod3PcbTemperatureValue;
}

//QLCDNumber& SolarCarTestUI::setMod3CellTemperature()
//{
//   return *ui->NONEXISTENTLABEL;
//}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage0()
{
   return *ui->mod3CellVoltage0Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage1()
{
   return *ui->mod3CellVoltage1Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage2()
{
   return *ui->mod3CellVoltage2Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage3()
{
   return *ui->mod3CellVoltage3Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage4()
{
   return *ui->mod3CellVoltage4Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage5()
{
   return *ui->mod3CellVoltage5Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage6()
{
   return *ui->mod3CellVoltage6Value;
}

QLCDNumber& SolarCarTestUI::setMod3CellVoltage7()
{
   return *ui->mod3CellVoltage7Value;
}

QPushButton& SolarCarTestUI::connectButton()
{
   return *ui->connectButton; 
}


//QLCDNumber& SolarCarTestUI::setBatteryVoltage()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setBatteryCurrent()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setBatteryVoltageThresholdRising()
//{
//   return *ui->NONEXISTENTLABEL;
//}

//QLCDNumber& SolarCarTestUI::setBatteryVoltageThresholdFalling()
//{
//   return *ui->NONEXISTENTLABEL;
//}


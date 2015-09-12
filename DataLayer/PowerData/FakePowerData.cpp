#include "FakePowerData.h"

FakePowerData::FakePowerData()
{
}

FakePowerData::~FakePowerData()
{
}

/*FakePowerData "Gets"*/
double FakePowerData::busCurrentA() const
{
   return 1;
}
double FakePowerData::busVoltage() const
{
   return 2;
}
double FakePowerData::motorVoltageReal() const
{
   return 3;
}
double FakePowerData::motorCurrentReal() const
{
   return 4;
}
double FakePowerData::backEmfImaginary() const
{
   return 5;
}
double FakePowerData::dcBusAmpHours() const
{
   return 6;
}

/*FakePowerData "Sets"*/
void FakePowerData::setBusCurrentA(double busCurrentA){}
void FakePowerData::setBusVoltage(double busVoltage){}
void FakePowerData::setMotorVoltageReal(double motorVoltageReal){}
void FakePowerData::setMotorCurrentReal(double motorCurrentReal){}
void FakePowerData::setBackEmfImaginary(double backEmfImaginary){}
void FakePowerData::setDcBusAmpHours(double dcBusAmpHours){}
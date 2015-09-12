#include "PowerData.h"

PowerData::PowerData()
{
}

PowerData::~PowerData()
{
}

/*PowerData "Gets"*/
double PowerData::busCurrentA() const
{
   return busCurrentA_;
}
double PowerData::busVoltage() const
{
   return busVoltage_;
}
double PowerData::motorVoltageReal() const
{
   return motorVoltageReal_;
}
double PowerData::motorCurrentReal() const
{
   return motorCurrentReal_;
}
double PowerData::backEmfImaginary() const
{
   return backEmfImaginary_;
}
double PowerData::dcBusAmpHours() const
{
   return dcBusAmpHours_;
}

/*PowerData "Sets"*/
void PowerData::setBusCurrentA(double busCurrentA)
{
   busCurrentA_ = busCurrentA;
   emit busCurrentAReceived(busCurrentA_);
}
void PowerData::setBusVoltage(double busVoltage)
{
   busVoltage_ = busVoltage;
   emit busVoltageReceived(busVoltage_);
}
void PowerData::setMotorVoltageReal(double motorVoltageReal)
{
   motorVoltageReal_ = motorVoltageReal;
   emit motorVoltageRealReceived(motorVoltageReal_);
}
void PowerData::setMotorCurrentReal(double motorCurrentReal)
{
   motorCurrentReal_ = motorCurrentReal;
   emit motorCurrentRealReceived(motorCurrentReal_);
}
void PowerData::setBackEmfImaginary(double backEmfImaginary)
{
   backEmfImaginary_ = backEmfImaginary;
   emit backEmfImaginaryReceived(backEmfImaginary_);
}
void PowerData::setDcBusAmpHours(double dcBusAmpHours)
{
   dcBusAmpHours_ = dcBusAmpHours;
   emit dcBusAmpHoursReceived(dcBusAmpHours_);
}
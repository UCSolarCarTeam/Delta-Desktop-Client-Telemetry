#include "TelemetryData.h"
#include <stdio.h>

TelemetryData::TelemetryData()
{
}

TelemetryData::~TelemetryData()
{
}

double TelemetryData::driverSetSpeedRPM() const
{   
   return driverSetSpeedRPM_;
}

double TelemetryData::driverSetCurrent() const
{
   return driverSetCurrent_;
}

double TelemetryData::vehicleVelocityKph() const
{
   return vehicleVelocityKph_;
}
double TelemetryData::busCurrentA() const
{
   return busCurrentA_;
}
double TelemetryData::busVoltage() const
{
   return busVoltage_;
}
double TelemetryData::motorVelocityRpm() const
{
   return motorVelocityRpm_;
}
double TelemetryData::motorVoltageReal() const
{
   return motorVoltageReal_;
}
double TelemetryData::motorCurrentReal() const
{
   return motorCurrentReal_;
}
double TelemetryData::backEmfImaginary() const
{
   return backEmfImaginary_;
}
double TelemetryData::ipmHeatSinkTemp() const
{
   return ipmHeatSinkTemp_;
}
double TelemetryData::dspBoardTemp() const
{
   return dspBoardTemp_;
}
double TelemetryData::dcBusAmpHours() const
{
   return dcBusAmpHours_;
}
double TelemetryData::receivedErrorCount() const
{
   return receivedErrorCount_;
}
double TelemetryData::transmittedErrorCount() const
{
   return transmittedErrorCount_;
}

double TelemetryData::mod0PcbTemperature() const
{           
   return mod0PcbTemperature_;
}
double TelemetryData::mod0CellTemperature() const
{           
   return mod0CellTemperature_;
}
double TelemetryData::mod0CellVoltage0() const
{           
   return mod0CellVoltage0_;
}
double TelemetryData::mod0CellVoltage1() const
{           
   return mod0CellVoltage1_;
}
double TelemetryData::mod0CellVoltage2() const
{           
   return mod0CellVoltage2_;
}
double TelemetryData::mod0CellVoltage3() const
{           
   return mod0CellVoltage3_;
}
double TelemetryData::mod0CellVoltage4() const
{           
   return mod0CellVoltage4_;
}
double TelemetryData::mod0CellVoltage5() const
{           
   return mod0CellVoltage5_;
}
double TelemetryData::mod0CellVoltage6() const
{           
   return mod0CellVoltage6_;
}
double TelemetryData::mod0CellVoltage7() const
{           
   return mod0CellVoltage7_;
}

double TelemetryData::mod1PcbTemperature() const
{           
   return mod1PcbTemperature_;
}
double TelemetryData::mod1CellTemperature() const
{           
   return mod1CellTemperature_;
}
double TelemetryData::mod1CellVoltage0() const
{           
   return mod1CellVoltage0_;
}
double TelemetryData::mod1CellVoltage1() const
{           
   return mod1CellVoltage1_;
}
double TelemetryData::mod1CellVoltage2() const
{           
   return mod1CellVoltage2_;
}
double TelemetryData::mod1CellVoltage3() const
{           
   return mod1CellVoltage3_;
}
double TelemetryData::mod1CellVoltage4() const
{           
   return mod1CellVoltage4_;
}
double TelemetryData::mod1CellVoltage5() const
{           
   return mod1CellVoltage5_;
}
double TelemetryData::mod1CellVoltage6() const
{           
   return mod1CellVoltage6_;
}
double TelemetryData::mod1CellVoltage7() const
{           
   return mod1CellVoltage7_;
}

double TelemetryData::mod2PcbTemperature() const
{           
   return mod2PcbTemperature_;
}
double TelemetryData::mod2CellTemperature() const
{           
   return mod2CellTemperature_;
}
double TelemetryData::mod2CellVoltage0() const
{           
   return mod2CellVoltage0_;
}
double TelemetryData::mod2CellVoltage1() const
{           
   return mod2CellVoltage1_;
}
double TelemetryData::mod2CellVoltage2() const
{           
   return mod2CellVoltage2_;
}
double TelemetryData::mod2CellVoltage3() const
{           
   return mod2CellVoltage3_;
}
double TelemetryData::mod2CellVoltage4() const
{           
   return mod2CellVoltage4_;
}
double TelemetryData::mod2CellVoltage5() const
{           
   return mod2CellVoltage5_;
}
double TelemetryData::mod2CellVoltage6() const
{           
   return mod2CellVoltage6_;
}
double TelemetryData::mod2CellVoltage7() const
{           
   return mod2CellVoltage7_;
}

double TelemetryData::mod3PcbTemperature() const
{           
   return mod3PcbTemperature_;
}
double TelemetryData::mod3CellTemperature() const
{           
   return mod3CellTemperature_;
}
double TelemetryData::mod3CellVoltage0() const
{           
   return mod3CellVoltage0_;
}
double TelemetryData::mod3CellVoltage1() const
{           
   return mod3CellVoltage1_;
}
double TelemetryData::mod3CellVoltage2() const
{           
   return mod3CellVoltage2_;
}
double TelemetryData::mod3CellVoltage3() const
{           
   return mod3CellVoltage3_;
}
double TelemetryData::mod3CellVoltage4() const
{           
   return mod3CellVoltage4_;
}
double TelemetryData::mod3CellVoltage5() const
{           
   return mod3CellVoltage5_;
}
double TelemetryData::mod3CellVoltage6() const
{           
   return mod3CellVoltage6_;
}
double TelemetryData::mod3CellVoltage7() const
{           
   return mod3CellVoltage7_;
}

double TelemetryData::batteryVoltage() const
{           
   return batteryVoltage_;
}
double TelemetryData::batteryCurrent() const
{           
   return batteryCurrent_;
}
double TelemetryData::batteryVoltageThresholdRising() const
{           
   return batteryVoltageThresholdRising_;
}
double TelemetryData::batteryVoltageThresholdFalling() const
{           
   return batteryVoltageThresholdFalling_;
}

/************Solar Car Driver************/
void TelemetryData::setDriverSetSpeedRPM(double driverSetSpeedRPM)
{
   driverSetSpeedRPM_ = driverSetSpeedRPM;
   emit driverSetSpeedRPMReceived(driverSetSpeedRPM_);
}
void TelemetryData::setDriverSetCurrent(double driverSetCurrent)
{
   driverSetCurrent_ = driverSetCurrent;
   emit driverSetCurrentReceived(driverSetCurrent_);
}

/************Solar Car Readings************/
void TelemetryData::setVehicleVelocityKph(double vehicleVelocityKph)
{
   vehicleVelocityKph_ = vehicleVelocityKph;
   emit vehicleVelocityKphReceived(vehicleVelocityKph_);
}
void TelemetryData::setBusCurrentA(double busCurrentA)
{
   busCurrentA_ = busCurrentA;
   emit busCurrentAReceived(busCurrentA_);
}
void TelemetryData::setBusVoltage(double busVoltage)
{
   busVoltage_ = busVoltage;
   emit busVoltageReceived(busVoltage_);
}
void TelemetryData::setMotorVelocityRpm(double motorVelocityRpm)
{
   motorVelocityRpm_ = motorVelocityRpm;
   emit motorVelocityRpmReceived(motorVelocityRpm_);
}
void TelemetryData::setMotorVoltageReal(double motorVoltageReal)
{
   motorVoltageReal_ = motorVoltageReal;
   emit motorVoltageRealReceived(motorVoltageReal_);
}
void TelemetryData::setMotorCurrentReal(double motorCurrentReal)
{
   motorCurrentReal_ = motorCurrentReal;
   emit motorCurrentRealReceived(motorCurrentReal_);
}
void TelemetryData::setBackEmfImaginary(double backEmfImaginary)
{
   backEmfImaginary_ = backEmfImaginary;
   emit backEmfImaginaryReceived(backEmfImaginary_);
}
void TelemetryData::setIpmHeatSinkTemp(double ipmHeatSinkTemp)
{
   ipmHeatSinkTemp_ = ipmHeatSinkTemp;
   emit ipmHeatSinkTempReceived(ipmHeatSinkTemp_);
}
void TelemetryData::setDspBoardTemp(double dspBoardTemp)
{
   dspBoardTemp_ = dspBoardTemp;
   emit dspBoardTempReceived(dspBoardTemp_);
}
void TelemetryData::setDcBusAmpHours(double dcBusAmpHours)
{
   dcBusAmpHours_ = dcBusAmpHours;
   emit dcBusAmpHoursReceived(dcBusAmpHours_);
}
void TelemetryData::setReceivedErrorCount(double receivedErrorCount)
{
   receivedErrorCount_ = receivedErrorCount;
   emit receivedErrorCountReceived(receivedErrorCount_);
}
void TelemetryData::setTransmittedErrorCount(double transmittedErrorCount)
{
   transmittedErrorCount_ = transmittedErrorCount;
   emit transmittedErrorCountReceived(transmittedErrorCount_);
}

/************Battery Module 0************/
void TelemetryData::setMod0PcbTemperature(double mod0PcbTemperature)
{
   mod0PcbTemperature_ = mod0PcbTemperature;
   emit mod0PcbTemperatureReceived(mod0PcbTemperature_);
}
void TelemetryData::setMod0CellTemperature(double mod0CellTemperature)
{
   mod0CellTemperature_ = mod0CellTemperature;
   emit mod0CellTemperatureReceived(mod0CellTemperature_);
}
void TelemetryData::setMod0CellVoltage0(double mod0CellVoltage0)
{
   mod0CellVoltage0_ = mod0CellVoltage0;
   emit mod0CellVoltage0Received(mod0CellVoltage0_);
}
void TelemetryData::setMod0CellVoltage1(double mod0CellVoltage1)
{
   mod0CellVoltage1_ = mod0CellVoltage1;
   emit mod0CellVoltage1Received(mod0CellVoltage1_);
}
void TelemetryData::setMod0CellVoltage2(double mod0CellVoltage2)
{
   mod0CellVoltage2_ = mod0CellVoltage2;
   emit mod0CellVoltage2Received(mod0CellVoltage2_);
}
void TelemetryData::setMod0CellVoltage3(double mod0CellVoltage3)
{
   mod0CellVoltage3_ = mod0CellVoltage3;
   emit mod0CellVoltage3Received(mod0CellVoltage3_);
}
void TelemetryData::setMod0CellVoltage4(double mod0CellVoltage4)
{
   mod0CellVoltage4_ = mod0CellVoltage4;
   emit mod0CellVoltage4Received(mod0CellVoltage4_);
}
void TelemetryData::setMod0CellVoltage5(double mod0CellVoltage5)
{
   mod0CellVoltage5_ = mod0CellVoltage5;
   emit mod0CellVoltage5Received(mod0CellVoltage5_);
}
void TelemetryData::setMod0CellVoltage6(double mod0CellVoltage6)
{
   mod0CellVoltage6_ = mod0CellVoltage6;
   emit mod0CellVoltage6Received(mod0CellVoltage6_);
}
void TelemetryData::setMod0CellVoltage7(double mod0CellVoltage7)
{
   mod0CellVoltage7_ = mod0CellVoltage7;
   emit mod0CellVoltage7Received(mod0CellVoltage7_);
}

/************Battery Module 1************/
void TelemetryData::setMod1PcbTemperature(double mod1PcbTemperature)
{
   mod1PcbTemperature_ = mod1PcbTemperature;
   emit mod1PcbTemperatureReceived(mod1PcbTemperature_);
}
void TelemetryData::setMod1CellTemperature(double mod1CellTemperature)
{
   mod1CellTemperature_ = mod1CellTemperature;
   emit mod1CellTemperatureReceived(mod1CellTemperature_);
}
void TelemetryData::setMod1CellVoltage0(double mod1CellVoltage0)
{
   mod1CellVoltage0_ = mod1CellVoltage0;
   emit mod1CellVoltage0Received(mod1CellVoltage0_);
}
void TelemetryData::setMod1CellVoltage1(double mod1CellVoltage1)
{
   mod1CellVoltage1_ = mod1CellVoltage1;
   emit mod1CellVoltage1Received(mod1CellVoltage1_);
}
void TelemetryData::setMod1CellVoltage2(double mod1CellVoltage2)
{
   mod1CellVoltage2_ = mod1CellVoltage2;
   emit mod1CellVoltage2Received(mod1CellVoltage2_);
}
void TelemetryData::setMod1CellVoltage3(double mod1CellVoltage3)
{
   mod1CellVoltage3_ = mod1CellVoltage3;
   emit mod1CellVoltage3Received(mod1CellVoltage3_);
}
void TelemetryData::setMod1CellVoltage4(double mod1CellVoltage4)
{
   mod1CellVoltage4_ = mod1CellVoltage4;
   emit mod1CellVoltage4Received(mod1CellVoltage4_);
}
void TelemetryData::setMod1CellVoltage5(double mod1CellVoltage5)
{
   mod1CellVoltage5_ = mod1CellVoltage5;
   emit mod1CellVoltage5Received(mod1CellVoltage5_);
}
void TelemetryData::setMod1CellVoltage6(double mod1CellVoltage6)
{
   mod1CellVoltage6_ = mod1CellVoltage6;
   emit mod1CellVoltage6Received(mod1CellVoltage6_);
}
void TelemetryData::setMod1CellVoltage7(double mod1CellVoltage7)
{
   mod1CellVoltage7_ = mod1CellVoltage7;
   emit mod1CellVoltage7Received(mod1CellVoltage7_);
}

/************Battery Module 2************/
void TelemetryData::setMod2PcbTemperature(double mod2PcbTemperature)
{
   mod2PcbTemperature_ = mod2PcbTemperature;
   emit mod2PcbTemperatureReceived(mod2PcbTemperature_);
}
void TelemetryData::setMod2CellTemperature(double mod2CellTemperature)
{
   mod2CellTemperature_ = mod2CellTemperature;
   emit mod2CellTemperatureReceived(mod2CellTemperature_);
}
void TelemetryData::setMod2CellVoltage0(double mod2CellVoltage0)
{
   mod2CellVoltage0_ = mod2CellVoltage0;
   emit mod2CellVoltage0Received(mod2CellVoltage0_);
}
void TelemetryData::setMod2CellVoltage1(double mod2CellVoltage1)
{
   mod2CellVoltage1_ = mod2CellVoltage1;
   emit mod2CellVoltage1Received(mod2CellVoltage1_);
}
void TelemetryData::setMod2CellVoltage2(double mod2CellVoltage2)
{
   mod2CellVoltage2_ = mod2CellVoltage2;
   emit mod2CellVoltage2Received(mod2CellVoltage2_);
}
void TelemetryData::setMod2CellVoltage3(double mod2CellVoltage3)
{
   mod2CellVoltage3_ = mod2CellVoltage3;
   emit mod2CellVoltage3Received(mod2CellVoltage3_);
}
void TelemetryData::setMod2CellVoltage4(double mod2CellVoltage4)
{
   mod2CellVoltage4_ = mod2CellVoltage4;
   emit mod2CellVoltage4Received(mod2CellVoltage4_);
}
void TelemetryData::setMod2CellVoltage5(double mod2CellVoltage5)
{
   mod2CellVoltage5_ = mod2CellVoltage5;
   emit mod2CellVoltage5Received(mod2CellVoltage5_);
}
void TelemetryData::setMod2CellVoltage6(double mod2CellVoltage6)
{
   mod2CellVoltage6_ = mod2CellVoltage6;
   emit mod2CellVoltage6Received(mod2CellVoltage6_);
}
void TelemetryData::setMod2CellVoltage7(double mod2CellVoltage7)
{
   mod2CellVoltage7_ = mod2CellVoltage7;
   emit mod2CellVoltage7Received(mod2CellVoltage7_);
}

/************Battery Module 3************/
void TelemetryData::setMod3PcbTemperature(double mod3PcbTemperature)
{
   mod3PcbTemperature_ = mod3PcbTemperature;
   emit mod3PcbTemperatureReceived(mod3PcbTemperature_);
}

void TelemetryData::setMod3CellTemperature(double mod3CellTemperature)
{
   mod3CellTemperature_ = mod3CellTemperature;
   emit mod3CellTemperatureReceived(mod3CellTemperature_);
}
void TelemetryData::setMod3CellVoltage0(double mod3CellVoltage0)
{
   mod3CellVoltage0_ = mod3CellVoltage0;
   emit mod3CellVoltage0Received(mod3CellVoltage0_);
}
void TelemetryData::setMod3CellVoltage1(double mod3CellVoltage1)
{
   mod3CellVoltage1_ = mod3CellVoltage1;
   emit mod3CellVoltage1Received(mod3CellVoltage1_);
}
void TelemetryData::setMod3CellVoltage2(double mod3CellVoltage2)
{
   mod3CellVoltage2_ = mod3CellVoltage2;
   emit mod3CellVoltage2Received(mod3CellVoltage2_);
}
void TelemetryData::setMod3CellVoltage3(double mod3CellVoltage3)
{
   mod3CellVoltage3_ = mod3CellVoltage3;
   emit mod3CellVoltage3Received(mod3CellVoltage3_);
}
void TelemetryData::setMod3CellVoltage4(double mod3CellVoltage4)
{
   mod3CellVoltage4_ = mod3CellVoltage4;
   emit mod3CellVoltage4Received(mod3CellVoltage4_);
}
void TelemetryData::setMod3CellVoltage5(double mod3CellVoltage5)
{
   mod3CellVoltage5_ = mod3CellVoltage5;
   emit mod3CellVoltage5Received(mod3CellVoltage5_);
}
void TelemetryData::setMod3CellVoltage6(double mod3CellVoltage6)
{
   mod3CellVoltage6_ = mod3CellVoltage6;
   emit mod3CellVoltage6Received(mod3CellVoltage6_);
}
void TelemetryData::setMod3CellVoltage7(double mod3CellVoltage7)
{
   mod3CellVoltage7_ = mod3CellVoltage7;
   emit mod3CellVoltage7Received(mod3CellVoltage7_);
}

void TelemetryData::setBatteryVoltage(double batteryVoltage)
{
   batteryVoltage_ = batteryVoltage;
   emit batteryVoltageReceived(batteryVoltage_);
}

void TelemetryData::setBatteryCurrent(double batteryCurrent)
{
   batteryCurrent_ = batteryCurrent;
   emit batteryCurrentReceived(batteryCurrent_);
}

void TelemetryData::setBatteryVoltageThresholdRising(double batteryVoltageThresholdRising)
{
   batteryVoltageThresholdRising_ = batteryVoltageThresholdRising;
   emit batteryVoltageThresholdRisingReceived(batteryVoltageThresholdRising_);
}

void TelemetryData::setBatteryVoltageThresholdFalling(double batteryVoltageThresholdFalling)
{
   batteryVoltageThresholdFalling_ = batteryVoltageThresholdFalling;
   emit batteryVoltageThresholdFallingReceived(batteryVoltageThresholdFalling_);
}

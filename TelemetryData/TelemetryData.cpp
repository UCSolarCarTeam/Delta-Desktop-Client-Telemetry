#include "TelemetryData.h"

TelemetryData::TelemetryData()
{
}

TelemetryData::~TelemetryData()
{
}

double TelemetryData::driverSetSpeedRPM() const
{              return driverSetSpeedRPM_;}
double TelemetryData::driverSetCurrent() const
{              return driverSetCurrent_;}

double TelemetryData::vehicleVelocityKph() const
{              return vehicleVelocityKph_;}
double TelemetryData::busCurrentA() const
{              return busCurrentA_;}
double TelemetryData::busVoltage() const
{              return busVoltage_;}
double TelemetryData::motorVelocityRpm() const
{              return motorVelocityRpm_;}
double TelemetryData::motorVoltageReal() const
{              return motorVoltageReal_;}
double TelemetryData::motorCurrentReal() const
{              return motorCurrentReal_;}
double TelemetryData::backEmfImaginary() const
{              return backEmfImaginary_;}
double TelemetryData::ipmHeatSinkTemp() const
{              return ipmHeatSinkTemp_;}
double TelemetryData::dspBoardTemp() const
{              return dspBoardTemp_;}
double TelemetryData::dcBusAmpHours() const
{              return dcBusAmpHours_;}
double TelemetryData::receivedErrorCount() const
{              return receivedErrorCount_;}
double TelemetryData::transmittedErrorCount() const
{              return transmittedErrorCount_;}

int TelemetryData::mod0PcbTemperature() const
{           return mod0PcbTemperature_;}
int TelemetryData::mod0CellTemperature() const
{           return mod0CellTemperature_;}
int TelemetryData::mod0CellVoltage0() const
{           return mod0CellVoltage0_;}
int TelemetryData::mod0CellVoltage1() const
{           return mod0CellVoltage1_;}
int TelemetryData::mod0CellVoltage2() const
{           return mod0CellVoltage2_;}
int TelemetryData::mod0CellVoltage3() const
{           return mod0CellVoltage3_;}
int TelemetryData::mod0CellVoltage4() const
{           return mod0CellVoltage4_;}
int TelemetryData::mod0CellVoltage5() const
{           return mod0CellVoltage5_;}
int TelemetryData::mod0CellVoltage6() const
{           return mod0CellVoltage6_;}
int TelemetryData::mod0CellVoltage7() const
{           return mod0CellVoltage7_;}

int TelemetryData::mod1PcbTemperature() const
{           return mod1PcbTemperature_;}
int TelemetryData::mod1CellTemperature() const
{           return mod1CellTemperature_;}
int TelemetryData::mod1CellVoltage0() const
{           return mod1CellVoltage0_;}
int TelemetryData::mod1CellVoltage1() const
{           return mod1CellVoltage1_;}
int TelemetryData::mod1CellVoltage2() const
{           return mod1CellVoltage2_;}
int TelemetryData::mod1CellVoltage3() const
{           return mod1CellVoltage3_;}
int TelemetryData::mod1CellVoltage4() const
{           return mod1CellVoltage4_;}
int TelemetryData::mod1CellVoltage5() const
{           return mod1CellVoltage5_;}
int TelemetryData::mod1CellVoltage6() const
{           return mod1CellVoltage6_;}
int TelemetryData::mod1CellVoltage7() const
{           return mod1CellVoltage7_;}

int TelemetryData::mod2PcbTemperature() const
{           return mod2PcbTemperature_;}
int TelemetryData::mod2CellTemperature() const
{           return mod2CellTemperature_;}
int TelemetryData::mod2CellVoltage0() const
{           return mod2CellVoltage0_;}
int TelemetryData::mod2CellVoltage1() const
{           return mod2CellVoltage1_;}
int TelemetryData::mod2CellVoltage2() const
{           return mod2CellVoltage2_;}
int TelemetryData::mod2CellVoltage3() const
{           return mod2CellVoltage3_;}
int TelemetryData::mod2CellVoltage4() const
{           return mod2CellVoltage4_;}
int TelemetryData::mod2CellVoltage5() const
{           return mod2CellVoltage5_;}
int TelemetryData::mod2CellVoltage6() const
{           return mod2CellVoltage6_;}
int TelemetryData::mod2CellVoltage7() const
{           return mod2CellVoltage7_;}

int TelemetryData::mod3PcbTemperature() const
{           return mod3PcbTemperature_;}
int TelemetryData::mod3CellTemperature() const
{           return mod3CellTemperature_;}
int TelemetryData::mod3CellVoltage0() const
{           return mod3CellVoltage0_;}
int TelemetryData::mod3CellVoltage1() const
{           return mod3CellVoltage1_;}
int TelemetryData::mod3CellVoltage2() const
{           return mod3CellVoltage2_;}
int TelemetryData::mod3CellVoltage3() const
{           return mod3CellVoltage3_;}
int TelemetryData::mod3CellVoltage4() const
{           return mod3CellVoltage4_;}
int TelemetryData::mod3CellVoltage5() const
{           return mod3CellVoltage5_;}
int TelemetryData::mod3CellVoltage6() const
{           return mod3CellVoltage6_;}
int TelemetryData::mod3CellVoltage7() const
{           return mod3CellVoltage7_;}

int TelemetryData::batteryVoltage() const
{           return batteryVoltage_;}
int TelemetryData::batteryCurrent() const
{           return batteryCurrent_;}
int TelemetryData::batteryVoltageThresholdRising() const
{           return batteryVoltageThresholdRising_;}
int TelemetryData::batteryVoltageThresholdFalling() const
{           return batteryVoltageThresholdFalling_;}

/************Solar Car Driver************/
void TelemetryData::setDriverSetSpeedRPM(double driverSetSpeedRPM){
   driverSetSpeedRPM_ = driverSetSpeedRPM;
   emit driverSetSpeedRPMReceived(driverSetSpeedRPM_);
}
void TelemetryData::setDriverSetCurrent(double driverSetCurrent){
   driverSetCurrent_ = driverSetCurrent;
   emit driverSetCurrentReceived(driverSetCurrent_);
}

/************Solar Car Readings************/
void TelemetryData::setVehicleVelocityKph(double vehicleVelocityKph){
   vehicleVelocityKph_ = vehicleVelocityKph;
   emit vehicleVelocityKphReceived(vehicleVelocityKph_);
}
void TelemetryData::setBusCurrentA(double busCurrentA){
   busCurrentA_ = busCurrentA;
   emit busCurrentAReceived(busCurrentA_);
}
void TelemetryData::setBusVoltage(double busVoltage){
   busVoltage_ = busVoltage;
   emit busVoltageReceived(busVoltage_);
}
void TelemetryData::setMotorVelocityRpm(double motorVelocityRpm){
   motorVelocityRpm_ = motorVelocityRpm;
   emit motorVelocityRpmReceived(motorVelocityRpm_);
}
void TelemetryData::setMotorVoltageReal(double motorVoltageReal){
   motorVoltageReal_ = motorVoltageReal;
   emit motorVoltageRealReceived(motorVoltageReal_);
}
void TelemetryData::setMotorCurrentReal(double motorCurrentReal){
   motorCurrentReal_ = motorCurrentReal;
   emit motorCurrentRealReceived(motorCurrentReal_);
}
void TelemetryData::setBackEmfImaginary(double backEmfImaginary){
   backEmfImaginary_ = backEmfImaginary;
   emit backEmfImaginaryReceived(backEmfImaginary_);
}
void TelemetryData::setIpmHeatSinkTemp(double ipmHeatSinkTemp){
   ipmHeatSinkTemp_ = ipmHeatSinkTemp;
   emit ipmHeatSinkTempReceived(ipmHeatSinkTemp_);
}
void TelemetryData::setDspBoardTemp(double dspBoardTemp){
   dspBoardTemp_ = dspBoardTemp;
   emit dspBoardTempReceived(dspBoardTemp_);
}
void TelemetryData::setDcBusAmpHours(double dcBusAmpHours){
   dcBusAmpHours_ = dcBusAmpHours;
   emit dcBusAmpHoursReceived(dcBusAmpHours_);
}
void TelemetryData::setReceivedErrorCount(double receivedErrorCount){
   receivedErrorCount_ = receivedErrorCount;
   emit receivedErrorCountReceived(receivedErrorCount_);
}
void TelemetryData::setTransmittedErrorCount(double transmittedErrorCount){
   transmittedErrorCount_ = transmittedErrorCount;
   emit transmittedErrorCountReceived(transmittedErrorCount_);
}

/************Battery Module 0************/
void TelemetryData::setMod0PcbTemperature(int mod0PcbTemperature){
   mod0PcbTemperature_ = mod0PcbTemperature;
   emit mod0PcbTemperatureReceived(mod0PcbTemperature_);
}
void TelemetryData::setMod0CellTemperature(int mod0CellTemperature){
   mod0CellTemperature_ = mod0CellTemperature;
   emit mod0PcbTemperatureReceived(mod0CellTemperature_);
}
void TelemetryData::setMod0CellVoltage0(int mod0CellVoltage0){
   mod0CellVoltage0_ = mod0CellVoltage0;
   emit mod0CellVoltage0Received(mod0CellVoltage0_);
}
void TelemetryData::setMod0CellVoltage1(int mod0CellVoltage1){
   mod0CellVoltage1_ = mod0CellVoltage1;
   emit mod0CellVoltage1Received(mod0CellVoltage1_);
}
void TelemetryData::setMod0CellVoltage2(int mod0CellVoltage2){
   mod0CellVoltage2_ = mod0CellVoltage2;
   emit mod0CellVoltage2Received(mod0CellVoltage2_);
}
void TelemetryData::setMod0CellVoltage3(int mod0CellVoltage3){
   mod0CellVoltage3_ = mod0CellVoltage3;
   emit mod0CellVoltage3Received(mod0CellVoltage3_);
}
void TelemetryData::setMod0CellVoltage4(int mod0CellVoltage4){
   mod0CellVoltage4_ = mod0CellVoltage4;
   emit mod0CellVoltage4Received(mod0CellVoltage4_);
}
void TelemetryData::setMod0CellVoltage5(int mod0CellVoltage5){
   mod0CellVoltage5_ = mod0CellVoltage5;
   emit mod0CellVoltage5Received(mod0CellVoltage5_);
}
void TelemetryData::setMod0CellVoltage6(int mod0CellVoltage6){
   mod0CellVoltage6_ = mod0CellVoltage6;
   emit mod0CellVoltage6Received(mod0CellVoltage6_);
}
void TelemetryData::setMod0CellVoltage7(int mod0CellVoltage7){
   mod0CellVoltage7_ = mod0CellVoltage7;
   emit mod0CellVoltage7Received(mod0CellVoltage7_);
}

/************Battery Module 1************/
void TelemetryData::setMod1PcbTemperature(int mod1PcbTemperature){
   mod1PcbTemperature_ = mod1PcbTemperature;
   emit mod1PcbTemperatureReceived(mod1PcbTemperature_);
}
void TelemetryData::setMod1CellTemperature(int mod1CellTemperature){
   mod1CellTemperature_ = mod1CellTemperature;
   emit mod1PcbTemperatureReceived(mod1CellTemperature_);
}
void TelemetryData::setMod1CellVoltage0(int mod1CellVoltage0){
   mod1CellVoltage0_ = mod1CellVoltage0;
   emit mod1CellVoltage0Received(mod1CellVoltage0_);
}
void TelemetryData::setMod1CellVoltage1(int mod1CellVoltage1){
   mod1CellVoltage1_ = mod1CellVoltage1;
   emit mod1CellVoltage1Received(mod1CellVoltage1_);
}
void TelemetryData::setMod1CellVoltage2(int mod1CellVoltage2){
   mod1CellVoltage2_ = mod1CellVoltage2;
   emit mod1CellVoltage2Received(mod1CellVoltage2_);
}
void TelemetryData::setMod1CellVoltage3(int mod1CellVoltage3){
   mod1CellVoltage3_ = mod1CellVoltage3;
   emit mod1CellVoltage3Received(mod1CellVoltage3_);
}
void TelemetryData::setMod1CellVoltage4(int mod1CellVoltage4){
   mod1CellVoltage4_ = mod1CellVoltage4;
   emit mod1CellVoltage4Received(mod1CellVoltage4_);
}
void TelemetryData::setMod1CellVoltage5(int mod1CellVoltage5){
   mod1CellVoltage5_ = mod1CellVoltage5;
   emit mod1CellVoltage5Received(mod1CellVoltage5_);
}
void TelemetryData::setMod1CellVoltage6(int mod1CellVoltage6){
   mod1CellVoltage6_ = mod1CellVoltage6;
   emit mod1CellVoltage6Received(mod1CellVoltage6_);
}
void TelemetryData::setMod1CellVoltage7(int mod1CellVoltage7){
   mod1CellVoltage7_ = mod1CellVoltage7;
   emit mod1CellVoltage7Received(mod1CellVoltage7_);
}

/************Battery Module 2************/
void TelemetryData::setMod2PcbTemperature(int mod2PcbTemperature){
   mod2PcbTemperature_ = mod2PcbTemperature;
   emit mod2PcbTemperatureReceived(mod2PcbTemperature_);
}
void TelemetryData::setMod2CellTemperature(int mod2CellTemperature){
   mod2CellTemperature_ = mod2CellTemperature;
   emit mod2PcbTemperatureReceived(mod2CellTemperature_);
}
void TelemetryData::setMod2CellVoltage0(int mod2CellVoltage0){
   mod2CellVoltage0_ = mod2CellVoltage0;
   emit mod2CellVoltage0Received(mod2CellVoltage0_);
}
void TelemetryData::setMod2CellVoltage1(int mod2CellVoltage1){
   mod2CellVoltage1_ = mod2CellVoltage1;
   emit mod2CellVoltage1Received(mod2CellVoltage1_);
}
void TelemetryData::setMod2CellVoltage2(int mod2CellVoltage2){
   mod2CellVoltage2_ = mod2CellVoltage2;
   emit mod2CellVoltage2Received(mod2CellVoltage2_);
}
void TelemetryData::setMod2CellVoltage3(int mod2CellVoltage3){
   mod2CellVoltage3_ = mod2CellVoltage3;
   emit mod2CellVoltage3Received(mod2CellVoltage3_);
}
void TelemetryData::setMod2CellVoltage4(int mod2CellVoltage4){
   mod2CellVoltage4_ = mod2CellVoltage4;
   emit mod2CellVoltage4Received(mod2CellVoltage4_);
}
void TelemetryData::setMod2CellVoltage5(int mod2CellVoltage5){
   mod2CellVoltage5_ = mod2CellVoltage5;
   emit mod2CellVoltage5Received(mod2CellVoltage5_);
}
void TelemetryData::setMod2CellVoltage6(int mod2CellVoltage6){
   mod2CellVoltage6_ = mod2CellVoltage6;
   emit mod2CellVoltage6Received(mod2CellVoltage6_);
}
void TelemetryData::setMod2CellVoltage7(int mod2CellVoltage7){
   mod2CellVoltage7_ = mod2CellVoltage7;
   emit mod2CellVoltage7Received(mod2CellVoltage7_);
}

/************Battery Module 3************/
void TelemetryData::setMod3PcbTemperature(int mod3PcbTemperature){
   mod3PcbTemperature_ = mod3PcbTemperature;
   emit mod3PcbTemperatureReceived(mod3PcbTemperature_);
}

void TelemetryData::setMod3CellTemperature(int mod3CellTemperature){
   mod3CellTemperature_ = mod3CellTemperature;
   emit mod3PcbTemperatureReceived(mod3CellTemperature_);
}
void TelemetryData::setMod3CellVoltage0(int mod3CellVoltage0){
   mod3CellVoltage0_ = mod3CellVoltage0;
   emit mod3CellVoltage0Received(mod3CellVoltage0_);
}
void TelemetryData::setMod3CellVoltage1(int mod3CellVoltage1){
   mod3CellVoltage1_ = mod3CellVoltage1;
   emit mod3CellVoltage1Received(mod3CellVoltage1_);
}
void TelemetryData::setMod3CellVoltage2(int mod3CellVoltage2){
   mod3CellVoltage2_ = mod3CellVoltage2;
   emit mod3CellVoltage2Received(mod3CellVoltage2_);
}
void TelemetryData::setMod3CellVoltage3(int mod3CellVoltage3){
   mod3CellVoltage3_ = mod3CellVoltage3;
   emit mod3CellVoltage3Received(mod3CellVoltage3_);
}
void TelemetryData::setMod3CellVoltage4(int mod3CellVoltage4){
   mod3CellVoltage4_ = mod3CellVoltage4;
   emit mod3CellVoltage4Received(mod3CellVoltage4_);
}
void TelemetryData::setMod3CellVoltage5(int mod3CellVoltage5){
   mod3CellVoltage5_ = mod3CellVoltage5;
   emit mod3CellVoltage5Received(mod3CellVoltage5_);
}
void TelemetryData::setMod3CellVoltage6(int mod3CellVoltage6){
   mod3CellVoltage6_ = mod3CellVoltage6;
   emit mod3CellVoltage6Received(mod3CellVoltage6_);
}
void TelemetryData::setMod3CellVoltage7(int mod3CellVoltage7){
   mod3CellVoltage7_ = mod3CellVoltage7;
   emit mod3CellVoltage7Received(mod3CellVoltage7_);
}

void TelemetryData::setBatteryVoltage(int batteryVoltage)
{
   batteryVoltage_ = batteryVoltage;
   emit batteryVoltageReceived(batteryVoltage_);
}

void TelemetryData::setBatteryCurrent(int batteryCurrent)
{
   batteryCurrent_ = batteryCurrent;
   emit batteryCurrentReceived(batteryCurrent_);
}

void TelemetryData::setBatteryVoltageThresholdRising(int batteryVoltageThresholdRising)
{
   batteryVoltageThresholdRising_ = batteryVoltageThresholdRising;
   emit batteryVoltageThresholdRisingReceived(batteryVoltageThresholdRising_);
}

void TelemetryData::setBatteryVoltageThresholdFalling(int batteryVoltageThresholdFalling)
{
   batteryVoltageThresholdFalling_ = batteryVoltageThresholdFalling;
   emit batteryVoltageThresholdFallingReceived(batteryVoltageThresholdFalling_);
}

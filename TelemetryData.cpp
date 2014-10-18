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
double TelemetryData::recievedErrorCount() const
{              return recievedErrorCount_;}
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
int TelemetryData::batteryCurent() const
{           return batteryCurrent_;}
int TelemetryData::batteryVoltageThresholdRising() const
{           return batteryVoltageThresholdRising_;}
int TelemetryData::batteryVoltageThresholdFalling() const
{           return batteryVoltageThresholdFalling_;}


void setDriverSetSpeedRPM(double driverSetSpeedRPM);
void setDriverSetCurrent(double driverSetCurrent);

void TelemetryData::setVehicleVelocityKph(double vehicleVelocityKph)
{
   vehicleVelocity_ = vehicleVelocity;
   emit vehicleVelocityReceived(vehicleVelocity_);
}

void setBusCurrentA(double busCurrentA)
{
   busCurrentA_ = busCurrentA;
   emit busCurrentARecieved(busCurrentA_);
}

void setBusVoltage(double busVoltage);
void setMotorVelocityRpm(double motorVelocityRpm);
void setMotorVoltageReal(double motorVoltageReal);
void setMotorCurrentReal(double motorCurrentReal);
void setBackEmfImaginary(double backEmfImaginary);
void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
void setDspBoardTemp(double dspBoardTemp);
void setDcBusAmpHours(double dcBusAmpHours);
void setRecievedErrorCount(double recievedErrorCount);
void setTransmittedErrorCount(double transmittedErrorCount);

void setMod0PcbTemperature(int mod0PcbTemperature);
void setMod0CellTemperature(int mod0CellTemperature);
void setMod0CellVoltage0(int mod0CellVoltage0);
void setMod0CellVoltage1(int mod0cellVoltage1);
void setMod0CellVoltage2(int mod0cellVoltage2);
void setMod0CellVoltage3(int mod0cellVoltage3);
void setMod0CellVoltage4(int mod0cellVoltage4);
void setMod0CellVoltage5(int mod0cellVoltage5);
void setMod0CellVoltage6(int mod0cellVoltage6);
void setMod0CellVoltage7(int mod0cellVoltage7);

void setMod1PcbTemperature(int mod1pcbTemperature);
void setMod1CellTemperature(int mod1cellTemperature);
void setMod1CellVoltage0(int mod1cellVoltage0);
void setMod1CellVoltage1(int mod1cellVoltage1);
void setMod1CellVoltage2(int mod1cellVoltage2);
void setMod1CellVoltage3(int mod1cellVoltage3);
void setMod1CellVoltage4(int mod1cellVoltage4);
void setMod1CellVoltage5(int mod1cellVoltage5);
void setMod1CellVoltage6(int mod1cellVoltage6);
void setMod1CellVoltage7(int mod1cellVoltage7);

void setMod2PcbTemperature(int mod2pcbTemperature);
void setMod2CellTemperature(int mod2cellTemperature);
void setMod2CellVoltage0(int mod2cellVoltage0);
void setMod2CellVoltage1(int mod2cellVoltage1);
void setMod2CellVoltage2(int mod2cellVoltage2);
void setMod2CellVoltage3(int mod2cellVoltage3);
void setMod2CellVoltage4(int mod2cellVoltage4);
void setMod2CellVoltage5(int mod2cellVoltage5);
void setMod2CellVoltage6(int mod2cellVoltage6);
void setMod2CellVoltage7(int mod2cellVoltage7);

void setMod3PcbTemperature(int mod3pcbTemperature);
void setMod3CellTemperature(int mod3cellTemperature);
void setMod3CellVoltage0(int mod3cellVoltage0);
void setMod3CellVoltage1(int mod3cellVoltage1);
void setMod3CellVoltage2(int mod3cellVoltage2);
void setMod3CellVoltage3(int mod3cellVoltage3);
void setMod3CellVoltage4(int mod3cellVoltage4);
void setMod3CellVoltage5(int mod3cellVoltage5);
void setMod3CellVoltage6(int mod3cellVoltage6);
void setMod3CellVoltage7(int mod3cellVoltage7);

void setBatteryVoltage(int batteryVoltage) const;
void setBatteryCurent(int batterCurrent) const;
void setBatteryVoltageThresholdRising(int batteryVoltageThresholdRising) const;
void setBatteryVoltageThresholdFalling(batteryVoltageThresholdFalling) const;

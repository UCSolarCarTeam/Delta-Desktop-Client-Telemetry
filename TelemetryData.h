#pragma once

#include "I_TelemetryData.h"

class TelemetryData : public I_TelemetryData
{
public:
  TelemetryData();
  virtual ~TelemetryData();

  double vehicleVelocity() const;
  void setVehicleVelocity(double vehicleVelocity);

private:
   double driverSetSpeedRPM_;
   double driverSetCurrent_;

   double vehicleVelocityKph_;
   double busCurrentA_;
   double busVoltage_;
   double motorVelocityRpm_;
   double motorVoltageReal_;
   double motorCurrentReal_;
   double backEmfImaginary_;
   double ipmHeatSinkTemp_;
   double dspBoardTemp_;
   double dcBusAmpHours_;
   double recievedErrorCount_;
   double transmittedErrorCount_;

   int mod0PcbTemperature_;
   int mod0CellTemperature_;
   int mod0CellVoltage0_;
   int mod0CellVoltage1_;
   int mod0CellVoltage2_;
   int mod0CellVoltage3_;
   int mod0CellVoltage4_;
   int mod0CellVoltage5_;
   int mod0CellVoltage6_;
   int mod0CellVoltage7_;

   int mod1PcbTemperature_;
   int mod1CellTemperature_;
   int mod1CellVoltage0_;
   int mod1CellVoltage1_;
   int mod1CellVoltage2_;
   int mod1CellVoltage3_;
   int mod1CellVoltage4_;
   int mod1CellVoltage5_;
   int mod1CellVoltage6_;
   int mod1CellVoltage7_;

   int mod2PcbTemperature_;
   int mod2CellTemperature_;
   int mod2CellVoltage0_;
   int mod2CellVoltage1_;
   int mod2CellVoltage2_;
   int mod2CellVoltage3_;
   int mod2CellVoltage4_;
   int mod2CellVoltage5_;
   int mod2CellVoltage6_;
   int mod2CellVoltage7_;

   int mod3PcbTemperature_;
   int mod3CellTemperature_;
   int mod3CellVoltage0_;
   int mod3CellVoltage1_;
   int mod3CellVoltage2_;
   int mod3CellVoltage3_;
   int mod3CellVoltage4_;
   int mod3CellVoltage5_;
   int mod3CellVoltage6_;
   int mod3CellVoltage7_;

   int batteryVoltage_;
   int batteryCurent_;
   int batteryVoltageThresholdRising_;
   int batteryVoltageThresholdFalling_;
};



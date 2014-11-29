#pragma once

#include "I_TelemetryData.h"

class TelemetryData : public I_TelemetryData
{
public:
  TelemetryData();
  virtual ~TelemetryData();

  /*Data "Gets"*/
  double driverSetSpeedRPM() const;
  double driverSetCurrent() const;

  double vehicleVelocityKph() const;
  double busCurrentA() const;
  double busVoltage() const;
  double motorVelocityRpm() const;
  double motorVoltageReal() const;
  double motorCurrentReal() const;
  double backEmfImaginary() const;
  double ipmHeatSinkTemp() const;
  double dspBoardTemp() const;
  double dcBusAmpHours() const;

  double receivedErrorCount() const;
  double transmittedErrorCount() const;

  double mod0PcbTemperature() const;
  double mod0CellTemperature() const;
  double mod0CellVoltage0() const;
  double mod0CellVoltage1() const;
  double mod0CellVoltage2() const;
  double mod0CellVoltage3() const;
  double mod0CellVoltage4() const;
  double mod0CellVoltage5() const;
  double mod0CellVoltage6() const;
  double mod0CellVoltage7() const;

  double mod1PcbTemperature() const;
  double mod1CellTemperature() const;
  double mod1CellVoltage0() const;
  double mod1CellVoltage1() const;
  double mod1CellVoltage2() const;
  double mod1CellVoltage3() const;
  double mod1CellVoltage4() const;
  double mod1CellVoltage5() const;
  double mod1CellVoltage6() const;
  double mod1CellVoltage7() const;

  double mod2PcbTemperature() const;
  double mod2CellTemperature() const;
  double mod2CellVoltage0() const;
  double mod2CellVoltage1() const;
  double mod2CellVoltage2() const;
  double mod2CellVoltage3() const;
  double mod2CellVoltage4() const;
  double mod2CellVoltage5() const;
  double mod2CellVoltage6() const;
  double mod2CellVoltage7() const;

  double mod3PcbTemperature() const;
  double mod3CellTemperature() const;
  double mod3CellVoltage0() const;
  double mod3CellVoltage1() const;
  double mod3CellVoltage2() const;
  double mod3CellVoltage3() const;
  double mod3CellVoltage4() const;
  double mod3CellVoltage5() const;
  double mod3CellVoltage6() const;
  double mod3CellVoltage7() const;

  double batteryVoltage() const;
  double batteryCurrent() const;
  double batteryVoltageThresholdRising() const;
  double batteryVoltageThresholdFalling() const;

   /*Data "Sets"*/
   void setDriverSetSpeedRPM(double driverSetSpeedRPM);
   void setDriverSetCurrent(double driverSetCurrent);

   void setVehicleVelocityKph(double vehicleVelocityKph);
   void setBusCurrentA(double busCurrentA);
   void setBusVoltage(double busVoltage);
   void setMotorVelocityRpm(double motorVelocityRpm);
   void setMotorVoltageReal(double motorVoltageReal);
   void setMotorCurrentReal(double motorCurrentReal);
   void setBackEmfImaginary(double backEmfImaginary);
   void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
   void setDspBoardTemp(double dspBoardTemp);
   void setDcBusAmpHours(double dcBusAmpHours);

   void setReceivedErrorCount(double receivedErrorCount);
   void setTransmittedErrorCount(double transmittedErrorCount);

   void setMod0PcbTemperature(double mod0PcbTemperature);
   void setMod0CellTemperature(double mod0CellTemperature);
   void setMod0CellVoltage0(double mod0CellVoltage0);
   void setMod0CellVoltage1(double mod0CellVoltage1);
   void setMod0CellVoltage2(double mod0CellVoltage2);
   void setMod0CellVoltage3(double mod0CellVoltage3);
   void setMod0CellVoltage4(double mod0CellVoltage4);
   void setMod0CellVoltage5(double mod0CellVoltage5);
   void setMod0CellVoltage6(double mod0CellVoltage6);
   void setMod0CellVoltage7(double mod0CellVoltage7);

   void setMod1PcbTemperature(double mod1PcbTemperature);
   void setMod1CellTemperature(double mod1CellTemperature);
   void setMod1CellVoltage0(double mod1CellVoltage0);
   void setMod1CellVoltage1(double mod1CellVoltage1);
   void setMod1CellVoltage2(double mod1CellVoltage2);
   void setMod1CellVoltage3(double mod1CellVoltage3);
   void setMod1CellVoltage4(double mod1CellVoltage4);
   void setMod1CellVoltage5(double mod1CellVoltage5);
   void setMod1CellVoltage6(double mod1CellVoltage6);
   void setMod1CellVoltage7(double mod1CellVoltage7);

   void setMod2PcbTemperature(double mod2PcbTemperature);
   void setMod2CellTemperature(double mod2CellTemperature);
   void setMod2CellVoltage0(double mod2CellVoltage0);
   void setMod2CellVoltage1(double mod2CellVoltage1);
   void setMod2CellVoltage2(double mod2CellVoltage2);
   void setMod2CellVoltage3(double mod2CellVoltage3);
   void setMod2CellVoltage4(double mod2CellVoltage4);
   void setMod2CellVoltage5(double mod2CellVoltage5);
   void setMod2CellVoltage6(double mod2CellVoltage6);
   void setMod2CellVoltage7(double mod2CellVoltage7);

   void setMod3PcbTemperature(double mod3PcbTemperature);
   void setMod3CellTemperature(double mod3CellTemperature);
   void setMod3CellVoltage0(double mod3CellVoltage0);
   void setMod3CellVoltage1(double mod3CellVoltage1);
   void setMod3CellVoltage2(double mod3CellVoltage2);
   void setMod3CellVoltage3(double mod3CellVoltage3);
   void setMod3CellVoltage4(double mod3CellVoltage4);
   void setMod3CellVoltage5(double mod3CellVoltage5);
   void setMod3CellVoltage6(double mod3CellVoltage6);
   void setMod3CellVoltage7(double mod3CellVoltage7);

   void setBatteryVoltage(double batteryVoltage);
   void setBatteryCurrent(double batteryCurrent);
   void setBatteryVoltageThresholdRising(double batteryVoltageThresholdRising);
   void setBatteryVoltageThresholdFalling(double batteryVoltageThresholdFalling);

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
   
   double receivedErrorCount_;
   double transmittedErrorCount_;

   double mod0PcbTemperature_;
   double mod0CellTemperature_;
   double mod0CellVoltage0_;
   double mod0CellVoltage1_;
   double mod0CellVoltage2_;
   double mod0CellVoltage3_;
   double mod0CellVoltage4_;
   double mod0CellVoltage5_;
   double mod0CellVoltage6_;
   double mod0CellVoltage7_;

   double mod1PcbTemperature_;
   double mod1CellTemperature_;
   double mod1CellVoltage0_;
   double mod1CellVoltage1_;
   double mod1CellVoltage2_;
   double mod1CellVoltage3_;
   double mod1CellVoltage4_;
   double mod1CellVoltage5_;
   double mod1CellVoltage6_;
   double mod1CellVoltage7_;

   double mod2PcbTemperature_;
   double mod2CellTemperature_;
   double mod2CellVoltage0_;
   double mod2CellVoltage1_;
   double mod2CellVoltage2_;
   double mod2CellVoltage3_;
   double mod2CellVoltage4_;
   double mod2CellVoltage5_;
   double mod2CellVoltage6_;
   double mod2CellVoltage7_;

   double mod3PcbTemperature_;
   double mod3CellTemperature_;
   double mod3CellVoltage0_;
   double mod3CellVoltage1_;
   double mod3CellVoltage2_;
   double mod3CellVoltage3_;
   double mod3CellVoltage4_;
   double mod3CellVoltage5_;
   double mod3CellVoltage6_;
   double mod3CellVoltage7_;

   double batteryVoltage_;
   double batteryCurrent_;
   double batteryVoltageThresholdRising_;
   double batteryVoltageThresholdFalling_;
};



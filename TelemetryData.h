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
  double recievedErrorCount() const;
  double transmittedErrorCount() const;

  int mod0PcbTemperature() const;
  int mod0CellTemperature() const;
  int mod0CellVoltage0() const;
  int mod0CellVoltage1() const;
  int mod0CellVoltage2() const;
  int mod0CellVoltage3() const;
  int mod0CellVoltage4() const;
  int mod0CellVoltage5() const;
  int mod0CellVoltage6() const;
  int mod0CellVoltage7() const;

  int mod1PcbTemperature() const;
  int mod1CellTemperature() const;
  int mod1CellVoltage0() const;
  int mod1CellVoltage1() const;
  int mod1CellVoltage2() const;
  int mod1CellVoltage3() const;
  int mod1CellVoltage4() const;
  int mod1CellVoltage5() const;
  int mod1CellVoltage6() const;
  int mod1CellVoltage7() const;

  int mod2PcbTemperature() const;
  int mod2CellTemperature() const;
  int mod2CellVoltage0() const;
  int mod2CellVoltage1() const;
  int mod2CellVoltage2() const;
  int mod2CellVoltage3() const;
  int mod2CellVoltage4() const;
  int mod2CellVoltage5() const;
  int mod2CellVoltage6() const;
  int mod2CellVoltage7() const;

  int mod3PcbTemperature() const;
  int mod3CellTemperature() const;
  int mod3CellVoltage0() const;
  int mod3CellVoltage1() const;
  int mod3CellVoltage2() const;
  int mod3CellVoltage3() const;
  int mod3CellVoltage4() const;
  int mod3CellVoltage5() const;
  int mod3CellVoltage6() const;
  int mod3CellVoltage7() const;

  int batteryVoltage() const;
  int batteryCurent() const;
  int batteryVoltageThresholdRising() const;
  int batteryVoltageThresholdFalling() const;

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
   void setReceivedErrorCount(double recievedErrorCount);
   void setTransmittedErrorCount(double transmittedErrorCount);

   void setMod0PcbTemperature(int mod0PcbTemperature);
   void setMod0CellTemperature(int mod0CellTemperature);
   void setMod0CellVoltage0(int mod0CellVoltage0);
   void setMod0CellVoltage1(int mod0CellVoltage1);
   void setMod0CellVoltage2(int mod0CellVoltage2);
   void setMod0CellVoltage3(int mod0CellVoltage3);
   void setMod0CellVoltage4(int mod0CellVoltage4);
   void setMod0CellVoltage5(int mod0CellVoltage5);
   void setMod0CellVoltage6(int mod0CellVoltage6);
   void setMod0CellVoltage7(int mod0CellVoltage7);

   void setMod1PcbTemperature(int mod1PcbTemperature);
   void setMod1CellTemperature(int mod1CellTemperature);
   void setMod1CellVoltage0(int mod1CellVoltage0);
   void setMod1CellVoltage1(int mod1CellVoltage1);
   void setMod1CellVoltage2(int mod1CellVoltage2);
   void setMod1CellVoltage3(int mod1CellVoltage3);
   void setMod1CellVoltage4(int mod1CellVoltage4);
   void setMod1CellVoltage5(int mod1CellVoltage5);
   void setMod1CellVoltage6(int mod1CellVoltage6);
   void setMod1CellVoltage7(int mod1CellVoltage7);

   void setMod2PcbTemperature(int mod2PcbTemperature);
   void setMod2CellTemperature(int mod2CellTemperature);
   void setMod2CellVoltage0(int mod2CellVoltage0);
   void setMod2CellVoltage1(int mod2CellVoltage1);
   void setMod2CellVoltage2(int mod2CellVoltage2);
   void setMod2CellVoltage3(int mod2CellVoltage3);
   void setMod2CellVoltage4(int mod2CellVoltage4);
   void setMod2CellVoltage5(int mod2CellVoltage5);
   void setMod2CellVoltage6(int mod2CellVoltage6);
   void setMod2CellVoltage7(int mod2CellVoltage7);

   void setMod3PcbTemperature(int mod3PcbTemperature);
   void setMod3CellTemperature(int mod3CellTemperature);
   void setMod3CellVoltage0(int mod3CellVoltage0);
   void setMod3CellVoltage1(int mod3CellVoltage1);
   void setMod3CellVoltage2(int mod3CellVoltage2);
   void setMod3CellVoltage3(int mod3CellVoltage3);
   void setMod3CellVoltage4(int mod3CellVoltage4);
   void setMod3CellVoltage5(int mod3CellVoltage5);
   void setMod3CellVoltage6(int mod3CellVoltage6);
   void setMod3CellVoltage7(int mod3CellVoltage7);

   void setBatteryVoltage(int batteryVoltage);
   void setBatteryCurent(int batteryCurrent);
   void setBatteryVoltageThresholdRising(int batteryVoltageThresholdRising);
   void setBatteryVoltageThresholdFalling(int batteryVoltageThresholdFalling);

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
   int batteryCurrent_;
   int batteryVoltageThresholdRising_;
   int batteryVoltageThresholdFalling_;
};



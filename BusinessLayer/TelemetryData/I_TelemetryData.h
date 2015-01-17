#pragma once

#include <QObject>

class I_TelemetryData : public QObject
{
  Q_OBJECT

public:
   virtual ~I_TelemetryData() {}

   /*Data "Gets"*/
   virtual double driverSetSpeedRPM() const = 0;
   virtual double driverSetCurrent() const = 0;

   virtual double vehicleVelocityKph() const = 0;
   virtual double busCurrentA() const = 0;
   virtual double busVoltage() const = 0;
   virtual double motorVelocityRpm() const = 0;
   virtual double motorVoltageReal() const = 0;
   virtual double motorCurrentReal() const = 0;
   virtual double backEmfImaginary() const = 0;
   virtual double ipmHeatSinkTemp() const = 0;
   virtual double dspBoardTemp() const = 0;
   virtual double dcBusAmpHours() const = 0;
   
   virtual double receivedErrorCount() const = 0;
   virtual double transmittedErrorCount() const = 0;

   virtual double mod0PcbTemperature() const = 0;
   virtual double mod0CellTemperature() const = 0;
   virtual double mod0CellVoltage0() const = 0;
   virtual double mod0CellVoltage1() const = 0;
   virtual double mod0CellVoltage2() const = 0;
   virtual double mod0CellVoltage3() const = 0;
   virtual double mod0CellVoltage4() const = 0;
   virtual double mod0CellVoltage5() const = 0;
   virtual double mod0CellVoltage6() const = 0;
   virtual double mod0CellVoltage7() const = 0;

   virtual double mod1PcbTemperature() const = 0;
   virtual double mod1CellTemperature() const = 0;
   virtual double mod1CellVoltage0() const = 0;
   virtual double mod1CellVoltage1() const = 0;
   virtual double mod1CellVoltage2() const = 0;
   virtual double mod1CellVoltage3() const = 0;
   virtual double mod1CellVoltage4() const = 0;
   virtual double mod1CellVoltage5() const = 0;
   virtual double mod1CellVoltage6() const = 0;
   virtual double mod1CellVoltage7() const = 0;

   virtual double mod2PcbTemperature() const = 0;
   virtual double mod2CellTemperature() const = 0;
   virtual double mod2CellVoltage0() const = 0;
   virtual double mod2CellVoltage1() const = 0;
   virtual double mod2CellVoltage2() const = 0;
   virtual double mod2CellVoltage3() const = 0;
   virtual double mod2CellVoltage4() const = 0;
   virtual double mod2CellVoltage5() const = 0;
   virtual double mod2CellVoltage6() const = 0;
   virtual double mod2CellVoltage7() const = 0;

   virtual double mod3PcbTemperature() const = 0;
   virtual double mod3CellTemperature() const = 0;
   virtual double mod3CellVoltage0() const = 0;
   virtual double mod3CellVoltage1() const = 0;
   virtual double mod3CellVoltage2() const = 0;
   virtual double mod3CellVoltage3() const = 0;
   virtual double mod3CellVoltage4() const = 0;
   virtual double mod3CellVoltage5() const = 0;
   virtual double mod3CellVoltage6() const = 0;
   virtual double mod3CellVoltage7() const = 0;

   virtual double batteryVoltage() const = 0;
   virtual double batteryCurrent() const = 0;
   virtual double batteryVoltageThresholdRising() const = 0;
   virtual double batteryVoltageThresholdFalling() const = 0;

   /*Data "Sets"*/
   virtual void setDriverSetSpeedRPM(double driverSetSpeedRPM) = 0;
   virtual void setDriverSetCurrent(double driverSetCurrent) = 0;

   virtual void setVehicleVelocityKph(double vehicleVelocityKph) = 0;
   virtual void setBusCurrentA(double busCurrentA) = 0;
   virtual void setBusVoltage(double busVoltage) = 0;
   virtual void setMotorVelocityRpm(double motorVelocityRpm) = 0;
   virtual void setMotorVoltageReal(double motorVoltageReal) = 0;
   virtual void setMotorCurrentReal(double motorCurrentReal) = 0;
   virtual void setBackEmfImaginary(double backEmfImaginary) = 0;
   virtual void setIpmHeatSinkTemp(double ipmHeatSinkTemp) = 0;
   virtual void setDspBoardTemp(double dspBoardTemp) = 0;
   virtual void setDcBusAmpHours(double dcBusAmpHours) = 0;
   
   virtual void setReceivedErrorCount(double receivedErrorCount) = 0;
   virtual void setTransmittedErrorCount(double transmittedErrorCount) = 0;

   virtual void setMod0PcbTemperature(double mod0PcbTemperature) = 0;
   virtual void setMod0CellTemperature(double mod0CellTemperature) = 0;
   virtual void setMod0CellVoltage0(double mod0CellVoltage0) = 0;
   virtual void setMod0CellVoltage1(double mod0CellVoltage1) = 0;
   virtual void setMod0CellVoltage2(double mod0CellVoltage2) = 0;
   virtual void setMod0CellVoltage3(double mod0CellVoltage3) = 0;
   virtual void setMod0CellVoltage4(double mod0CellVoltage4) = 0;
   virtual void setMod0CellVoltage5(double mod0CellVoltage5) = 0;
   virtual void setMod0CellVoltage6(double mod0CellVoltage6) = 0;
   virtual void setMod0CellVoltage7(double mod0CellVoltage7) = 0;

   virtual void setMod1PcbTemperature(double mod1PcbTemperature) = 0;
   virtual void setMod1CellTemperature(double mod1CellTemperature) = 0;
   virtual void setMod1CellVoltage0(double mod1CellVoltage0) = 0;
   virtual void setMod1CellVoltage1(double mod1CellVoltage1) = 0;
   virtual void setMod1CellVoltage2(double mod1CellVoltage2) = 0;
   virtual void setMod1CellVoltage3(double mod1CellVoltage3) = 0;
   virtual void setMod1CellVoltage4(double mod1CellVoltage4) = 0;
   virtual void setMod1CellVoltage5(double mod1CellVoltage5) = 0;
   virtual void setMod1CellVoltage6(double mod1CellVoltage6) = 0;
   virtual void setMod1CellVoltage7(double mod1CellVoltage7) = 0;

   virtual void setMod2PcbTemperature(double mod2PcbTemperature) = 0;
   virtual void setMod2CellTemperature(double mod2CellTemperature) = 0;
   virtual void setMod2CellVoltage0(double mod2CellVoltage0) = 0;
   virtual void setMod2CellVoltage1(double mod2CellVoltage1) = 0;
   virtual void setMod2CellVoltage2(double mod2CellVoltage2) = 0;
   virtual void setMod2CellVoltage3(double mod2CellVoltage3) = 0;
   virtual void setMod2CellVoltage4(double mod2CellVoltage4) = 0;
   virtual void setMod2CellVoltage5(double mod2CellVoltage5) = 0;
   virtual void setMod2CellVoltage6(double mod2CellVoltage6) = 0;
   virtual void setMod2CellVoltage7(double mod2CellVoltage7) = 0;

   virtual void setMod3PcbTemperature(double mod3PcbTemperature) = 0;
   virtual void setMod3CellTemperature(double mod3CellTemperature) = 0;
   virtual void setMod3CellVoltage0(double mod3CellVoltage0) = 0;
   virtual void setMod3CellVoltage1(double mod3CellVoltage1) = 0;
   virtual void setMod3CellVoltage2(double mod3CellVoltage2) = 0;
   virtual void setMod3CellVoltage3(double mod3CellVoltage3) = 0;
   virtual void setMod3CellVoltage4(double mod3CellVoltage4) = 0;
   virtual void setMod3CellVoltage5(double mod3CellVoltage5) = 0;
   virtual void setMod3CellVoltage6(double mod3CellVoltage6) = 0;
   virtual void setMod3CellVoltage7(double mod3CellVoltage7) = 0;

   virtual void setBatteryVoltage(double batteryVoltage) = 0;
   virtual void setBatteryCurrent(double batteryCurrent) = 0;
   virtual void setBatteryVoltageThresholdRising(double batteryVoltageThresholdRising) = 0;
   virtual void setBatteryVoltageThresholdFalling(double batteryVoltageThresholdFalling) = 0;

signals:
   void driverSetSpeedRPMReceived(double driverSetSpeedRPM);
   void driverSetCurrentReceived(double driverSetCurrent);

   void vehicleVelocityKphReceived(double vehicleVelocityKph);
   void busCurrentAReceived(double busCurrentA);
   void busVoltageReceived(double busVoltage);
   void motorVelocityRpmReceived(double motorVelocityRpm);
   void motorVoltageRealReceived(double motorVoltageReal);
   void motorCurrentRealReceived(double motorCurrentReal);
   void backEmfImaginaryReceived(double backEmfImaginary);
   void ipmHeatSinkTempReceived(double ipmHeatSinkTemp);
   void dspBoardTempReceived(double dspBoardTemp);
   void dcBusAmpHoursReceived(double dcBusAmpHours);
   void receivedErrorCountReceived(double ReceivedErrorCount);
   void transmittedErrorCountReceived(double transmittedErrorCount);

   void mod0PcbTemperatureReceived(double mod0PcbTemperature);
   void mod0CellTemperatureReceived(double mod0CellTemperature);
   void mod0CellVoltage0Received(double mod0CellVoltage0);
   void mod0CellVoltage1Received(double mod0CellVoltage1);
   void mod0CellVoltage2Received(double mod0CellVoltage2);
   void mod0CellVoltage3Received(double mod0CellVoltage3);
   void mod0CellVoltage4Received(double mod0CellVoltage4);
   void mod0CellVoltage5Received(double mod0CellVoltage5);
   void mod0CellVoltage6Received(double mod0CellVoltage6);
   void mod0CellVoltage7Received(double mod0CellVoltage7);

   void mod1PcbTemperatureReceived(double mod1PcbTemperature);
   void mod1CellTemperatureReceived(double mod1CellTemperature);
   void mod1CellVoltage0Received(double mod1CellVoltage0);
   void mod1CellVoltage1Received(double mod1CellVoltage1);
   void mod1CellVoltage2Received(double mod1CellVoltage2);
   void mod1CellVoltage3Received(double mod1CellVoltage3);
   void mod1CellVoltage4Received(double mod1CellVoltage4);
   void mod1CellVoltage5Received(double mod1CellVoltage5);
   void mod1CellVoltage6Received(double mod1CellVoltage6);
   void mod1CellVoltage7Received(double mod1CellVoltage7);

   void mod2PcbTemperatureReceived(double mod2PcbTemperature);
   void mod2CellTemperatureReceived(double mod2CellTemperature);
   void mod2CellVoltage0Received(double mod2CellVoltage0);
   void mod2CellVoltage1Received(double mod2CellVoltage1);
   void mod2CellVoltage2Received(double mod2CellVoltage2);
   void mod2CellVoltage3Received(double mod2CellVoltage3);
   void mod2CellVoltage4Received(double mod2CellVoltage4);
   void mod2CellVoltage5Received(double mod2CellVoltage5);
   void mod2CellVoltage6Received(double mod2CellVoltage6);
   void mod2CellVoltage7Received(double mod2CellVoltage7);

   void mod3PcbTemperatureReceived(double mod3PcbTemperature);
   void mod3CellTemperatureReceived(double mod3CellTemperature);
   void mod3CellVoltage0Received(double mod3CellVoltage0);
   void mod3CellVoltage1Received(double mod3CellVoltage1);
   void mod3CellVoltage2Received(double mod3CellVoltage2);
   void mod3CellVoltage3Received(double mod3CellVoltage3);
   void mod3CellVoltage4Received(double mod3CellVoltage4);
   void mod3CellVoltage5Received(double mod3CellVoltage5);
   void mod3CellVoltage6Received(double mod3CellVoltage6);
   void mod3CellVoltage7Received(double mod3CellVoltage7);

   void batteryVoltageReceived(double batteryVoltage);
   void batteryCurrentReceived(double batteryCurent);
   void batteryVoltageThresholdRisingReceived(double batteryVoltageThresholdRising);
   void batteryVoltageThresholdFallingReceived(double batteryVoltageThresholdFalling);
};


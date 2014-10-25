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

   virtual int mod0PcbTemperature() const = 0;
   virtual int mod0CellTemperature() const = 0;
   virtual int mod0CellVoltage0() const = 0;
   virtual int mod0CellVoltage1() const = 0;
   virtual int mod0CellVoltage2() const = 0;
   virtual int mod0CellVoltage3() const = 0;
   virtual int mod0CellVoltage4() const = 0;
   virtual int mod0CellVoltage5() const = 0;
   virtual int mod0CellVoltage6() const = 0;
   virtual int mod0CellVoltage7() const = 0;

   virtual int mod1PcbTemperature() const = 0;
   virtual int mod1CellTemperature() const = 0;
   virtual int mod1CellVoltage0() const = 0;
   virtual int mod1CellVoltage1() const = 0;
   virtual int mod1CellVoltage2() const = 0;
   virtual int mod1CellVoltage3() const = 0;
   virtual int mod1CellVoltage4() const = 0;
   virtual int mod1CellVoltage5() const = 0;
   virtual int mod1CellVoltage6() const = 0;
   virtual int mod1CellVoltage7() const = 0;

   virtual int mod2PcbTemperature() const = 0;
   virtual int mod2CellTemperature() const = 0;
   virtual int mod2CellVoltage0() const = 0;
   virtual int mod2CellVoltage1() const = 0;
   virtual int mod2CellVoltage2() const = 0;
   virtual int mod2CellVoltage3() const = 0;
   virtual int mod2CellVoltage4() const = 0;
   virtual int mod2CellVoltage5() const = 0;
   virtual int mod2CellVoltage6() const = 0;
   virtual int mod2CellVoltage7() const = 0;

   virtual int mod3PcbTemperature() const = 0;
   virtual int mod3CellTemperature() const = 0;
   virtual int mod3CellVoltage0() const = 0;
   virtual int mod3CellVoltage1() const = 0;
   virtual int mod3CellVoltage2() const = 0;
   virtual int mod3CellVoltage3() const = 0;
   virtual int mod3CellVoltage4() const = 0;
   virtual int mod3CellVoltage5() const = 0;
   virtual int mod3CellVoltage6() const = 0;
   virtual int mod3CellVoltage7() const = 0;

   virtual int batteryVoltage() const = 0;
   virtual int batteryCurrent() const = 0;
   virtual int batteryVoltageThresholdRising() const = 0;
   virtual int batteryVoltageThresholdFalling() const = 0;

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
   virtual void setReceivedErrorCount(double ReceivedErrorCount) = 0;
   virtual void setTransmittedErrorCount(double transmittedErrorCount) = 0;

   virtual void setMod0PcbTemperature(int mod0PcbTemperature) = 0;
   virtual void setMod0CellTemperature(int mod0CellTemperature) = 0;
   virtual void setMod0CellVoltage0(int mod0CellVoltage0) = 0;
   virtual void setMod0CellVoltage1(int mod0CellVoltage1) = 0;
   virtual void setMod0CellVoltage2(int mod0CellVoltage2) = 0;
   virtual void setMod0CellVoltage3(int mod0CellVoltage3) = 0;
   virtual void setMod0CellVoltage4(int mod0CellVoltage4) = 0;
   virtual void setMod0CellVoltage5(int mod0CellVoltage5) = 0;
   virtual void setMod0CellVoltage6(int mod0CellVoltage6) = 0;
   virtual void setMod0CellVoltage7(int mod0CellVoltage7) = 0;

   virtual void setMod1PcbTemperature(int mod1PcbTemperature) = 0;
   virtual void setMod1CellTemperature(int mod1CellTemperature) = 0;
   virtual void setMod1CellVoltage0(int mod1CellVoltage0) = 0;
   virtual void setMod1CellVoltage1(int mod1CellVoltage1) = 0;
   virtual void setMod1CellVoltage2(int mod1CellVoltage2) = 0;
   virtual void setMod1CellVoltage3(int mod1CellVoltage3) = 0;
   virtual void setMod1CellVoltage4(int mod1CellVoltage4) = 0;
   virtual void setMod1CellVoltage5(int mod1CellVoltage5) = 0;
   virtual void setMod1CellVoltage6(int mod1CellVoltage6) = 0;
   virtual void setMod1CellVoltage7(int mod1CellVoltage7) = 0;

   virtual void setMod2PcbTemperature(int mod2PcbTemperature) = 0;
   virtual void setMod2CellTemperature(int mod2CellTemperature) = 0;
   virtual void setMod2CellVoltage0(int mod2CellVoltage0) = 0;
   virtual void setMod2CellVoltage1(int mod2CellVoltage1) = 0;
   virtual void setMod2CellVoltage2(int mod2CellVoltage2) = 0;
   virtual void setMod2CellVoltage3(int mod2CellVoltage3) = 0;
   virtual void setMod2CellVoltage4(int mod2CellVoltage4) = 0;
   virtual void setMod2CellVoltage5(int mod2CellVoltage5) = 0;
   virtual void setMod2CellVoltage6(int mod2CellVoltage6) = 0;
   virtual void setMod2CellVoltage7(int mod2CellVoltage7) = 0;

   virtual void setMod3PcbTemperature(int mod3PcbTemperature) = 0;
   virtual void setMod3CellTemperature(int mod3CellTemperature) = 0;
   virtual void setMod3CellVoltage0(int mod3CellVoltage0) = 0;
   virtual void setMod3CellVoltage1(int mod3CellVoltage1) = 0;
   virtual void setMod3CellVoltage2(int mod3CellVoltage2) = 0;
   virtual void setMod3CellVoltage3(int mod3CellVoltage3) = 0;
   virtual void setMod3CellVoltage4(int mod3CellVoltage4) = 0;
   virtual void setMod3CellVoltage5(int mod3CellVoltage5) = 0;
   virtual void setMod3CellVoltage6(int mod3CellVoltage6) = 0;
   virtual void setMod3CellVoltage7(int mod3CellVoltage7) = 0;

   virtual void setBatteryVoltage(int batteryVoltage) = 0;
   virtual void setBatteryCurrent(int batteryCurrent) = 0;
   virtual void setBatteryVoltageThresholdRising(int batteryVoltageThresholdRising) = 0;
   virtual void setBatteryVoltageThresholdFalling(int batteryVoltageThresholdFalling) = 0;

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

   void mod0PcbTemperatureReceived(int mod0PcbTemperature);
   void mod0CellTemperatureReceived(int mod0CellTemperature);
   void mod0CellVoltage0Received(int mod0CellVoltage0);
   void mod0CellVoltage1Received(int mod0CellVoltage1);
   void mod0CellVoltage2Received(int mod0CellVoltage2);
   void mod0CellVoltage3Received(int mod0CellVoltage3);
   void mod0CellVoltage4Received(int mod0CellVoltage4);
   void mod0CellVoltage5Received(int mod0CellVoltage5);
   void mod0CellVoltage6Received(int mod0CellVoltage6);
   void mod0CellVoltage7Received(int mod0CellVoltage7);

   void mod1PcbTemperatureReceived(int mod1PcbTemperature);
   void mod1CellTemperatureReceived(int mod1CellTemperature);
   void mod1CellVoltage0Received(int mod1CellVoltage0);
   void mod1CellVoltage1Received(int mod1CellVoltage1);
   void mod1CellVoltage2Received(int mod1CellVoltage2);
   void mod1CellVoltage3Received(int mod1CellVoltage3);
   void mod1CellVoltage4Received(int mod1CellVoltage4);
   void mod1CellVoltage5Received(int mod1CellVoltage5);
   void mod1CellVoltage6Received(int mod1CellVoltage6);
   void mod1CellVoltage7Received(int mod1CellVoltage7);

   void mod2PcbTemperatureReceived(int mod2PcbTemperature);
   void mod2CellTemperatureReceived(int mod2CellTemperature);
   void mod2CellVoltage0Received(int mod2CellVoltage0);
   void mod2CellVoltage1Received(int mod2CellVoltage1);
   void mod2CellVoltage2Received(int mod2CellVoltage2);
   void mod2CellVoltage3Received(int mod2CellVoltage3);
   void mod2CellVoltage4Received(int mod2CellVoltage4);
   void mod2CellVoltage5Received(int mod2CellVoltage5);
   void mod2CellVoltage6Received(int mod2CellVoltage6);
   void mod2CellVoltage7Received(int mod2CellVoltage7);

   void mod3PcbTemperatureReceived(int mod3PcbTemperature);
   void mod3CellTemperatureReceived(int mod3CellTemperature);
   void mod3CellVoltage0Received(int mod3CellVoltage0);
   void mod3CellVoltage1Received(int mod3CellVoltage1);
   void mod3CellVoltage2Received(int mod3CellVoltage2);
   void mod3CellVoltage3Received(int mod3CellVoltage3);
   void mod3CellVoltage4Received(int mod3CellVoltage4);
   void mod3CellVoltage5Received(int mod3CellVoltage5);
   void mod3CellVoltage6Received(int mod3CellVoltage6);
   void mod3CellVoltage7Received(int mod3CellVoltage7);

   void batteryVoltageReceived(int batteryVoltage);
   void batteryCurrentReceived(int batteryCurent);
   void batteryVoltageThresholdRisingReceived(int batteryVoltageThresholdRising);
   void batteryVoltageThresholdFallingReceived(int batteryVoltageThresholdFalling);
};


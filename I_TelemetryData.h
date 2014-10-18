#pragma once

#include <QObject>

class I_TelemetryData : public QObject
{
  Q_OBJECT

public:
   virtual ~I_TelemetryData() {}

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

   virtual void setVehicleVelocityKph(double vehicleVelocity) = 0;

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


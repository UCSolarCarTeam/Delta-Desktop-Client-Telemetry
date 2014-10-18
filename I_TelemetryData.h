#pragma once

#include <QObject>

class I_TelemetryData : public QObject
{
  Q_OBJECT
public:
   virtual ~I_TelemetryData() {}

   virtual double driverSetSpeedRPM() const;
   virtual double driverSetCurrent() const;

   virtual double vehicleVelocityKph() const = 0;
   virtual double busCurrentA() const;
   virtual double busVoltage() const;
   virtual double motorVelocityRpm() const;
   virtual double motorVoltageReal() const;
   virtual double motorCurrentReal() const;
   virtual double backEmfImaginary() const;
   virtual double ipmHeatSinkTemp() const;
   virtual double dspBoardTemp() const;
   virtual double dcBusAmpHours() const;
   virtual double recievedErrorCount() const;
   virtual double transmittedErrorCount() const;

   virtual int mod0PcbTemperature() const;
   virtual int mod0CellTemperature() const;
   virtual int mod0CellVoltage0() const;
   virtual int mod0CellVoltage1() const;
   virtual int mod0CellVoltage2() const;
   virtual int mod0CellVoltage3() const;
   virtual int mod0CellVoltage4() const;
   virtual int mod0CellVoltage5() const;
   virtual int mod0CellVoltage6() const;
   virtual int mod0CellVoltage7() const;

   virtual int mod1PcbTemperature() const;
   virtual int mod1CellTemperature() const;
   virtual int mod1CellVoltage0() const;
   virtual int mod1CellVoltage1() const;
   virtual int mod1CellVoltage2() const;
   virtual int mod1CellVoltage3() const;
   virtual int mod1CellVoltage4() const;
   virtual int mod1CellVoltage5() const;
   virtual int mod1CellVoltage6() const;
   virtual int mod1CellVoltage7() const;

   virtual int mod2PcbTemperature() const;
   virtual int mod2CellTemperature() const;
   virtual int mod2CellVoltage0() const;
   virtual int mod2CellVoltage1() const;
   virtual int mod2CellVoltage2() const;
   virtual int mod2CellVoltage3() const;
   virtual int mod2CellVoltage4() const;
   virtual int mod2CellVoltage5() const;
   virtual int mod2CellVoltage6() const;
   virtual int mod2CellVoltage7() const;

   virtual int mod3PcbTemperature() const;
   virtual int mod3CellTemperature() const;
   virtual int mod3CellVoltage0() const;
   virtual int mod3CellVoltage1() const;
   virtual int mod3CellVoltage2() const;
   virtual int mod3CellVoltage3() const;
   virtual int mod3CellVoltage4() const;
   virtual int mod3CellVoltage5() const;
   virtual int mod3CellVoltage6() const;
   virtual int mod3CellVoltage7() const;

   virtual int batteryVoltage() const;
   virtual int batteryCurrent() const;
   virtual int batteryVoltageThresholdRising() const;
   virtual int batteryVoltageThresholdFalling() const;

   virtual void setVehicleVelocityKph(double vehicleVelocity) = 0;

signals:
   void driverSetSpeedRPMRecieved(double driverSetSpeedRPM);
   void driverSetCurrentRecieved(double driverSetCurrent);

   void vehicleVelocityKphReceived(double vehicleVelocityKph);
   void busCurrentAReceived() const;
   void busVoltageReceived() const;
   void motorVelocityRpmReceived() const;
   void motorVoltageRealReceived() const;
   void motorCurrentRealReceived() const;
   void backEmfImaginaryReceived() const;
   void ipmHeatSinkTempReceived() const;
   void dspBoardTempReceived() const;
   void dcBusAmpHoursReceived() const;
   void recievedErrorCountReceived() const;
   void transmittedErrorCountReceived() const;

   void mod0PcbTemperatureReceived() const;
   void mod0CellTemperatureReceived() const;
   void mod0CellVoltage0Received() const;
   void mod0CellVoltage1Received() const;
   void mod0CellVoltage2Received() const;
   void mod0CellVoltage3Received() const;
   void mod0CellVoltage4Received() const;
   void mod0CellVoltage5Received() const;
   void mod0CellVoltage6Received() const;
   void mod0CellVoltage7Received() const;

   void mod1PcbTemperatureReceived() const;
   void mod1CellTemperatureReceived() const;
   void mod1CellVoltage0Received() const;
   void mod1CellVoltage1Received() const;
   void mod1CellVoltage2Received() const;
   void mod1CellVoltage3Received() const;
   void mod1CellVoltage4Received() const;
   void mod1CellVoltage5Received() const;
   void mod1CellVoltage6Received() const;
   void mod1CellVoltage7Received() const;

   void mod2PcbTemperatureReceived() const;
   void mod2CellTemperatureReceived() const;
   void mod2CellVoltage0Received() const;
   void mod2CellVoltage1Received() const;
   void mod2CellVoltage2Received() const;
   void mod2CellVoltage3Received() const;
   void mod2CellVoltage4Received() const;
   void mod2CellVoltage5Received() const;
   void mod2CellVoltage6Received() const;
   void mod2CellVoltage7Received() const;

   void mod3PcbTemperatureReceived() const;
   void mod3CellTemperatureReceived() const;
   void mod3CellVoltage0Received() const;
   void mod3CellVoltage1Received() const;
   void mod3CellVoltage2Received() const;
   void mod3CellVoltage3Received() const;
   void mod3CellVoltage4Received() const;
   void mod3CellVoltage5Received() const;
   void mod3CellVoltage6Received() const;
   void mod3CellVoltage7Received() const;

   void batteryVoltageReceived() const;
   void batteryCurentReceived() const;
   void batteryVoltageThresholdRisingReceived() const;
   void batteryVoltageThresholdFallingReceived() const;

};


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
   void busCurrentA() const;
   void busVoltage() const;
   void motorVelocityRpm() const;
   void motorVoltageReal() const;
   void motorCurrentReal() const;
   void backEmfImaginary() const;
   void ipmHeatSinkTemp() const;
   void dspBoardTemp() const;
   void dcBusAmpHours() const;
   void recievedErrorCount() const;
   void transmittedErrorCount() const;

   void mod0PcbTemperature() const;
   void mod0CellTemperature() const;
   void mod0CellVoltage0() const;
   void mod0CellVoltage1() const;
   void mod0CellVoltage2() const;
   void mod0CellVoltage3() const;
   void mod0CellVoltage4() const;
   void mod0CellVoltage5() const;
   void mod0CellVoltage6() const;
   void mod0CellVoltage7() const;

   void mod1PcbTemperature() const;
   void mod1CellTemperature() const;
   void mod1CellVoltage0() const;
   void mod1CellVoltage1() const;
   void mod1CellVoltage2() const;
   void mod1CellVoltage3() const;
   void mod1CellVoltage4() const;
   void mod1CellVoltage5() const;
   void mod1CellVoltage6() const;
   void mod1CellVoltage7() const;

   void mod2PcbTemperature() const;
   void mod2CellTemperature() const;
   void mod2CellVoltage0() const;
   void mod2CellVoltage1() const;
   void mod2CellVoltage2() const;
   void mod2CellVoltage3() const;
   void mod2CellVoltage4() const;
   void mod2CellVoltage5() const;
   void mod2CellVoltage6() const;
   void mod2CellVoltage7() const;

   void mod3PcbTemperature() const;
   void mod3CellTemperature() const;
   void mod3CellVoltage0() const;
   void mod3CellVoltage1() const;
   void mod3CellVoltage2() const;
   void mod3CellVoltage3() const;
   void mod3CellVoltage4() const;
   void mod3CellVoltage5() const;
   void mod3CellVoltage6() const;
   void mod3CellVoltage7() const;

   void batteryVoltage() const;
   void batteryCurent() const;
   void batteryVoltageThresholdRising() const;
   void batteryVoltageThresholdFalling() const;

};


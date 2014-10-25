#pragma once

#include <QObject>
class I_TelemetryData;
class I_ConnectionService;

class DisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit DisplayPresenter(const I_TelemetryData& telemetryData, I_ConnectionService& connectionService);
   void connectDataSource();


public slots:

private:
    void relayTelemetryData();
    void relayConnectionStatus();

private:
   const I_TelemetryData& telemetryData_;
   I_ConnectionService& connectionService_;

signals:
   void relayConnectionFailed(QString);
   void relayConnectionSucceeded();

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


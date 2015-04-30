#pragma once

#include <QObject>
class I_ArrayData;
class I_PowerData;
class I_VehicleData;
class I_ConnectionService;
class LoggerService;

class DisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit DisplayPresenter(const I_ArrayData& arrayData,
                             const I_PowerData& powerData,
                             const I_VehicleData& vehicleData,
                             I_ConnectionService& connectionService,
                             LoggerService& loggerService);
   void connectDataSource(QString portName, int baudRate);
   void disconnectDataSource();

private:
    void relayArrayData();
    void relayPowerData();
    void relayVehicleData();
    void relayConnectionStatus();
    void relayDebugMessage();

private:
   const I_ArrayData& arrayData_;
   const I_PowerData& powerData_;
   const I_VehicleData& vehicleData_;
   I_ConnectionService& connectionService_;
   LoggerService& loggerService_;

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

   void batteryVoltageThresholdRisingReceived(double batteryVoltageThresholdRising);
   void batteryVoltageThresholdFallingReceived(double batteryVoltageThresholdFalling);

   void connectionFailed(QString failureMessage);
   void connectionSucceeded(QString successMessage);
   void sendDebugMessage(QString message);
};


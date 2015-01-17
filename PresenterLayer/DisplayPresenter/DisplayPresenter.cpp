#include "DisplayPresenter.h"
#include "../TelemetryData/I_TelemetryData.h"
#include "../ConnectionService/I_ConnectionService.h"
#include "../DebugHandler/DebugHandler.h"


DisplayPresenter::DisplayPresenter(const I_TelemetryData& telemetryData,
                                   I_ConnectionService& connectionService,
                                   DebugHandler& debugHandler)
: telemetryData_(telemetryData)
, connectionService_(connectionService)
, debugHandler_(debugHandler)
{
    relayDebugMessage();
    relayConnectionStatus();
    relayTelemetryData();
}

void DisplayPresenter::connectDataSource(QString portName, int baudRate)
{
    connectionService_.connectDataSource(portName, baudRate);
}
void DisplayPresenter::disconnectDataSource()
{
   connectionService_.disconnectDataSource();
}

void DisplayPresenter::relayDebugMessage()
{
   connect(&debugHandler_, SIGNAL(sendDebugMessageToPresenter(QString)), this, SIGNAL(sendDebugMessage(QString)));
}

void DisplayPresenter::relayConnectionStatus()
{
    connect(&connectionService_, SIGNAL(connectionFailed(QString)), this, SIGNAL(connectionFailed(QString)));
    connect(&connectionService_, SIGNAL(connectionSucceeded(QString)), this, SIGNAL(connectionSucceeded(QString)));
}

void DisplayPresenter::relayTelemetryData()
{
   connect(&telemetryData_, SIGNAL(driverSetSpeedRPMReceived(double)),
           this, SIGNAL(driverSetSpeedRPMReceived(double)));
   connect(&telemetryData_, SIGNAL(driverSetCurrentReceived(double)),
           this, SIGNAL(driverSetCurrentReceived(double)));

   connect(&telemetryData_, SIGNAL(vehicleVelocityKphReceived(double)),
           this, SIGNAL(vehicleVelocityKphReceived(double)));
   connect(&telemetryData_, SIGNAL(busCurrentAReceived(double)),
           this, SIGNAL(busCurrentAReceived(double)));
   connect(&telemetryData_, SIGNAL(busVoltageReceived(double)),
           this, SIGNAL(busVoltageReceived(double)));
   connect(&telemetryData_, SIGNAL(motorVelocityRpmReceived(double)),
           this, SIGNAL(motorVelocityRpmReceived(double)));
   connect(&telemetryData_, SIGNAL(motorVoltageRealReceived(double)),
           this, SIGNAL(motorVoltageRealReceived(double)));
   connect(&telemetryData_, SIGNAL(motorCurrentRealReceived(double)),
           this, SIGNAL(motorCurrentRealReceived(double)));
   connect(&telemetryData_, SIGNAL(backEmfImaginaryReceived(double)),
           this, SIGNAL(backEmfImaginaryReceived(double)));
   connect(&telemetryData_, SIGNAL(ipmHeatSinkTempReceived(double)),
           this, SIGNAL(ipmHeatSinkTempReceived(double)));
   connect(&telemetryData_, SIGNAL(dspBoardTempReceived(double)),
           this, SIGNAL(dspBoardTempReceived(double)));
   connect(&telemetryData_, SIGNAL(dcBusAmpHoursReceived(double)),
           this, SIGNAL(dcBusAmpHoursReceived(double)));
   connect(&telemetryData_, SIGNAL(receivedErrorCountReceived(double)),
           this, SIGNAL(receivedErrorCountReceived(double)));
   connect(&telemetryData_, SIGNAL(transmittedErrorCountReceived(double)),
           this, SIGNAL(transmittedErrorCountReceived(double)));

   connect(&telemetryData_, SIGNAL(mod0PcbTemperatureReceived(double)),
           this, SIGNAL(mod0PcbTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod0CellTemperatureReceived(double)),
           this, SIGNAL(mod0CellTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage0Received(double)),
           this, SIGNAL(mod0CellVoltage0Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage1Received(double)),
           this, SIGNAL(mod0CellVoltage1Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage2Received(double)),
           this, SIGNAL(mod0CellVoltage2Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage3Received(double)),
           this, SIGNAL(mod0CellVoltage3Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage4Received(double)),
           this, SIGNAL(mod0CellVoltage4Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage5Received(double)),
           this, SIGNAL(mod0CellVoltage5Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage6Received(double)),
           this, SIGNAL(mod0CellVoltage6Received(double)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage7Received(double)),
           this, SIGNAL(mod0CellVoltage7Received(double)));

   connect(&telemetryData_, SIGNAL(mod1PcbTemperatureReceived(double)),
           this, SIGNAL(mod1PcbTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod1CellTemperatureReceived(double)),
           this, SIGNAL(mod1CellTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage0Received(double)),
           this, SIGNAL(mod1CellVoltage0Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage1Received(double)),
           this, SIGNAL(mod1CellVoltage1Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage2Received(double)),
           this, SIGNAL(mod1CellVoltage2Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage3Received(double)),
           this, SIGNAL(mod1CellVoltage3Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage4Received(double)),
           this, SIGNAL(mod1CellVoltage4Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage5Received(double)),
           this, SIGNAL(mod1CellVoltage5Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage6Received(double)),
           this, SIGNAL(mod1CellVoltage6Received(double)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage7Received(double)),
           this, SIGNAL(mod1CellVoltage7Received(double)));

   connect(&telemetryData_, SIGNAL(mod2PcbTemperatureReceived(double)),
           this, SIGNAL(mod2PcbTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod2CellTemperatureReceived(double)),
           this, SIGNAL(mod2CellTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage0Received(double)),
           this, SIGNAL(mod2CellVoltage0Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage1Received(double)),
           this, SIGNAL(mod2CellVoltage1Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage2Received(double)),
           this, SIGNAL(mod2CellVoltage2Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage3Received(double)),
           this, SIGNAL(mod2CellVoltage3Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage4Received(double)),
           this, SIGNAL(mod2CellVoltage4Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage5Received(double)),
           this, SIGNAL(mod2CellVoltage5Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage6Received(double)),
           this, SIGNAL(mod2CellVoltage6Received(double)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage7Received(double)),
           this, SIGNAL(mod2CellVoltage7Received(double)));

   connect(&telemetryData_, SIGNAL(mod3PcbTemperatureReceived(double)),
           this, SIGNAL(mod3PcbTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod3CellTemperatureReceived(double)),
           this, SIGNAL(mod3CellTemperatureReceived(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage0Received(double)),
           this, SIGNAL(mod3CellVoltage0Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage1Received(double)),
           this, SIGNAL(mod3CellVoltage1Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage2Received(double)),
           this, SIGNAL(mod3CellVoltage2Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage3Received(double)),
           this, SIGNAL(mod3CellVoltage3Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage4Received(double)),
           this, SIGNAL(mod3CellVoltage4Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage5Received(double)),
           this, SIGNAL(mod3CellVoltage5Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage6Received(double)),
           this, SIGNAL(mod3CellVoltage6Received(double)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage7Received(double)),
           this, SIGNAL(mod3CellVoltage7Received(double)));

   connect(&telemetryData_, SIGNAL(batteryVoltageReceived(double)),
           this, SIGNAL(batteryVoltageReceived(double)));
   connect(&telemetryData_, SIGNAL(batteryCurrentReceived(double)),
           this, SIGNAL(batteryCurrentReceived(double)));
   connect(&telemetryData_, SIGNAL(batteryVoltageThresholdRisingReceived(double)),
           this, SIGNAL(batteryVoltageThresholdRisingReceived(double)));
   connect(&telemetryData_, SIGNAL(batteryVoltageThresholdFallingReceived(double)),
           this, SIGNAL(batteryVoltageThresholdFallingReceived(double)));

   connect(&connectionService_, SIGNAL(connectionFailed(QString)),
           this, SIGNAL(connectionFailed(QString)));
   connect(&connectionService_, SIGNAL(connectionSucceeded(QString)),
           this, SIGNAL(connectionSucceeded(QString)));
}

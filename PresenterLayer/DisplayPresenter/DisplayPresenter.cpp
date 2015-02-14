#include "DisplayPresenter.h"
#include "../../DataLayer/ArrayData/I_ArrayData.h"
#include "../../DataLayer/VehicleData/I_VehicleData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"
#include "../../CommunicationLayer/ConnectionService/I_ConnectionService.h"
#include "../../BusinessLayer/LoggerService/LoggerService.h"


DisplayPresenter::DisplayPresenter(const I_ArrayData& arrayData,
                                   const I_PowerData& powerData,
                                   const I_VehicleData& vehicleData,
                                   const I_BatteryData& batteryData,
                                   I_ConnectionService& connectionService,
                                   LoggerService& loggerService)
: arrayData_(arrayData)
, powerData_(powerData)
, vehicleData_(vehicleData)
, batteryData_(batteryData)
, connectionService_(connectionService)
, loggerService_(loggerService)
{
    relayArrayData();
    relayPowerData();
    relayVehicleData();
    relayBatteryData();
    relayConnectionStatus();
    relayDebugMessage();
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
   connect(&loggerService_, SIGNAL(sendDebugMessageToPresenter(QString)), this, SIGNAL(sendDebugMessage(QString)));
}

void DisplayPresenter::relayConnectionStatus()
{
    connect(&connectionService_, SIGNAL(connectionFailed(QString)), 
            this, SIGNAL(connectionFailed(QString)));
    connect(&connectionService_, SIGNAL(connectionSucceeded(QString)), 
            this, SIGNAL(connectionSucceeded(QString)));
}

void DisplayPresenter::relayArrayData()
{
}

void DisplayPresenter::relayPowerData()
{
   connect(&powerData_, SIGNAL(busCurrentAReceived(double)),
           this, SIGNAL(busCurrentAReceived(double)));
   connect(&powerData_, SIGNAL(busVoltageReceived(double)),
           this, SIGNAL(busVoltageReceived(double)));
   connect(&powerData_, SIGNAL(motorVoltageRealReceived(double)),
           this, SIGNAL(motorVoltageRealReceived(double)));
   connect(&powerData_, SIGNAL(motorCurrentRealReceived(double)),
           this, SIGNAL(motorCurrentRealReceived(double)));
   connect(&powerData_, SIGNAL(backEmfImaginaryReceived(double)),
           this, SIGNAL(backEmfImaginaryReceived(double)));
   connect(&powerData_, SIGNAL(dcBusAmpHoursReceived(double)),
           this, SIGNAL(dcBusAmpHoursReceived(double)));  
}

void DisplayPresenter::relayVehicleData()
{
   connect(&vehicleData_, SIGNAL(driverSetSpeedRPMReceived(double)),
           this, SIGNAL(driverSetSpeedRPMReceived(double)));
   connect(&vehicleData_, SIGNAL(driverSetCurrentReceived(double)),
           this, SIGNAL(driverSetCurrentReceived(double)));
   connect(&vehicleData_, SIGNAL(vehicleVelocityKphReceived(double)),
           this, SIGNAL(vehicleVelocityKphReceived(double)));
   connect(&vehicleData_, SIGNAL(motorVelocityRpmReceived(double)),
           this, SIGNAL(motorVelocityRpmReceived(double)));
   connect(&vehicleData_, SIGNAL(ipmHeatSinkTempReceived(double)),
           this, SIGNAL(ipmHeatSinkTempReceived(double)));
   connect(&vehicleData_, SIGNAL(dspBoardTempReceived(double)),
           this, SIGNAL(dspBoardTempReceived(double)));
   connect(&vehicleData_, SIGNAL(receivedErrorCountReceived(double)),
           this, SIGNAL(receivedErrorCountReceived(double)));
   connect(&vehicleData_, SIGNAL(transmittedErrorCountReceived(double)),
           this, SIGNAL(transmittedErrorCountReceived(double)));  
}

void DisplayPresenter::relayBatteryData()
{
   connect(&batteryData_, SIGNAL(mod0PcbTemperatureReceived(double)),
           this, SIGNAL(mod0PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod0CellTemperatureReceived(double)),
           this, SIGNAL(mod0CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage0Received(double)),
           this, SIGNAL(mod0CellVoltage0Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage1Received(double)),
           this, SIGNAL(mod0CellVoltage1Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage2Received(double)),
           this, SIGNAL(mod0CellVoltage2Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage3Received(double)),
           this, SIGNAL(mod0CellVoltage3Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage4Received(double)),
           this, SIGNAL(mod0CellVoltage4Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage5Received(double)),
           this, SIGNAL(mod0CellVoltage5Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage6Received(double)),
           this, SIGNAL(mod0CellVoltage6Received(double)));
   connect(&batteryData_, SIGNAL(mod0CellVoltage7Received(double)),
           this, SIGNAL(mod0CellVoltage7Received(double)));

   connect(&batteryData_, SIGNAL(mod1PcbTemperatureReceived(double)),
           this, SIGNAL(mod1PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellTemperatureReceived(double)),
           this, SIGNAL(mod1CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage0Received(double)),
           this, SIGNAL(mod1CellVoltage0Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage1Received(double)),
           this, SIGNAL(mod1CellVoltage1Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage2Received(double)),
           this, SIGNAL(mod1CellVoltage2Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage3Received(double)),
           this, SIGNAL(mod1CellVoltage3Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage4Received(double)),
           this, SIGNAL(mod1CellVoltage4Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage5Received(double)),
           this, SIGNAL(mod1CellVoltage5Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage6Received(double)),
           this, SIGNAL(mod1CellVoltage6Received(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltage7Received(double)),
           this, SIGNAL(mod1CellVoltage7Received(double)));

   connect(&batteryData_, SIGNAL(mod2PcbTemperatureReceived(double)),
           this, SIGNAL(mod2PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellTemperatureReceived(double)),
           this, SIGNAL(mod2CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage0Received(double)),
           this, SIGNAL(mod2CellVoltage0Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage1Received(double)),
           this, SIGNAL(mod2CellVoltage1Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage2Received(double)),
           this, SIGNAL(mod2CellVoltage2Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage3Received(double)),
           this, SIGNAL(mod2CellVoltage3Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage4Received(double)),
           this, SIGNAL(mod2CellVoltage4Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage5Received(double)),
           this, SIGNAL(mod2CellVoltage5Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage6Received(double)),
           this, SIGNAL(mod2CellVoltage6Received(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltage7Received(double)),
           this, SIGNAL(mod2CellVoltage7Received(double)));

   connect(&batteryData_, SIGNAL(mod3PcbTemperatureReceived(double)),
           this, SIGNAL(mod3PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellTemperatureReceived(double)),
           this, SIGNAL(mod3CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage0Received(double)),
           this, SIGNAL(mod3CellVoltage0Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage1Received(double)),
           this, SIGNAL(mod3CellVoltage1Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage2Received(double)),
           this, SIGNAL(mod3CellVoltage2Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage3Received(double)),
           this, SIGNAL(mod3CellVoltage3Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage4Received(double)),
           this, SIGNAL(mod3CellVoltage4Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage5Received(double)),
           this, SIGNAL(mod3CellVoltage5Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage6Received(double)),
           this, SIGNAL(mod3CellVoltage6Received(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltage7Received(double)),
           this, SIGNAL(mod3CellVoltage7Received(double)));

   connect(&batteryData_, SIGNAL(batteryVoltageReceived(double)),
           this, SIGNAL(batteryVoltageReceived(double)));
   connect(&batteryData_, SIGNAL(batteryCurrentReceived(double)),
           this, SIGNAL(batteryCurrentReceived(double)));
   connect(&batteryData_, SIGNAL(batteryVoltageThresholdRisingReceived(double)),
           this, SIGNAL(batteryVoltageThresholdRisingReceived(double)));
   connect(&batteryData_, SIGNAL(batteryVoltageThresholdFallingReceived(double)),
           this, SIGNAL(batteryVoltageThresholdFallingReceived(double)));  
}


#include "DisplayPresenter.h"
#include "TelemetryData/I_TelemetryData.h"

DisplayPresenter::DisplayPresenter(const I_TelemetryData& telemetryData)
: telemetryData_(telemetryData)
{

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

   connect(&telemetryData_, SIGNAL(mod0PcbTemperatureReceived(int)),
           this, SIGNAL(mod0PcbTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod0CellTemperatureReceived(int)),
           this, SIGNAL(mod0CellTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage0Received(int)),
           this, SIGNAL(mod0CellVoltage0Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage1Received(int)),
           this, SIGNAL(mod0CellVoltage1Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage2Received(int)),
           this, SIGNAL(mod0CellVoltage2Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage3Received(int)),
           this, SIGNAL(mod0CellVoltage3Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage4Received(int)),
           this, SIGNAL(mod0CellVoltage4Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage5Received(int)),
           this, SIGNAL(mod0CellVoltage5Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage6Received(int)),
           this, SIGNAL(mod0CellVoltage6Received(int)));
   connect(&telemetryData_, SIGNAL(mod0CellVoltage7Received(int)),
           this, SIGNAL(mod0CellVoltage7Received(int)));

   connect(&telemetryData_, SIGNAL(mod1PcbTemperatureReceived(int)),
           this, SIGNAL(mod1PcbTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod1CellTemperatureReceived(int)),
           this, SIGNAL(mod1CellTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage0Received(int)),
           this, SIGNAL(mod1CellVoltage0Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage1Received(int)),
           this, SIGNAL(mod1CellVoltage1Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage2Received(int)),
           this, SIGNAL(mod1CellVoltage2Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage3Received(int)),
           this, SIGNAL(mod1CellVoltage3Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage4Received(int)),
           this, SIGNAL(mod1CellVoltage4Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage5Received(int)),
           this, SIGNAL(mod1CellVoltage5Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage6Received(int)),
           this, SIGNAL(mod1CellVoltage6Received(int)));
   connect(&telemetryData_, SIGNAL(mod1CellVoltage7Received(int)),
           this, SIGNAL(mod1CellVoltage7Received(int)));

   connect(&telemetryData_, SIGNAL(mod2PcbTemperatureReceived(int)),
           this, SIGNAL(mod2PcbTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod2CellTemperatureReceived(int)),
           this, SIGNAL(mod2CellTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage0Received(int)),
           this, SIGNAL(mod2CellVoltage0Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage1Received(int)),
           this, SIGNAL(mod2CellVoltage1Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage2Received(int)),
           this, SIGNAL(mod2CellVoltage2Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage3Received(int)),
           this, SIGNAL(mod2CellVoltage3Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage4Received(int)),
           this, SIGNAL(mod2CellVoltage4Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage5Received(int)),
           this, SIGNAL(mod2CellVoltage5Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage6Received(int)),
           this, SIGNAL(mod2CellVoltage6Received(int)));
   connect(&telemetryData_, SIGNAL(mod2CellVoltage7Received(int)),
           this, SIGNAL(mod2CellVoltage7Received(int)));

   connect(&telemetryData_, SIGNAL(mod3PcbTemperatureReceived(int)),
           this, SIGNAL(mod3PcbTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod3CellTemperatureReceived(int)),
           this, SIGNAL(mod3CellTemperatureReceived(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage0Received(int)),
           this, SIGNAL(mod3CellVoltage0Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage1Received(int)),
           this, SIGNAL(mod3CellVoltage1Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage2Received(int)),
           this, SIGNAL(mod3CellVoltage2Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage3Received(int)),
           this, SIGNAL(mod3CellVoltage3Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage4Received(int)),
           this, SIGNAL(mod3CellVoltage4Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage5Received(int)),
           this, SIGNAL(mod3CellVoltage5Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage6Received(int)),
           this, SIGNAL(mod3CellVoltage6Received(int)));
   connect(&telemetryData_, SIGNAL(mod3CellVoltage7Received(int)),
           this, SIGNAL(mod3CellVoltage7Received(int)));

   connect(&telemetryData_, SIGNAL(batteryVoltageReceived(int)),
           this, SIGNAL(batteryVoltageReceived(int)));
   connect(&telemetryData_, SIGNAL(batteryCurrentReceived(int)),
           this, SIGNAL(batteryCurrentReceived(int)));
   connect(&telemetryData_, SIGNAL(batteryVoltageThresholdRisingReceived(int)),
           this, SIGNAL(batteryVoltageThresholdRisingReceived(int)));
   connect(&telemetryData_, SIGNAL(batteryVoltageThresholdFallingReceived(int)),
           this, SIGNAL(batteryVoltageThresholdFallingReceived(int)));
}

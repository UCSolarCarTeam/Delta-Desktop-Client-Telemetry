#include "BatteryPresenter.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"

BatteryPresenter::BatteryPresenter(const I_BatteryData& batteryData)
: batteryData_(batteryData)
{	
	relayBatteryData();
}

void BatteryPresenter::relayBatteryData()
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
}
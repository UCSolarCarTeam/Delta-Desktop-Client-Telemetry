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
   connect(&batteryData_, SIGNAL(mod0CellVoltagesReceived(double)),
           this, SIGNAL(mod0CellVoltagesReceived(double)));

   connect(&batteryData_, SIGNAL(mod1PcbTemperatureReceived(double)),
           this, SIGNAL(mod1PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellTemperatureReceived(double)),
           this, SIGNAL(mod1CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltagesReceived(double)),
           this, SIGNAL(mod1CellVoltagesReceived(double)));

   connect(&batteryData_, SIGNAL(mod2PcbTemperatureReceived(double)),
           this, SIGNAL(mod2PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellTemperatureReceived(double)),
           this, SIGNAL(mod2CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltagesReceived(double)),
           this, SIGNAL(mod2CellVoltagesReceived(double)));

   connect(&batteryData_, SIGNAL(mod3PcbTemperatureReceived(double)),
           this, SIGNAL(mod3PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellTemperatureReceived(double)),
           this, SIGNAL(mod3CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltagesReceived(double)),
           this, SIGNAL(mod3CellVoltagesReceived(double)));

   connect(&batteryData_, SIGNAL(batteryVoltageReceived(double)),
           this, SIGNAL(batteryVoltageReceived(double)));
   connect(&batteryData_, SIGNAL(batteryCurrentReceived(double)),
           this, SIGNAL(batteryCurrentReceived(double)));
}

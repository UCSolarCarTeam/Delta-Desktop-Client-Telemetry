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
   connect(&batteryData_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
           this, SIGNAL(mod0CellVoltagesReceived(QList<double>)));

   connect(&batteryData_, SIGNAL(mod1PcbTemperatureReceived(double)),
           this, SIGNAL(mod1PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellTemperatureReceived(double)),
           this, SIGNAL(mod1CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
           this, SIGNAL(mod1CellVoltagesReceived(QList<double>)));

   connect(&batteryData_, SIGNAL(mod2PcbTemperatureReceived(double)),
           this, SIGNAL(mod2PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellTemperatureReceived(double)),
           this, SIGNAL(mod2CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
           this, SIGNAL(mod2CellVoltagesReceived(QList<double>)));

   connect(&batteryData_, SIGNAL(mod3PcbTemperatureReceived(double)),
           this, SIGNAL(mod3PcbTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellTemperatureReceived(double)),
           this, SIGNAL(mod3CellTemperatureReceived(double)));
   connect(&batteryData_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
           this, SIGNAL(mod3CellVoltagesReceived(QList<double>)));

   connect(&batteryData_, SIGNAL(batteryVoltageReceived(double)),
           this, SIGNAL(batteryVoltageReceived(double)));
   connect(&batteryData_, SIGNAL(batteryCurrentReceived(double)),
           this, SIGNAL(batteryCurrentReceived(double)));
}

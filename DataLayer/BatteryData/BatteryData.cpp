#include "BatteryData.h"

BatteryData::BatteryData()
{
}

BatteryData::~BatteryData()
{
}

/*BatteryData "Gets"*/
double BatteryData::mod0PcbTemperature() const
{           
   return mod0PcbTemperature_;
}
double BatteryData::mod0CellTemperature() const
{           
   return mod0CellTemperature_;
}

QList<double> BatteryData::mod0CellVoltages() const
{
   return mod0CellVoltages_;
}

double BatteryData::mod1PcbTemperature() const
{           
   return mod1PcbTemperature_;
}
double BatteryData::mod1CellTemperature() const
{           
   return mod1CellTemperature_;
}

QList<double> BatteryData::mod1CellVoltages() const
{
   return mod1CellVoltages_;
}

double BatteryData::mod2PcbTemperature() const
{           
   return mod2PcbTemperature_;
}
double BatteryData::mod2CellTemperature() const
{           
   return mod2CellTemperature_;
}

QList<double> BatteryData::mod2CellVoltages() const
{
   return mod2CellVoltages_;
}

double BatteryData::mod3PcbTemperature() const
{           
   return mod3PcbTemperature_;
}
double BatteryData::mod3CellTemperature() const
{           
   return mod3CellTemperature_;
}

QList<double> BatteryData::mod3CellVoltages() const
{
   return mod3CellVoltages_;
}

double BatteryData::batteryVoltage() const
{           
   return batteryVoltage_;
}
double BatteryData::batteryCurrent() const
{           
   return batteryCurrent_;
}                      

/*BatteryData "Sets"*/
void BatteryData::setMod0PcbTemperature(double mod0PcbTemperature)
{
   mod0PcbTemperature_ = mod0PcbTemperature;
   emit mod0PcbTemperatureReceived(mod0PcbTemperature_);
}
void BatteryData::setMod0CellTemperature(double mod0CellTemperature)
{
   mod0CellTemperature_ = mod0CellTemperature;
   emit mod0CellTemperatureReceived(mod0CellTemperature_);
}

void BatteryData::setMod0CellVoltages(QList<double> mod0CellVoltages)
{
   mod0CellVoltages_ = mod0CellVoltages;
   emit mod0CellVoltagesReceived(mod0CellVoltages_);
}

void BatteryData::setMod1PcbTemperature(double mod1PcbTemperature)
{
   mod1PcbTemperature_ = mod1PcbTemperature;
   emit mod1PcbTemperatureReceived(mod1PcbTemperature_);
}
void BatteryData::setMod1CellTemperature(double mod1CellTemperature)
{
   mod1CellTemperature_ = mod1CellTemperature;
   emit mod1CellTemperatureReceived(mod1CellTemperature_);
}

void BatteryData::setMod1CellVoltages(QList<double> mod1CellVoltages)
{
   mod1CellVoltages_ = mod1CellVoltages;
   emit mod1CellVoltagesReceived(mod1CellVoltages_);
}

void BatteryData::setMod2PcbTemperature(double mod2PcbTemperature)
{
   mod2PcbTemperature_ = mod2PcbTemperature;
   emit mod2PcbTemperatureReceived(mod2PcbTemperature_);
}
void BatteryData::setMod2CellTemperature(double mod2CellTemperature)
{
   mod2CellTemperature_ = mod2CellTemperature;
   emit mod2CellTemperatureReceived(mod2CellTemperature_);
}

void BatteryData::setMod2CellVoltages(QList<double> mod2CellVoltages)
{
   mod2CellVoltages_ = mod2CellVoltages;
   emit mod2CellVoltagesReceived(mod2CellVoltages_);
}

void BatteryData::setMod3PcbTemperature(double mod3PcbTemperature)
{
   mod3PcbTemperature_ = mod3PcbTemperature;
   emit mod3PcbTemperatureReceived(mod3PcbTemperature_);
}

void BatteryData::setMod3CellTemperature(double mod3CellTemperature)
{
   mod3CellTemperature_ = mod3CellTemperature;
   emit mod3CellTemperatureReceived(mod3CellTemperature_);
}

void BatteryData::setMod3CellVoltages(QList<double> mod3CellVoltages)
{
   mod3CellVoltages_ = mod3CellVoltages;
   emit mod3CellVoltagesReceived(mod3CellVoltages_);
}

void BatteryData::setBatteryVoltage(double batteryVoltage)
{
   batteryVoltage_ = batteryVoltage;
   emit batteryVoltageReceived(batteryVoltage_);
}

void BatteryData::setBatteryCurrent(double batteryCurrent)
{
   batteryCurrent_ = batteryCurrent;
   emit batteryCurrentReceived(batteryCurrent_);
}


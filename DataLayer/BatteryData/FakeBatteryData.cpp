#include "FakeBatteryData.h"

FakeBatteryData::FakeBatteryData()
{
}

FakeBatteryData::~FakeBatteryData()
{
}

/*FakeBatteryData "Gets"*/
double FakeBatteryData::mod0PcbTemperature() const
{           
 return 1;
}
double FakeBatteryData::mod0CellTemperature() const
{           
 return 2;
}

QList<double> FakeBatteryData::mod0CellVoltages() const
{
   QList<double> mod0CellVoltages= new QList();
   mod0CellVoltages.append(3);
   return mod0CellVoltages;
}

double FakeBatteryData::mod1PcbTemperature() const
{           
 return 4;
}
double FakeBatteryData::mod1CellTemperature() const
{           
 return 5;
}

QList<double> FakeBatteryData::mod1CellVoltages() const
{
   QList<double> mod1CellVoltages= new QList();
   mod1CellVoltages.append(6);
   return mod1CellVoltages;
}

double FakeBatteryData::mod2PcbTemperature() const
{           
 return 7;
}
double FakeBatteryData::mod2CellTemperature() const
{           
 return 8;
}

QList<double> FakeBatteryData::mod2CellVoltages() const
{
   QList<double> mod2CellVoltages= new QList();
   mod2CellVoltages.append(9);
   return mod2CellVoltages;
}

double FakeBatteryData::mod3PcbTemperature() const
{           
  return 10;
}
double FakeBatteryData::mod3CellTemperature() const
{           
  return 11;
}

QList<double> FakeBatteryData::mod3CellVoltages() const
{
   QList<double> mod3CellVoltages= new QList();
   mod3CellVoltages.append(12);
   return mod3CellVoltages;
}

double FakeBatteryData::batteryVoltage() const
{           
  return 13;
}
double FakeBatteryData::batteryCurrent() const
{           
  return 14;
}                      

/*FakeBatteryData "Sets"*/
void FakeBatteryData::setMod0PcbTemperature(double mod0PcbTemperature){}
void FakeBatteryData::setMod0CellTemperature(double mod0CellTemperature){}

void FakeBatteryData::setMod0CellVoltages(QList<double> mod0CellVoltages){}

void FakeBatteryData::setMod1PcbTemperature(double mod1PcbTemperature){}
void FakeBatteryData::setMod1CellTemperature(double mod1CellTemperature){}

void FakeBatteryData::setMod1CellVoltages(QList<double> mod1CellVoltages){}

void FakeBatteryData::setMod2PcbTemperature(double mod2PcbTemperature){}
void FakeBatteryData::setMod2CellTemperature(double mod2CellTemperature){}

void FakeBatteryData::setMod2CellVoltages(QList<double> mod2CellVoltages){}

void FakeBatteryData::setMod3PcbTemperature(double mod3PcbTemperature){}

void FakeBatteryData::setMod3CellTemperature(double mod3CellTemperature){}

void FakeBatteryData::setMod3CellVoltages(QList<double> mod3CellVoltages){}

void FakeBatteryData::setBatteryVoltage(double batteryVoltage){}

void FakeBatteryData::setBatteryCurrent(double batteryCurrent){}


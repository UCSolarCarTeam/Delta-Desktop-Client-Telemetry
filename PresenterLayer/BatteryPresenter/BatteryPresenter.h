#pragma once

#include <QObject>
class I_BatteryData;

class BatteryPresenter : public QObject
{
	Q_OBJECT
public:
	explicit BatteryPresenter(const I_BatteryData& batteryData);

private:
	void relayBatteryData();

	const I_BatteryData& batteryData_;

signals:
   void mod0PcbTemperatureReceived(double mod0PcbTemperature);
   void mod0CellTemperatureReceived(double mod0CellTemperature);
   void mod0CellVoltagesReceived(double mod0CellVoltages);

   void mod1PcbTemperatureReceived(double mod1PcbTemperature);
   void mod1CellTemperatureReceived(double mod1CellTemperature);
   void mod1CellVoltagesReceived(double mod1CellVoltages);

   void mod2PcbTemperatureReceived(double mod2PcbTemperature);
   void mod2CellTemperatureReceived(double mod2CellTemperature);
   void mod2CellVoltagesReceived(double mod2CellVoltages);

   void mod3PcbTemperatureReceived(double mod3PcbTemperature);
   void mod3CellTemperatureReceived(double mod3CellTemperature);
   void mod3CellVoltagesReceived(double mod3CellVoltages);

   void batteryVoltageReceived(double batteryVoltage);
   void batteryCurrentReceived(double batteryCurent);
};

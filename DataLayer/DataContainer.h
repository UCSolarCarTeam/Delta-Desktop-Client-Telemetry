#pragma once

#include <QScopedPointer>

class I_BatteryData;
class I_FaultsData;
class I_PowerData;
class I_VehicleData;

class DataContainer
{
public:
   DataContainer();
   ~DataContainer();

   I_PowerData& powerData();
   I_VehicleData& vehicleData();
   I_BatteryData& batteryData();
   I_FaultsData& faultsData();

private:
	QScopedPointer<I_VehicleData> vehicleData_;
	QScopedPointer<I_PowerData> powerData_;
	QScopedPointer<I_BatteryData> batteryData_;
   QScopedPointer<I_FaultsData> faultsData_;
};

#pragma once

#include <QScopedPointer>

class I_ArrayData;
class I_VehicleData;
class I_PowerData;
class I_BatteryData;

class DataContainer
{
public:
   DataContainer();
   ~DataContainer();

   I_ArrayData& arrayData();
   I_PowerData& powerData();
   I_VehicleData& vehicleData();
   I_BatteryData& batteryData();

private:
	QScopedPointer<I_ArrayData> arrayData_;
	QScopedPointer<I_VehicleData> vehicleData_;
	QScopedPointer<I_PowerData> powerData_;
	QScopedPointer<I_BatteryData> batteryData_;
};

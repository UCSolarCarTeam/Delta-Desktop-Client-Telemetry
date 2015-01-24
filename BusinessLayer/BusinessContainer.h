#pragma once

#include <QScopedPointer>

class ArrayData;
class VehicleData;
class PowerData;
class BatteryData;
class DebugHandler;

class BusinessContainer
{
public:
    BusinessContain2er();
    ~BusinessContainer();

private:
	QScopedPointer<ArrayData> arrayData_;
	QScopedPointer<VehicleData> vehicleData_; 
	QScopedPointer<PowerData> powerData_;
	QScopedPointer<BatteryData> batteryData_;
	QScopedPointer<DebugHandler> debugHandler_;	
};



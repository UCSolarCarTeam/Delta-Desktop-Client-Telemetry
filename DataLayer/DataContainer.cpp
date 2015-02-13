#include <QSharedPointer>

#include "ArrayData/ArrayData.h"
#include "VehicleData/VehicleData.h"
#include "PowerData/PowerData.h"
#include "BatteryData/BatteryData.h"

#include "DataContainer.h"

DataContainer::DataContainer()
: arrayData_(new ArrayData())
, vehicleData_(new VehicleData())
, powerData_(new PowerData())
, batteryData_(new BatteryData()) 
{
}
QSharedPointer<I_ArrayData> DataContainer::arrayData()
{
	return arrayData_;
}
QSharedPointer<I_PowerData> DataContainer::powerData()
{
	return powerData_;
}
QSharedPointer<I_VehicleData> DataContainer::vehicleData()
{
	return vehicleData_;
}
QSharedPointer<I_BatteryData> DataContainer::batteryData()
{
	return batteryData_;
}
DataContainer::~DataContainer()
{
}


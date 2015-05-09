#include "ArrayData/ArrayData.h"
#include "BatteryData/BatteryData.h"
#include "DataContainer.h"
#include "PowerData/PowerData.h"
#include "VehicleData/VehicleData.h"

DataContainer::DataContainer()
: arrayData_(new ArrayData())
, vehicleData_(new VehicleData())
, powerData_(new PowerData())
, batteryData_(new BatteryData())
{
}

DataContainer::~DataContainer()
{
}

I_ArrayData& DataContainer::arrayData()
{
   return *arrayData_;
}

I_PowerData& DataContainer::powerData()
{
   return *powerData_;
}

I_VehicleData& DataContainer::vehicleData()
{
   return *vehicleData_;
}

I_BatteryData& DataContainer::batteryData()
{
   return *batteryData_;
}

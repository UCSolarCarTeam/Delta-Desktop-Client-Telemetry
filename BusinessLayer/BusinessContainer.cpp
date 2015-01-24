#include "BusinessContainer.h"

#include "ArrayData/ArrayData.h"
#include "VehicleData/VehicleData.h"
#include "PowerData/PowerData.h"
#include "BatteryData/BatteryData.h"
#include "DebugHandler/DebugHandler.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer()
: arrayData_(new ArrayData())
, vehicleData_(new Vehicle()Data())
, powerData_(new PowerData())
, batteryData_(new BatteryData())
, debugHandler_(new DebugHandler(*connectionservice_, *dataParser_, defaultFilename))
{
}

BusinessContainer::~BusinessContainer()
{
}


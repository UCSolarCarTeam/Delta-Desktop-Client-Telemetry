#include "BusinessContainer.h"

#include "DataLayer/DataContainer.h"
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
: dataContainer_(new DataContainer())
, debugHandler_(new DebugHandler(*connectionservice_, *dataParser_, defaultFilename))
{
}

DebugHandler& debugHandler()
{
	return debugHandler_;
} 

BusinessContainer::~BusinessContainer()
{
}


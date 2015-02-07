#include "BusinessContainer.h"

#include "DataLayer/DataContainer.h"
#include "DebugHandler/DebugHandler.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer()
: dataContainer_(new DataContainer())
, debugHandler_(new DebugHandler(dataContainer_->connectionService(),
                                 dataContainer_->dataParser(),
                                 defaultFilename))
{
}

DebugHandler& debugHandler()
{
	return debugHandler_;
} 

BusinessContainer::~BusinessContainer()
{
}


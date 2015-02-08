#include <QSharedPointer>

#include "DataLayer/DataContainer.h"
#include "DebugHandler/DebugHandler.h"

#include "BusinessContainer.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer()
: dataContainer_(new DataContainer())
, debugHandler_(new DebugHandler(*(dataContainer_->connectionService()),
                                 *(dataContainer_->dataParser()),
                                 defaultFilename))
{
}

QSharedPointer<DebugHandler> BusinessContainer::debugHandler()
{
	return debugHandler_;
} 

BusinessContainer::~BusinessContainer()
{
}


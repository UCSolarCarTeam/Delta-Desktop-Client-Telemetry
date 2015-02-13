#include <QSharedPointer>

#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "DebugHandler/DebugHandler.h"

#include "BusinessContainer.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer(QSharedPointer<DataContainer> dataContainer,
									 QSharedPointer<CommunicationContainer> communicationContainer)
: dataContainer_(dataContainer)
, communicationContainer_(communicationContainer)
, debugHandler_(new DebugHandler(*(communicationContainer_->connectionService()),
                                 *(communicationContainer_->dataParser()),
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


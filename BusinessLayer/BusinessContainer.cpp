#include <QSharedPointer>

#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "LoggerService/LoggerService.h"

#include "BusinessContainer.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer(QSharedPointer<DataContainer> dataContainer,
									 QSharedPointer<CommunicationContainer> communicationContainer)
: dataContainer_(dataContainer)
, communicationContainer_(communicationContainer)
, loggerService_(new LoggerService(*(communicationContainer_->connectionService()),
                                 *(communicationContainer_->dataParser()),
                                 defaultFilename))
{
}

QSharedPointer<LoggerService> BusinessContainer::loggerService()
{
	return loggerService_;
} 

BusinessContainer::~BusinessContainer()
{
}


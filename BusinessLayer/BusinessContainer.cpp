#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "LoggerService/LoggerService.h"

namespace
{
	const QString defaultFilename = "SolarCarDebugLog";
}

BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer)
: loggerService_(new LoggerService(communicationContainer.connectionService(),
      communicationContainer.dataParser(),
      defaultFilename))
{
}

BusinessContainer::~BusinessContainer()
{
}

LoggerService& BusinessContainer::loggerService()
{
   return *loggerService_;
}

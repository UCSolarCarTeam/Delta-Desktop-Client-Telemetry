#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "LoggerService/LoggerService.h"

BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer)
: loggerService_(new LoggerService(communicationContainer.connectionService(),
   communicationContainer.packetSynchronizer(),
   communicationContainer.packetDecoder()))
{
}

BusinessContainer::~BusinessContainer()
{
}

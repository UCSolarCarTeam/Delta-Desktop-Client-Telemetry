#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "LoggerService/LoggerService.h"
#include "PlaybackService/PlaybackService.h"

BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer)
: loggerService_(new LoggerService(communicationContainer.connectionService(),
   communicationContainer.packetSynchronizer(),
   communicationContainer.packetDecoder()))
, playbackService_(new PlaybackService(
   communicationContainer.dataInjectionService()))
{
}

BusinessContainer::~BusinessContainer()
{
}

I_PlaybackService& BusinessContainer::playbackService()
{
   return *playbackService_;
}

#include "BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "LoggerService/LoggerService.h"
#include "PlaybackService/PlaybackService.h"
#include "CommunicationsMonitoringService/CommunicationsMonitoringService.h"

BusinessContainer::BusinessContainer(CommunicationContainer& communicationContainer)
: loggerService_(new LoggerService(
   communicationContainer.packetSynchronizer(),
   communicationContainer.packetDecoder()))
, playbackService_(new PlaybackService(
   communicationContainer.dataInjectionService()))
, communicationsMonitoringService_(new CommunicationsMonitoringService(
	communicationContainer.packetChecksumChecker()))
{
}

BusinessContainer::~BusinessContainer()
{
}

I_PlaybackService& BusinessContainer::playbackService()
{
   return *playbackService_;
}

I_CommunicationsMonitoringService& BusinessContainer::communicationsMonitoringService()
{
	return *communicationsMonitoringService_;
}

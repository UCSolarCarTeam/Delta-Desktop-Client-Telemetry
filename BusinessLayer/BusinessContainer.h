#pragma once

#include <QScopedPointer>
class CommunicationContainer;
class LoggerService;
class I_PlaybackService;
class I_CommunicationsMonitoringService;

class BusinessContainer
{
public:
   explicit BusinessContainer(CommunicationContainer& communicationContainer);
   ~BusinessContainer();

   I_PlaybackService& playbackService();
   I_CommunicationsMonitoringService& communicationsMonitoringService();

private:
   QScopedPointer<LoggerService> loggerService_;
   QScopedPointer<I_PlaybackService> playbackService_;
   QScopedPointer<I_CommunicationsMonitoringService> communicationsMonitoringService_;
};

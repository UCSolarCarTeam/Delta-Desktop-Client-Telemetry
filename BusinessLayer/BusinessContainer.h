#pragma once

#include <QScopedPointer>
class CommunicationContainer;
class I_PlaybackService;
class LoggerService;
class PlaybackService;

class BusinessContainer
{
public:
   explicit BusinessContainer(CommunicationContainer& communicationContainer);
   ~BusinessContainer();

   I_PlaybackService& playbackService();

private:
   QScopedPointer<LoggerService> loggerService_;
   QScopedPointer<PlaybackService> playbackService_;
};

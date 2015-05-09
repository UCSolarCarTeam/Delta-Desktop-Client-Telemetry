#pragma once

#include <QScopedPointer>
class CommunicationContainer;
class LoggerService;

class BusinessContainer
{
public:
   explicit BusinessContainer(CommunicationContainer& communicationContainer);
   ~BusinessContainer();

   LoggerService& loggerService();

private:
    QScopedPointer<LoggerService> loggerService_;
};

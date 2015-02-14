#pragma once

#include <QSharedPointer>

class DataContainer;
class CommunicationContainer;
class LoggerService;

class BusinessContainer
{
public:
    QSharedPointer<LoggerService> loggerService();

    explicit BusinessContainer(QSharedPointer<DataContainer> dataContainer, 
    						   QSharedPointer<CommunicationContainer> communicationContainer);
    ~BusinessContainer();

private:
    QSharedPointer<DataContainer> dataContainer_;
    QSharedPointer<CommunicationContainer> communicationContainer_;
    QSharedPointer<LoggerService> loggerService_;
};



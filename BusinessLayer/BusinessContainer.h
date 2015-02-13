#pragma once

#include <QSharedPointer>

class DataContainer;
class CommunicationContainer;
class DebugHandler;

class BusinessContainer
{
public:
    QSharedPointer<DebugHandler> debugHandler();

    explicit BusinessContainer(QSharedPointer<DataContainer> dataContainer, 
    						   QSharedPointer<CommunicationContainer> communicationContainer);
    ~BusinessContainer();

private:
    QSharedPointer<DataContainer> dataContainer_;
    QSharedPointer<CommunicationContainer> communicationContainer_;
    QSharedPointer<DebugHandler> debugHandler_;
};



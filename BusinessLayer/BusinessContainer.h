#pragma once

#include <QSharedPointer>

class DataContainer;
class DebugHandler;

class BusinessContainer
{
public:
    QSharedPointer<DebugHandler> debugHandler();

    BusinessContainer();
    ~BusinessContainer();

private:
    QSharedPointer<DataContainer> dataContainer_;
    QSharedPointer<DebugHandler> debugHandler_;
};



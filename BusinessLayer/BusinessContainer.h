#pragma once

#include <QSharedPointer>

class DataContainer;
class DebugHandler;

class BusinessContainer
{
public:
	DebugHandler& debugHandler();

    BusinessContainer();
    ~BusinessContainer();

private:
    QSharedPointer<DataContainer> dataContainer_;
    QSharedPointer<DebugHandler> debugHandler_;
};



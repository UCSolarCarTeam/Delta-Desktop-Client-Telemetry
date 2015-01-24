#pragma once

#include <QScopedPointer>

class DataContainer;
class DebugHandler;

class BusinessContainer
{
public:
	DebugHandler& debugHandler();

    BusinessContainer();
    ~BusinessContainer();

private:
	QScopedPointer<DataContainer> dataContainer_;
	QScopedPointer<DebugHandler> debugHandler_;	
};



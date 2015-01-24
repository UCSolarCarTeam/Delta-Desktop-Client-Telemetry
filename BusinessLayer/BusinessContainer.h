#pragma once

#include <QScopedPointer>

class DataContainer;
class DebugHandler;

class BusinessContainer
{
public:
    BusinessContain2er();
    ~BusinessContainer();

private:
	QScopedPointer<DataContainer> dataContainer_;
	QScopedPointer<DebugHandler> debugHandler_;	
};



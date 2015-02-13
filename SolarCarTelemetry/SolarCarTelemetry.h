#pragma once

#include <QApplication>
#include <QSharedPointer>

class CommunicationContainer;
class DataContainer;
class BusinessContainer;
class PresenterContainer;
class ViewContainer;

class SolarCarTelemetry : public QApplication
{
public:
    explicit SolarCarTelemetry(int &argc, char **argv);
    ~SolarCarTelemetry();

private:
	QSharedPointer<DataContainer> dataContainer_;
	QSharedPointer<CommunicationContainer> communicationContainer_;
	QSharedPointer<BusinessContainer> businessContainer_;
	QSharedPointer<PresenterContainer> presenterContainer_;
	QSharedPointer<ViewContainer> viewContainer_;
};

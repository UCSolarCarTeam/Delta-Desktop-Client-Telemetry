#pragma once

#include <QApplication>
#include <QScopedPointer>

class CommunicationContainer;
class DataContainer;
class BusinessContainer;
class PresenterContainer;
class ViewContainer;

class SolarCarTelemetry : public QApplication
{
public:
   SolarCarTelemetry(int &argc, char **argv);
   ~SolarCarTelemetry();

private:
   QScopedPointer<DataContainer> dataContainer_;
   QScopedPointer<CommunicationContainer> communicationContainer_;
   QScopedPointer<BusinessContainer> businessContainer_;
   QScopedPointer<PresenterContainer> presenterContainer_;
   QScopedPointer<ViewContainer> viewContainer_;
};

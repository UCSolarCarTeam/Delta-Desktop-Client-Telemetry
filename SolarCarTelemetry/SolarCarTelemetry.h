#pragma once

#include <QApplication>
#include <QScopedPointer>
class DataParser;
class DataPopulator;
class DisplayPresenter;
class DisplayView;
class I_ConnectionService;
class QSerialPort;
class SolarCarTestUI;
class TelemetryData;

class SolarCarTelemetry : public QApplication
{
public:

   explicit SolarCarTelemetry(int &argc, char **argv);
   ~SolarCarTelemetry();

private:
   QScopedPointer<I_ConnectionService> connectionService_;
   QScopedPointer<TelemetryData> data_;
   QScopedPointer<QSerialPort> port_;
   QScopedPointer<DataParser> dataParser_;
   QScopedPointer<DataPopulator> dataPopulator_;
   QScopedPointer<DisplayPresenter> displayPresenter_;
   QScopedPointer<SolarCarTestUI> mainWindow_;
   QScopedPointer<DisplayView> displayView_;
};

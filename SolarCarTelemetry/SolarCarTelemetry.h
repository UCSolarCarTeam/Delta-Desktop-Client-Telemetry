#pragma once

#include <QApplication>
#include <QScopedPointer>

class DataParser;
class DataPopulator;
class DebugHandler;
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
   QScopedPointer<QSerialPort> port_;
   QScopedPointer<I_ConnectionService> connectionService_;
   QScopedPointer<TelemetryData> data_;
   QScopedPointer<DataParser> dataParser_;
   QScopedPointer<DataPopulator> dataPopulator_;
   QScopedPointer<DebugHandler> debugHandler_;
   QScopedPointer<DisplayPresenter> displayPresenter_;
   QScopedPointer<SolarCarTestUI> mainWindow_;
   QScopedPointer<DisplayView> displayView_;
};

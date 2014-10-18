#pragma once

#include <QApplication>
#include <QScopedPointer>
class TelemetryData;
class DataParser;
class DataPopulator;
class QSerialPort;

class SolarCarTelemetry : public QApplication
{
public:

   explicit SolarCarTelemetry(int &argc, char **argv);
   ~SolarCarTelemetry();

private:
   QScopedPointer<TelemetryData> data_;
   QScopedPointer<QSerialPort> port_;
   QScopedPointer<DataParser> dataParser_;
   QScopedPointer<DataPopulator> dataPopulator_;
};

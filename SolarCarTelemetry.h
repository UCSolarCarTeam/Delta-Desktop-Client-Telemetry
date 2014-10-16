#pragma once

#include <QScopedPointer>
class TelemetryData;
class DataParser;
class DataPopulator;
class QSerialPort;

class SolarCarTelemetry
{
public:
  explicit SolarCarTelemetry();
  ~SolarCarTelemetry();

private:
  QScopedPointer<TelemetryData> data_;
  QScopedPointer<QSerialPort> port_;
  QScopedPointer<DataParser> dataParser_;
  QScopedPointer<DataPopulator> dataPopulator_;
};

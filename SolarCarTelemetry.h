#pragma once

#include <QScopedPointer>
class Data;
class DataParser;
class DataPopulator;
class QSerialPort;

class SolarCarTelemetry
{
public:
  explicit SolarCarTelemetry();
  ~SolarCarTelemetry();

private:
  QScopedPointer<Data> data_;
  QScopedPointer<QSerialPort> port_;
  QScopedPointer<DataParser> dataParser_;
  QScopedPointer<DataPopulator> dataPopulator_;
};

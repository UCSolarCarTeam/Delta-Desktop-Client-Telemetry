#pragma once
#include <QObject>

class I_DataParser;
class I_TelemetryData;

class DataPopulator : public QObject
{
  Q_OBJECT
public:
  DataPopulator(const I_DataParser& dataParser, I_TelemetryData& data);

private slots:
  void handleDataReceived(int id, int value);

private:
  const I_DataParser& dataParser_;
  I_TelemetryData& data_;
};

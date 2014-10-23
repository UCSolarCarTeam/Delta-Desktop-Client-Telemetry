#pragma once

#include <QObject>
class I_TelemetryData;

class MainDisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit MainDisplayPresenter(const I_TelemetryData& telemetryData);

signals:

public slots:

private:
   void relayTelemetryData();

private:
   const I_TelemetryData& telemetryData_;
};


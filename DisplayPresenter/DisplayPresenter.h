#pragma once

#include <QObject>
class I_TelemetryData;

class DisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit DisplayPresenter(const I_TelemetryData& telemetryData);

signals:

public slots:

private:
   void relayTelemetryData();

private:
   const I_TelemetryData& telemetryData_;
};


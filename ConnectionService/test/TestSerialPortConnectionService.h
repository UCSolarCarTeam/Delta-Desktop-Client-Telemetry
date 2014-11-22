#pragma once

#include <QtTest/QtTest>
#include "../../ConnectionService/SerialPortConnectionService.h"

class TestSerialPortConnectionService : public QObject
{
   Q_OBJECT
public:
    TestSerialPortConnectionService();

private slots:
    void init();
    void cleanup();

private:
    QScopedPointer<SerialPortConnectionService> patient_;  //testing this.
    QScopedPointer<FakeDataParser> dataParser_;
    QScopedPointer<TelemetryData> telemetry_;
};

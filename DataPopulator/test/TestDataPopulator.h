#pragma once

#include <QtTest/QtTest>
#include "../../DataPopulator/DataPopulator.h"
#include "../../DataParser/FakeDataParser.h"
#include "../../TelemetryData/TelemetryData.h"

class TestDataPopulator : public QObject
{
   Q_OBJECT
public:
    TestDataPopulator();

private slots:
    void init();
    void cleanup();

    void functionTestsDouble();
    void functionTestsDouble_data();

private:
    QScopedPointer<DataPopulator> patient_;  //testing this.
    QScopedPointer<FakeDataParser> dataParser_;
    QScopedPointer<TelemetryData> telemetry_;
};

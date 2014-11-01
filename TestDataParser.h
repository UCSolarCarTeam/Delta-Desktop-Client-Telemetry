#pragma once

#include <QtTest/QtTest>
#include "DataParser/DataParser.h"
#include "ConnectionService/FakeConnectionService.h"

class TestDataParser
{
public:
    TestDataParser();

private slots:
    void init();
    void cleanup();

    void willEmitDataReceived();

private:
    QScopedPointer<DataParser> patient_;
    QScopedPointer<FakeConnectionService> connection_;
    QScopedPointer<QBuffer> device_;
};

#endif // TESTDATAPARSER_H

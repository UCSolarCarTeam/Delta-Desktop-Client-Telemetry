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
    void willEmitDataReceived_data();

//    void willNotEmitDataReceivedMoreThanOneHash();


private:
    QScopedPointer<DataParser> patient_;  //testing this.
    QScopedPointer<FakeConnectionService> connection_;
    QScopedPointer<QBuffer> device_;
};

#endif // TESTDATAPARSER_H

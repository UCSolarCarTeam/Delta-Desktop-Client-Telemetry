#pragma once

#include <QtTest/QtTest>
#include "../../DataParser/DataParser.h"
#include "../../ConnectionService/FakeConnectionService.h"

class TestDataParser : public QObject
{
   Q_OBJECT
public:
    TestDataParser();

private slots:
    void init();
    void cleanup();

    void willEmitDataReceived();
    void willEmitDataReceived_data();

    //SAMS FUNCTIONS <
    void moreThanOneHash();
    void moreThanOneHash_data();

    void noHash();
    void noHash_data();

    void noASCIINumbers();
    void noASCIINumbers_data();

    void noEmitSignalConnectionSucceeded();
    void noEmitSignalConnectionSucceeded_data();

    void invalidChars();
    void invalidChars_data();
    //>

//    void willNotEmitDataReceivedMoreThanOneHash();

private:
    QScopedPointer<DataParser> patient_;  //testing this.
    QScopedPointer<FakeConnectionService> connection_;
    QScopedPointer<QBuffer> device_;
};

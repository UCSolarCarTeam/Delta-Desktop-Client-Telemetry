#pragma once

#include <QtTest/QtTest>
#include "../../DataPopulator/DataPopulator.h"
#include "../../ConnectionService/FakeConnectionService.h"

class TestDataPopulator : public QObject
{
   Q_OBJECT
public:
    TestDataPopulator();

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
    QScopedPointer<DataPopulator> patient_;  //testing this.
    QScopedPointer<FakeConnectionService> connection_;
    QScopedPointer<QBuffer> device_;
};

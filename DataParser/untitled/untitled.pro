TEMPLATE = app

QT += core gui testlib

SOURCES += \
    ../../TestDataParser.cpp \
    ../DataParser.cpp \
    ../../ConnectionService/FakeConnectionService.cpp

HEADERS += \
    ../../TestDataParser.h \
    ../DataParser.h \
    ../../ConnectionService/FakeConnectionService.h

TARGET = dataParserTest


# Default rules for deployment.


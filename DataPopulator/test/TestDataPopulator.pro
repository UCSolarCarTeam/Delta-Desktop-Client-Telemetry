QT += core testlib
TEMPLATE = app

TARGET =dataPopulatorTest

RCC_DIR= ../../../release
DESTDIR = ../../../release
OBJECTS_DIR = ../../../release/.obj
MOC_DIR = ../../../release/.moc
RCC_DIR = ../../../release/.rcc
UI_DIR = ../../../release/.ui

SOURCES += \
    TestDataPopulator.cpp \
    ../DataPopulator.cpp \
    ../../TelemetryData/TelemetryData.cpp \
    ../../DataParser/FakeDataParser.cpp

HEADERS += \
    TestDataPopulator.h \
    ../DataPopulator.h \
    ../I_DataPopulator.h \
    ../../DataParser/FakeDataParser.h \
    ../../TelemetryData/TelemetryData.h \
    ../../TelemetryData/I_TelemetryData.h \
    ../../DataParser/I_DataParser.h


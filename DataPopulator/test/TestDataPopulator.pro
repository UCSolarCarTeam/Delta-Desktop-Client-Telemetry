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
    ../../DataParser/FakeDataParser.cpp \
    ../../ConnectionService/I_ConnectionService.cpp \
    ../../ConnectionService/SerialPortConnectionService.cpp \
    TestDataPopulator.cpp

HEADERS += \
    TestDataPopulator.h \
    ../DataPopulator.h \
    ../I_DataPopulator.h \
    ../../ConnectionService/I_ConnectionService.h \
    ../../DataParser/FakeDataParser.h \
    TestDataPopulator.h \
    ../../ConnectionService/SerialPortConnectionService.h \
    ../../DataParser/I_DataParser.h


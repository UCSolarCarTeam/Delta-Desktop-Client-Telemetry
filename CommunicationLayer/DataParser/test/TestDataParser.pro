QT += core testlib
TEMPLATE = app

TARGET =dataParserTest

RCC_DIR= ../../../release
DESTDIR = ../../../release
OBJECTS_DIR = ../../../release/.obj
MOC_DIR = ../../../release/.moc
RCC_DIR = ../../../release/.rcc
UI_DIR = ../../../release/.ui

SOURCES += \
    TestDataParser.cpp \
    ../DataParser.cpp \
    ../../ConnectionService/FakeConnectionService.cpp

HEADERS += \
    TestDataParser.h \
    ../DataParser.h \
    ../I_DataParser.h \
    ../../ConnectionService/I_ConnectionService.h \
    ../../ConnectionService/FakeConnectionService.h



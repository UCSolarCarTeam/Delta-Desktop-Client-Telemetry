QT += core testlib serialport
TEMPLATE = app

TARGET =serialPortConnectionServiceTest

RCC_DIR= ../../../release
DESTDIR = ../../../release
OBJECTS_DIR = ../../../release/.obj
MOC_DIR = ../../../release/.moc
RCC_DIR = ../../../release/.rcc
UI_DIR = ../../../release/.ui

SOURCES += \
    TestSerialPortConnectionService.cpp \
    ../SerialPortConnectionService.cpp \

HEADERS += \
    TestSerialPortConnectionService.h \
    ../SerialPortConnectionService.h \
    ../I_ConnectionService.h \



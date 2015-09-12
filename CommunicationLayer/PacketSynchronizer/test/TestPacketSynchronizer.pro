QT += core testlib
TEMPLATE = app

TARGET = packetSynchronizerTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   TestPacketSynchronizer.cpp \
   FakeSerialPort.cpp \
   ../PacketSynchronizer.cpp \
   ../../ConnectionService/FakeConnectionService.cpp

HEADERS += \
   TestPacketSynchronizer.h \
   FakeSerialPort.h \
   ../PacketSynchronizer.h \
   ../I_PacketSynchronizer.h \
   ../../ConnectionService/I_ConnectionService.h \
   ../../ConnectionService/FakeConnectionService.h

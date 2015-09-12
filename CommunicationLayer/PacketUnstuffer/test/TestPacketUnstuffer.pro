QT += core testlib
TEMPLATE = app

TARGET = packetUnstufferTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   TestPacketUnstuffer.cpp \
   ../PacketUnstuffer.cpp \
   ../../PacketSynchronizer/FakePacketSynchronizer.cpp \

HEADERS += \
   TestPacketUnstuffer.h \
   ../PacketUnstuffer.h \
   ../I_PacketUnstuffer.h \
   ../../PacketSynchronizer/FakePacketSynchronizer.h \
   ../../PacketSynchronizer/I_PacketSynchronizer.h \

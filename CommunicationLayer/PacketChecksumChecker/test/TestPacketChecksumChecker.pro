QT += core testlib
TEMPLATE = app

TARGET = checksumCheckerTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   *.cpp \
   ../PacketChecksumChecker.cpp \
   ../../PacketUnstuffer/FakePacketUnstuffer.cpp \

HEADERS += \
   *.h \
   ../PacketChecksumChecker.h \
   ../I_PacketChecksumChecker.h \
   ../../PacketUnstuffer/FakePacketUnstuffer.h \
   ../../PacketUnstuffer/I_PacketUnstuffer.h \

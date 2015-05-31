QT += core testlib
TEMPLATE = app

TARGET = packetDecoderTest

RCC_DIR= ../../../../release

DESTDIR = ../../../../release
OBJECTS_DIR = ../../../../release/.obj
MOC_DIR = ../../../../release/.moc
RCC_DIR = ../../../../release/.rcc
UI_DIR = ../../../../release/.ui

SOURCES += \
   *.cpp \
   ../PacketDecoder.cpp \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.cpp \
   ../../MessagingFramework/*.cpp

HEADERS += \
   *.h \
   ../PacketDecoder.h \
   ../I_PacketDecoder.h \
   ../../PacketChecksumChecker/I_PacketChecksumChecker.h \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.h \
   ../../MessagingFramework/*.h

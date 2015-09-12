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
   TestPacketDecoder.cpp \
   ../PacketDecoder.cpp \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.cpp \
   ../../MessagingFramework/BatteryDataMessage.cpp \
   ../../MessagingFramework/BatteryFaults.cpp \
   ../../MessagingFramework/CmuDataMessage.cpp \
   ../../MessagingFramework/DriverControlDetails.cpp \
   ../../MessagingFramework/FaultsMessage.cpp \
   ../../MessagingFramework/KeyDriverControlTelemetry.cpp \
   ../../MessagingFramework/LimitFlags.cpp \
   ../../MessagingFramework/MessageDecodingHelpers.cpp \
   ../../MessagingFramework/MessageDefines.cpp \
   ../../MessagingFramework/MotorFaults.cpp \
   ../../MessagingFramework/MpptDataMessage.cpp \
   ../../MessagingFramework/MpptDefines.cpp \

HEADERS += \
   TestPacketDecoder.h \
   ../PacketDecoder.h \
   ../I_PacketDecoder.h \
   ../../PacketChecksumChecker/I_PacketChecksumChecker.h \
   ../../PacketChecksumChecker/FakePacketChecksumChecker.h \
   ../../MessagingFramework/BatteryDataMessage.h \
   ../../MessagingFramework/BatteryFaults.h \
   ../../MessagingFramework/CmuDataMessage.h \
   ../../MessagingFramework/DriverControlDetails.h \
   ../../MessagingFramework/FaultsMessage.h \
   ../../MessagingFramework/KeyDriverControlTelemetry.h \
   ../../MessagingFramework/LimitFlags.h \
   ../../MessagingFramework/MessageDecodingHelpers.h \
   ../../MessagingFramework/MessageDefines.h \
   ../../MessagingFramework/MotorFaults.h \
   ../../MessagingFramework/MpptDataMessage.h \
   ../../MessagingFramework/MpptDefines.h \

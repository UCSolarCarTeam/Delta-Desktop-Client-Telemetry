#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
   error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../release/.lib

SOURCES += \
    CommDeviceControl/CommDeviceManager.cpp \
    CommDeviceControl/ConnectionController.cpp \
    CommDeviceControl/RadioConnectionService.cpp \
    CommDeviceControl/UdpConnectionService.cpp \
    CommDeviceControl/UdpMessageForwarder.cpp \
    CommunicationContainer.cpp \
    DataPopulators/BatteryPopulator.cpp \
    DataPopulators/CmuPopulator.cpp \
    DataPopulators/DriverDetailsPopulator.cpp \
    DataPopulators/FaultsPopulator.cpp \
    DataPopulators/KeyDriverControlPopulator.cpp \
    MessagingFramework/BatteryDataMessage.cpp \
    MessagingFramework/BatteryFaults.cpp \
    MessagingFramework/CmuDataMessage.cpp \
    MessagingFramework/DriverControlDetails.cpp \
    MessagingFramework/FaultsMessage.cpp \
    MessagingFramework/KeyDriverControlTelemetry.cpp \
    MessagingFramework/LimitFlags.cpp \
    MessagingFramework/MessageDecodingHelpers.cpp \
    MessagingFramework/MessageDefines.cpp \
    MessagingFramework/MotorFaults.cpp \
    PacketChecksumChecker/PacketChecksumChecker.cpp \
    PacketDecoder/PacketDecoder.cpp \
    PacketSynchronizer/PacketSynchronizer.cpp \
    PacketUnstuffer/PacketUnstuffer.cpp

HEADERS  += \
    CommunicationContainer.h \
    CommDeviceControl/CommDeviceManager.h \
    CommDeviceControl/ConnectionController.h \
    CommDeviceControl/I_CommDevice.h \
    CommDeviceControl/I_ConnectionService.h \
    CommDeviceControl/RadioConnectionService.h \
    CommDeviceControl/UdpConnectionService.h \
    CommDeviceControl/UdpMessageForwarder.h \
    DataPopulators/BatteryPopulator.h \
    DataPopulators/CmuPopulator.h \
    DataPopulators/DriverDetailsPopulator.h \
    DataPopulators/FaultsPopulator.h \
    DataPopulators/KeyDriverControlPopulator.h \
    MessagingFramework/BatteryDataMessage.h \
    MessagingFramework/BatteryFaults.h \
    MessagingFramework/CmuDataMessage.h \
    MessagingFramework/DriverControlDetails.h \
    MessagingFramework/FaultsMessage.h \
    MessagingFramework/KeyDriverControlTelemetry.h \
    MessagingFramework/LimitFlags.h \
    MessagingFramework/MessageDecodingHelpers.h \
    MessagingFramework/MessageDefines.h \
    MessagingFramework/MotorFaults.h \
    PacketChecksumChecker/I_PacketChecksumChecker.h \
    PacketChecksumChecker/PacketChecksumChecker.h \
    PacketDecoder/I_PacketDecoder.h \
    PacketDecoder/PacketDecoder.h \
    PacketSynchronizer/I_PacketSynchronizer.h \
    PacketSynchronizer/PacketSynchronizer.h \
    PacketUnstuffer/I_DataInjectionService.h \
    PacketUnstuffer/I_PacketUnstuffer.h \
    PacketUnstuffer/PacketUnstuffer.h

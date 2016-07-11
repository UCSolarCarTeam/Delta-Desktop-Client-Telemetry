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
    BusinessContainer.cpp \
    LoggerService/LoggerService.cpp \
    PlaybackService/PlaybackService.cpp \
    CommunicationsMonitoringService/CommunicationsMonitoringService.cpp

HEADERS  += \
    BusinessContainer.h \
    LoggerService/LoggerService.h \
    PlaybackService/I_PlaybackService.h \
    PlaybackService/PlaybackService.h \
    CommunicationsMonitoringService/CommunicationsMonitoringService.h \
    CommunicationsMonitoringService/I_CommunicationsMonitoringService.h

#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

TEMPLATE = app

LIBS += -L../release/.lib -lBusinessLayer -lCommunicationLayer -lDataLayer -lPresenterLayer -lViewLayer

! include( ../common.pri ) {
   error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../release/.lib/*

TARGET = ../release/SchulichDeltaDesktopTelemetry
DESTDIR = ../release

SOURCES += \
    main.cpp \
    SchulichDeltaDesktopTelemetry.cpp

HEADERS  += \
    SchulichDeltaDesktopTelemetry.h

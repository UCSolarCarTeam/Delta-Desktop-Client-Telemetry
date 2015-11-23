TEMPLATE = app

# This MUST be before the common.pri since these need to be listed before the qwt library
LIBS += -L../../build/.lib -lViewLayer -lBusinessLayer -lCommunicationLayer -lPresenterLayer -lDataLayer

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

PRE_TARGETDEPS += \
   ../../build/.lib/*

TARGET = SolarCarTelemetry
# DESTDIR = ../../build

HEADERS += \
   SolarCarTelemetry.h

SOURCES += \
   main.cpp \
   SolarCarTelemetry.cpp

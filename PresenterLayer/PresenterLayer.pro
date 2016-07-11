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
    BatteryPresenter/BatteryPresenter.cpp \
    CommunicationPresenter/CommunicationPresenter.cpp \
    FaultsPresenter/FaultsPresenter.cpp \
    GraphsPresenter/PowerGraphData.cpp \
    GraphsPresenter/PowerGraphsPresenter.cpp \
    PlaybackPresenter/PlaybackPresenter.cpp \
    PowerPresenter/PowerPresenter.cpp \
    PresenterContainer.cpp \
    VehiclePresenter/VehiclePresenter.cpp

HEADERS  += \
    BatteryPresenter/BatteryPresenter.h \
    CommunicationPresenter/CommunicationPresenter.h \
    FaultsPresenter/FaultsPresenter.h \
    GraphsPresenter/I_GraphsPresenter.h \
    GraphsPresenter/PowerGraphData.h \
    GraphsPresenter/PowerGraphsPresenter.h \
    PlaybackPresenter/PlaybackPresenter.h \
    PowerPresenter/PowerPresenter.h \
    PresenterContainer.h \
    VehiclePresenter/VehiclePresenter.h \
    GraphsPresenter/I_PowerGraphsPresenter.h

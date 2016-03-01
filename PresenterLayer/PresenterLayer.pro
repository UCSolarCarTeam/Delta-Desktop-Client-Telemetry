TEMPLATE = lib
CONFIG += create_prl link_prl staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   BatteryPresenter/BatteryPresenter.h \
   CommunicationPresenter/CommunicationPresenter.h \
   FaultsPresenter/FaultsPresenter.h \
   GraphsPresenter/I_GraphsPresenter.h \
   GraphsPresenter/I_PowerGraphsPresenter.h \
   GraphsPresenter/PowerGraphData.h \
   GraphsPresenter/PowerGraphsPresenter.h \
   PlaybackPresenter/PlaybackPresenter.h \
   PowerPresenter/PowerPresenter.h \
   PresenterContainer.h \
   VehiclePresenter/VehiclePresenter.h

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

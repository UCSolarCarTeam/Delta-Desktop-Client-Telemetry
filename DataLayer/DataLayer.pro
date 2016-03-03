TEMPLATE = lib
CONFIG += staticlib

! include( ../common.pri ) {
    error( "Couldn't find the common.pri file!" )
}

DESTDIR = ../../build/.lib

HEADERS += \
   BatteryData/BatteryData.h \
   BatteryData/I_BatteryData.h \
   DataContainer.h \
   FaultsData/FaultsData.h \
   FaultsData/I_FaultsData.h \
   PowerData/I_PowerData.h \
   PowerData/PowerData.h \
   VehicleData/I_VehicleData.h \
   VehicleData/VehicleData.h

SOURCES += \
   BatteryData/BatteryData.cpp \
   DataContainer.cpp \
   FaultsData/FaultsData.cpp \
   PowerData/PowerData.cpp \
   VehicleData/VehicleData.cpp

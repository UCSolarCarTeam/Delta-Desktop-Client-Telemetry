#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../release/SolarCarTelemetry
TEMPLATE = app
CONFIG += static

QMAKE_CXXFLAGS +=
RCC_DIR= ../release
DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui

SOURCES += \
    DataLayer/DataContainer.cpp \
    DataLayer/ConnectionService/SerialPortConnectionService.cpp \
    DataLayer/DataParser/DataParser.cpp \
    DataLayer/DataPopulator/DataPopulator.cpp \
    DataLayer/ArrayData/ArrayData.cpp \
    DataLayer/PowerData/PowerData.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/VehicleData/VehicleData.cpp \
    BusinessLayer/BusinessContainer.cpp \
    BusinessLayer/TelemetryData/TelemetryData.cpp \
    BusinessLayer/DebugHandler/DebugHandler.cpp \
    SolarCarTelemetry/main.cpp \
    PresenterLayer/PresenterContainer.cpp \
    PresenterLayer/DisplayPresenter/DisplayPresenter.cpp \
    ViewLayer/ViewContainer.cpp \
    ViewLayer/SolarCarTestUi/SolarCarTestUI.cpp \
    ViewLayer/DisplayView/DisplayView.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp

HEADERS  += \
    DataLayer/DataContainer.h \
    DataLayer/ConnectionService/I_ConnectionService.h \
    DataLayer/ConnectionService/SerialPortConnectionService.h \
    DataLayer/DataParser/DataParser.h \
    DataLayer/DataParser/I_DataParser.h \
    DataLayer/DataPopulator/DataPopulator.h \
    DataLayer/ArrayData/ArrayData.h \
    DataLayer/PowerData/PowerData.h \
    DataLayer/VehicleData/VehicleData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/ArrayData/I_ArrayData.h \
    DataLayer/PowerData/I_PowerData.h \
    DataLayer/VehicleData/I_VehicleData.h \
    DataLayer/BatteryData/BatteryData.h \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/DebugHandler/DebugHandler.h \
    BusinessLayer/TelemetryData/I_TelemetryData.h \
    BusinessLayer/TelemetryData/TelemetryData.h \
    PresenterLayer/PresenterContainer.h \
    PresenterLayer/DisplayPresenter/DisplayPresenter.h \
    ViewLayer/ViewContainer.h \
    ViewLayer/DisplayView/DisplayView.h \
    ViewLayer/SolarCarTestUi/I_SolarCarTestUI.h \
    ViewLayer/SolarCarTestUi/SolarCarTestUI.h \
    SolarCarTelemetry/SolarCarTelemetry.h
    

FORMS    += \
    SolarCarTestUI.ui

RESOURCES += \
    SolarCarUIResources.qrc

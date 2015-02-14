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
    DataLayer/ArrayData/ArrayData.cpp \
    DataLayer/PowerData/PowerData.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/VehicleData/VehicleData.cpp \
    CommunicationLayer/CommunicationContainer.cpp \
    CommunicationLayer/ConnectionService/SerialPortConnectionService.cpp \
    CommunicationLayer/DataParser/DataParser.cpp \
    CommunicationLayer/DataPopulator/DataPopulator.cpp \
    BusinessLayer/BusinessContainer.cpp \
    BusinessLayer/LoggerService/LoggerService.cpp \
    PresenterLayer/PresenterContainer.cpp \
    PresenterLayer/DisplayPresenter/DisplayPresenter.cpp \
    ViewLayer/ViewContainer.cpp \
    ViewLayer/SolarCarTestUi/SolarCarTestUI.cpp \
    ViewLayer/DisplayView/DisplayView.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    SolarCarTelemetry/main.cpp

HEADERS  += \
    DataLayer/DataContainer.h \
    DataLayer/ArrayData/ArrayData.h \
    DataLayer/PowerData/PowerData.h \
    DataLayer/VehicleData/VehicleData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/ArrayData/I_ArrayData.h \
    DataLayer/PowerData/I_PowerData.h \
    DataLayer/VehicleData/I_VehicleData.h \
    DataLayer/BatteryData/BatteryData.h \
    CommunicationLayer/CommunicationContainer.h \
    CommunicationLayer/ConnectionService/I_ConnectionService.h \
    CommunicationLayer/ConnectionService/SerialPortConnectionService.h \
    CommunicationLayer/DataParser/DataParser.h \
    CommunicationLayer/DataParser/I_DataParser.h \
    CommunicationLayer/DataPopulator/DataPopulator.h \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/LoggerService/LoggerService.h \
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

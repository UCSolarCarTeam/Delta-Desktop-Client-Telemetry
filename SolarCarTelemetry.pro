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
    DataLayer/ConnectionService/SerialPortConnectionService.cpp \
    DataLayer/DataParser/DataParser.cpp \
    DataLayer/DataPopulator/DataPopulator.cpp \
    PresenterLayer/DisplayPresenter/DisplayPresenter.cpp \
    ViewLayer/DisplayView/DisplayView.cpp \
    SolarCarTelemetry/main.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    ViewLayer/SolarCarTestUi/SolarCarTestUI.cpp \
    BusinessLayer/TelemetryData/TelemetryData.cpp \
    BusinessLayer/DebugHandler/DebugHandler.cpp

HEADERS  += \
    DataLayer/ConnectionService/I_ConnectionService.h \
    DataLayer/ConnectionService/SerialPortConnectionService.h \
    DataLayer/DataParser/DataParser.h \
    DataLayer/DataParser/I_DataParser.h \
    DataLayer/DataPopulator/DataPopulator.h \
    PresenterLayer/DisplayPresenter/DisplayPresenter.h \
    ViewLayer/DisplayView/DisplayView.h \
    SolarCarTelemetry/SolarCarTelemetry.h \
    SolarCarTestUi/SolarCarTestUI.h \
    BusinessLayer/TelemetryData/I_TelemetryData.h \
    BusinessLayer/TelemetryData/TelemetryData.h \
    ViewLayer/SolarCarTestUi/SolarCarTestUI.h \
    ViewLayer/SolarCarTestUi/I_SolarCarTestUI.h \
    BusinessLayer/DebugHandler/DebugHandler.h

FORMS    += \
    SolarCarTestUI.ui

RESOURCES += \
    SolarCarUIResources.qrc

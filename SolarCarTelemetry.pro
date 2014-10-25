#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../release/SolarCarTelemetry
TEMPLATE = app

RCC_DIR= ../release
DESTDIR = ../release
OBJECTS_DIR = ../release/.obj
MOC_DIR = ../release/.moc
RCC_DIR = ../release/.rcc
UI_DIR = ../release/.ui

SOURCES += SolarCarTelemetry/main.cpp \
    DataPopulator/DataPopulator.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    DataParser/DataParser.cpp \
    TelemetryData/TelemetryData.cpp \
    ConnectionService/SerialPortConnectionService.cpp \
    DisplayPresenter/DisplayPresenter.cpp \
    SolarCarTestUi/SolarCarTestUI.cpp

HEADERS  += \
    DataPopulator/DataPopulator.h \
    DataParser/DataParser.h \
    SolarCarTelemetry/SolarCarTelemetry.h \
    DataParser/I_DataParser.h \
    TelemetryData/I_TelemetryData.h \
    TelemetryData/TelemetryData.h \
    ConnectionService/I_ConnectionService.h \
    ConnectionService/SerialPortConnectionService.h \
    DisplayPresenter/DisplayPresenter.h \
    SolarCarTestUi/SolarCarTestUI.h

FORMS    += \
    SolarCarTestUI.ui

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

SOURCES += \
    ConnectionService/SerialPortConnectionService.cpp \
    DataParser/DataParser.cpp \
    DataPopulator/DataPopulator.cpp \
    DisplayPresenter/DisplayPresenter.cpp \
    DisplayView/DisplayView.cpp \
    SolarCarTelemetry/main.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    SolarCarTestUi/SolarCarTestUI.cpp \
    TelemetryData/TelemetryData.cpp

HEADERS  += \
    ConnectionService/I_ConnectionService.h \
    ConnectionService/SerialPortConnectionService.h \
    DataParser/DataParser.h \
    DataParser/I_DataParser.h \
    DataPopulator/DataPopulator.h \
    DisplayPresenter/DisplayPresenter.h \
    DisplayView/DisplayView.h \
    SolarCarTelemetry/SolarCarTelemetry.h \
    SolarCarTestUi/SolarCarTestUI.h \
    TelemetryData/I_TelemetryData.h \
    TelemetryData/TelemetryData.h \

FORMS    += \
    SolarCarTestUI.ui

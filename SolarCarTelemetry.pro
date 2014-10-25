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

SOURCES += main.cpp \
    DataPopulator.cpp \
    SolarCarTelemetry.cpp \
    DataParser.cpp \
    TelemetryData.cpp \
    SerialPortConnectionService.cpp \
    MainDisplayPresenter.cpp \
    MainWindow.cpp

HEADERS  += \
    DataPopulator.h \
    DataParser.h \
    SolarCarTelemetry.h \
    I_DataParser.h \
    I_TelemetryData.h \
    TelemetryData.h \
    I_ConnectionService.h \
    SerialPortConnectionService.h \
    MainDisplayPresenter.h \
    MainWindow.h

FORMS    += \
    MainWindow.ui

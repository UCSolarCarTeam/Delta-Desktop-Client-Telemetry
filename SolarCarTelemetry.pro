#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T12:01:32
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

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
    ViewLayer/PowerUI/PowerUI.cpp \
    ViewLayer/PowerView/PowerView.cpp \
    ViewLayer/OverlordWidget/OverlordWidget.cpp \
    ViewLayer/DisplayView/DisplayView.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    SolarCarTelemetry/main.cpp \
    ViewLayer/MpptUI/MpptUI.cpp \
    ViewLayer/MpptView/MpptView.cpp

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
    ViewLayer/PowerUI/I_PowerUI.h \
    ViewLayer/PowerUI/PowerUI.h \
    ViewLayer/PowerView/PowerView.h \
    ViewLayer/PowerView/I_PowerView.h \
    ViewLayer/OverlordWidget/OverlordWidget.h \
    ViewLayer/OverlordWidget/I_OverlordWidget.h \
    ViewLayer/DisplayView/DisplayView.h \
    SolarCarTelemetry/SolarCarTelemetry.h \
    ViewLayer/PowerView/PowerView.h \
    ViewLayer/MpptUI/MpptUI.h \
    ViewLayer/MpptUI/I_MpptUI.h \
    ViewLayer/MpptView/MpptView.h
    
FORMS    += \
    SolarCarTestUI.ui \
    FaultsUI.ui \
    MpptUI.ui \
    PowerUI.ui

RESOURCES += \
    uiresources.qrc

DISTFILES +=

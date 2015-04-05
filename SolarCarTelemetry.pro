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
    ViewLayer/EscapeDialog/EscapeDialog.cpp \
    ViewLayer/EscapeDialogView/EscapeDialogView.cpp \
    ViewLayer/ViewContainer.cpp \
    ViewLayer/PowerUI/PowerUI.cpp \
    ViewLayer/PowerView/PowerView.cpp \
    ViewLayer/MpptUI/MpptUI.cpp \
    ViewLayer/MpptView/MpptView.cpp \ 
    ViewLayer/FaultsUI/FaultsUI.cpp \
    ViewLayer/FaultsView/FaultsView.cpp \ 
    ViewLayer/OverlordWidget/OverlordWidget.cpp \
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
    ViewLayer/EscapeDialogView/EscapeDialogView.h \
    ViewLayer/EscapeDialog/I_EscapeDialog.h \
    ViewLayer/EscapeDialog/EscapeDialog.h \
    ViewLayer/PowerUI/I_PowerUI.h \
    ViewLayer/PowerUI/PowerUI.h \
    ViewLayer/PowerView/PowerView.h \
    ViewLayer/PowerView/I_PowerView.h \
    ViewLayer/MpptUI/MpptUI.h \
    ViewLayer/MpptUI/I_MpptUI.h \
    ViewLayer/MpptView/MpptView.h \ 
    ViewLayer/FaultsUI/FaultsUI.h \
    ViewLayer/FaultsUI/I_FaultsUI.h \
    ViewLayer/FaultsView/FaultsView.h \ 
    ViewLayer/I_SolarCarWindow/I_SolarCarWindow.h \
    ViewLayer/OverlordWidget/OverlordWidget.h \
    ViewLayer/OverlordWidget/I_OverlordWidget.h \
    ViewLayer/DisplayView/DisplayView.h \
    ViewLayer/PowerView/PowerView.h \
    SolarCarTelemetry/SolarCarTelemetry.h 
    
FORMS    += \
    SolarCarTestUI.ui \
    FaultsUI.ui \
    MpptUI.ui \
    PowerUI.ui \
    EscapeDialog.ui

RESOURCES += \
    uiresources.qrc

DISTFILES += \
    Resources/Background1.png \
    Resources/MainTitleBar.png \
    Resources/MenuButton.png \
    Resources/Solar Car Team Logo.png \
    Resources/Solar Car Team Symbol.png \
    Resources/SubTitleBar.png \
    Resources/Solar Car Team Icon.ico \
    Resources/Solar Car Team Logo.png \
    Resources/Solar Car Team Symbol.png \
    Resources/Solar Car Team Icon.ico

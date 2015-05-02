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
    BusinessLayer/BusinessContainer.cpp \
    BusinessLayer/LoggerService/LoggerService.cpp \
    CommunicationLayer/CommunicationContainer.cpp \
    CommunicationLayer/ConnectionService/RadioConnectionService.cpp \
    CommunicationLayer/ConnectionService/SerialPortConnectionService.cpp \
    CommunicationLayer/DataParser/DataParser.cpp \
    CommunicationLayer/DataPopulator/DataPopulator.cpp \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.cpp \
    CommunicationLayer/DataPopulators/FaultsPopulator.cpp \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.cpp \
    CommunicationLayer/MessagingFramework/BatteryFaults.cpp \
    CommunicationLayer/MessagingFramework/DriverControlDetails.cpp \
    CommunicationLayer/MessagingFramework/FaultsMessage.cpp \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.cpp \
    CommunicationLayer/MessagingFramework/LimitFlags.cpp \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.cpp \
    CommunicationLayer/MessagingFramework/MotorFaults.cpp \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.cpp \
    DataLayer/ArrayData/ArrayData.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/DataContainer.cpp \
    DataLayer/FaultsData/FaultsData.cpp \
    DataLayer/PowerData/PowerData.cpp \
    DataLayer/VehicleData/VehicleData.cpp \
    PresenterLayer/BatteryPresenter/BatteryPresenter.cpp \
    PresenterLayer/ConnectionsPresenter/ConnectionsPresenter.cpp \
    PresenterLayer/DisplayPresenter/DisplayPresenter.cpp \
    PresenterLayer/FaultsPresenter/FaultsPresenter.cpp \
    PresenterLayer/GraphsPresenter/GraphsPresenter.cpp \
    PresenterLayer/MpptPresenter/MpptPresenter.cpp \
    PresenterLayer/PowerPresenter/PowerPresenter.cpp \
    PresenterLayer/PresenterContainer.cpp \
    PresenterLayer/VehiclePresenter/VehiclePresenter.cpp \
    SolarCarTelemetry/main.cpp \
    SolarCarTelemetry/SolarCarTelemetry.cpp \
    ViewLayer/DisplayView/DisplayView.cpp \
    ViewLayer/EscapeDialog/EscapeDialog.cpp \
    ViewLayer/EscapeDialogView/EscapeDialogView.cpp \
    ViewLayer/FaultsUI/FaultsUI.cpp \
    ViewLayer/FaultsView/FaultsView.cpp \
    ViewLayer/MpptUI/MpptUI.cpp \
    ViewLayer/MpptView/MpptView.cpp \
    ViewLayer/OverlordWidget/OverlordWidget.cpp \
    ViewLayer/PowerUI/PowerUI.cpp \
    ViewLayer/PowerView/PowerView.cpp \
    ViewLayer/ViewContainer.cpp

HEADERS  += \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/LoggerService/LoggerService.h \
    CommunicationLayer/CommunicationContainer.h \
    CommunicationLayer/ConnectionService/I_ConnectionService.h \
    CommunicationLayer/ConnectionService/RadioConnectionService.h \
    CommunicationLayer/ConnectionService/SerialPortConnectionService.h \
    CommunicationLayer/DataParser/DataParser.h \
    CommunicationLayer/DataParser/I_DataParser.h \
    CommunicationLayer/DataPopulator/DataPopulator.h \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.h \
    CommunicationLayer/DataPopulators/FaultsPopulator.h \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.h \
    CommunicationLayer/MessagingFramework/BatteryFaults.h \
    CommunicationLayer/MessagingFramework/DriverControlDetails.h \
    CommunicationLayer/MessagingFramework/FaultsMessage.h \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h \
    CommunicationLayer/MessagingFramework/LimitFlags.h \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.h \
    CommunicationLayer/MessagingFramework/MessageDefines.h \
    CommunicationLayer/MessagingFramework/MotorFaults.h \
    CommunicationLayer/PacketDecoder/I_PacketDecoder.h \
    CommunicationLayer/PacketSynchronizer/I_PacketSynchronizer.h \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.h \
    DataLayer/ArrayData/ArrayData.h \
    DataLayer/ArrayData/I_ArrayData.h \
    DataLayer/BatteryData/BatteryData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/DataContainer.h \
    DataLayer/FaultsData/I_FaultsData.h \
    DataLayer/FaultsData/FaultsData.h \
    DataLayer/PowerData/I_PowerData.h \
    DataLayer/PowerData/PowerData.h \
    DataLayer/VehicleData/I_VehicleData.h \
    DataLayer/VehicleData/VehicleData.h \
    PresenterLayer/BatteryPresenter/BatteryPresenter.h \
    PresenterLayer/ConnectionsPresenter/ConnectionsPresenter.h \
    PresenterLayer/DisplayPresenter/DisplayPresenter.h \
    PresenterLayer/FaultsPresenter/FaultsPresenter.h \
    PresenterLayer/GraphsPresenter/GraphsPresenter.h \
    PresenterLayer/MpptPresenter/MpptPresenter.h \
    PresenterLayer/PowerPresenter/PowerPresenter.h \
    PresenterLayer/PresenterContainer.h \
    PresenterLayer/VehiclePresenter/VehiclePresenter.h \
    SolarCarTelemetry/SolarCarTelemetry.h \
    ViewLayer/DisplayView/DisplayView.h \
    ViewLayer/EscapeDialog/EscapeDialog.h \
    ViewLayer/EscapeDialog/I_EscapeDialog.h \
    ViewLayer/EscapeDialogView/EscapeDialogView.h \
    ViewLayer/FaultsUI/FaultsUI.h \
    ViewLayer/FaultsUI/I_FaultsUI.h \
    ViewLayer/FaultsView/FaultsView.h \
    ViewLayer/I_SolarCarWindow/I_SolarCarWindow.h \
    ViewLayer/MpptUI/I_MpptUI.h \
    ViewLayer/MpptUI/MpptUI.h \
    ViewLayer/MpptView/MpptView.h \
    ViewLayer/OverlordWidget/I_OverlordWidget.h \
    ViewLayer/OverlordWidget/OverlordWidget.h \
    ViewLayer/PowerUI/I_PowerUI.h \
    ViewLayer/PowerUI/PowerUI.h \
    ViewLayer/PowerView/PowerView.h \

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

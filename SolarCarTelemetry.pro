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
CONFIG += qwt

INCLUDEPATH += /usr/local/qwt-6.1.2/include
LIBS += -L/usr/local/qwt-6.1.2/lib -lqwt
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
    BusinessLayer/PlaybackService/PlaybackService.cpp \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.cpp \
    CommunicationLayer/CommDeviceControl/CommDeviceManager.cpp \
    CommunicationLayer/CommDeviceControl/ConnectionController.cpp \
    CommunicationLayer/CommDeviceControl/RadioConnectionService.cpp \
    CommunicationLayer/CommDeviceControl/UdpConnectionService.cpp \
    CommunicationLayer/CommDeviceControl/UdpMessageForwarder.cpp \
    CommunicationLayer/CommunicationContainer.cpp \
    CommunicationLayer/DataPopulators/BatteryPopulator.cpp \
    CommunicationLayer/DataPopulators/CmuPopulator.cpp \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.cpp \
    CommunicationLayer/DataPopulators/FaultsPopulator.cpp \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.cpp \
    CommunicationLayer/DataPopulators/MpptPopulator.cpp \
    CommunicationLayer/MessagingFramework/BatteryDataMessage.cpp \
    CommunicationLayer/MessagingFramework/BatteryFaults.cpp \
    CommunicationLayer/MessagingFramework/CmuDataMessage.cpp \
    CommunicationLayer/MessagingFramework/DriverControlDetails.cpp \
    CommunicationLayer/MessagingFramework/FaultsMessage.cpp \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.cpp \
    CommunicationLayer/MessagingFramework/LimitFlags.cpp \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.cpp \
    CommunicationLayer/MessagingFramework/MessageDefines.cpp \
    CommunicationLayer/MessagingFramework/MotorFaults.cpp \
    CommunicationLayer/MessagingFramework/MpptDataMessage.cpp \
    CommunicationLayer/MessagingFramework/MpptDefines.cpp \
    CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.cpp \
    CommunicationLayer/PacketDecoder/PacketDecoder.cpp \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.cpp \
    CommunicationLayer/PacketUnstuffer/PacketUnstuffer.cpp \
    DataLayer/BatteryData/BatteryData.cpp \
    DataLayer/DataContainer.cpp \
    DataLayer/FaultsData/FaultsData.cpp \
    DataLayer/MpptData/MpptData.cpp \
    DataLayer/PowerData/PowerData.cpp \
    DataLayer/VehicleData/VehicleData.cpp \
    PresenterLayer/BatteryPresenter/BatteryPresenter.cpp \
    PresenterLayer/CommunicationPresenter/CommunicationPresenter.cpp \
    PresenterLayer/FaultsPresenter/FaultsPresenter.cpp \
    PresenterLayer/GraphsPresenter/PowerGraphData.cpp \
    PresenterLayer/GraphsPresenter/PowerGraphsPresenter.cpp \
    PresenterLayer/MpptPresenter/MpptPresenter.cpp \
    PresenterLayer/PlaybackPresenter/PlaybackPresenter.cpp \
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
    ViewLayer/PlaybackUI/PlaybackUI.cpp \
    ViewLayer/PlaybackView/PlaybackView.cpp \
    ViewLayer/PowerUI/PowerUI.cpp \
    ViewLayer/PowerView/PowerView.cpp \
    ViewLayer/ViewContainer.cpp

HEADERS  += \
    BusinessLayer/BusinessContainer.h \
    BusinessLayer/LoggerService/LoggerService.h \
    BusinessLayer/PlaybackService/I_PlaybackService.h \
    BusinessLayer/PlaybackService/PlaybackService.h \
    BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h \
    BusinessLayer/CommunicationsMonitoringService/I_CommunicationsMonitoringService.h \
    CommunicationLayer/CommunicationContainer.h \
    CommunicationLayer/CommDeviceControl/CommDeviceManager.h \
    CommunicationLayer/CommDeviceControl/ConnectionController.h \
    CommunicationLayer/CommDeviceControl/I_CommDevice.h \
    CommunicationLayer/CommDeviceControl/I_ConnectionService.h \
    CommunicationLayer/CommDeviceControl/RadioConnectionService.h \
    CommunicationLayer/CommDeviceControl/UdpConnectionService.h \
    CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h \
    CommunicationLayer/DataPopulators/BatteryPopulator.h \
    CommunicationLayer/DataPopulators/CmuPopulator.h \
    CommunicationLayer/DataPopulators/DriverDetailsPopulator.h \
    CommunicationLayer/DataPopulators/FaultsPopulator.h \
    CommunicationLayer/DataPopulators/KeyDriverControlPopulator.h \
    CommunicationLayer/DataPopulators/MpptPopulator.h \
    CommunicationLayer/MessagingFramework/BatteryDataMessage.h \
    CommunicationLayer/MessagingFramework/BatteryFaults.h \
    CommunicationLayer/MessagingFramework/CmuDataMessage.h \
    CommunicationLayer/MessagingFramework/DriverControlDetails.h \
    CommunicationLayer/MessagingFramework/FaultsMessage.h \
    CommunicationLayer/MessagingFramework/KeyDriverControlTelemetry.h \
    CommunicationLayer/MessagingFramework/LimitFlags.h \
    CommunicationLayer/MessagingFramework/MessageDecodingHelpers.h \
    CommunicationLayer/MessagingFramework/MessageDefines.h \
    CommunicationLayer/MessagingFramework/MotorFaults.h \
    CommunicationLayer/MessagingFramework/MpptDataMessage.h \
    CommunicationLayer/MessagingFramework/MpptDefines.h \
    CommunicationLayer/PacketChecksumChecker/I_PacketChecksumChecker.h \
    CommunicationLayer/PacketChecksumChecker/PacketChecksumChecker.h \
    CommunicationLayer/PacketDecoder/I_PacketDecoder.h \
    CommunicationLayer/PacketDecoder/PacketDecoder.h \
    CommunicationLayer/PacketSynchronizer/I_PacketSynchronizer.h \
    CommunicationLayer/PacketSynchronizer/PacketSynchronizer.h \
    CommunicationLayer/PacketUnstuffer/I_DataInjectionService.h \
    CommunicationLayer/PacketUnstuffer/I_PacketUnstuffer.h \
    CommunicationLayer/PacketUnstuffer/PacketUnstuffer.h \
    DataLayer/BatteryData/BatteryData.h \
    DataLayer/BatteryData/I_BatteryData.h \
    DataLayer/DataContainer.h \
    DataLayer/FaultsData/FaultsData.h \
    DataLayer/FaultsData/I_FaultsData.h \
    DataLayer/MpptData/I_MpptData.h \
    DataLayer/MpptData/MpptData.h \
    DataLayer/PowerData/I_PowerData.h \
    DataLayer/PowerData/PowerData.h \
    DataLayer/VehicleData/I_VehicleData.h \
    DataLayer/VehicleData/VehicleData.h \
    PresenterLayer/BatteryPresenter/BatteryPresenter.h \
    PresenterLayer/CommunicationPresenter/CommunicationPresenter.h \
    PresenterLayer/FaultsPresenter/FaultsPresenter.h \
    PresenterLayer/GraphsPresenter/I_GraphsPresenter.h \
    PresenterLayer/GraphsPresenter/PowerGraphData.h \
    PresenterLayer/GraphsPresenter/PowerGraphsPresenter.h \
    PresenterLayer/MpptPresenter/MpptPresenter.h \
    PresenterLayer/PlaybackPresenter/PlaybackPresenter.h \
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
    ViewLayer/PlaybackUI/I_PlaybackUI.h \
    ViewLayer/PlaybackUI/PlaybackUI.h \
    ViewLayer/PlaybackView/PlaybackView.h \
    ViewLayer/PowerUI/I_PowerUI.h \
    ViewLayer/PowerUI/PowerUI.h \
    ViewLayer/PowerView/PowerView.h \
    PresenterLayer/GraphsPresenter/I_PowerGraphsPresenter.h

FORMS    += \
    EscapeDialog.ui \
    FaultsUI.ui \
    MpptUI.ui \
    PlaybackUI.ui \
    PowerUI.ui \
    SolarCarTestUI.ui

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
    Resources/Solar Car Team Icon.ico \
    Resources/BrowseButton.png

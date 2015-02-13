#include "DisplayView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"

DisplayView::DisplayView(DisplayPresenter& presenter, SolarCarTestUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   ui_.show();

    connect(&presenter_, SIGNAL(driverSetSpeedRPMReceived(double)),
            this, SLOT(driverSetSpeedRPMReceived(double)));
    connect(&presenter_, SIGNAL(driverSetCurrentReceived(double)),
            this, SLOT(driverSetCurrentReceived(double)));

    connect(&presenter_, SIGNAL(vehicleVelocityKphReceived(double)),
            this, SLOT(vehicleVelocityKphReceived(double)));
    connect(&presenter_, SIGNAL(busCurrentAReceived(double)),
            this, SLOT(busCurrentAReceived(double)));
    connect(&presenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));

    connect(&presenter_, SIGNAL(mod0CellTemperatureReceived(double)),
            this, SLOT(mod0CellTemperatureReceived(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage0Received(double)),
            this, SLOT(mod0CellVoltage0Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage1Received(double)),
            this, SLOT(mod0CellVoltage1Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage2Received(double)),
            this, SLOT(mod0CellVoltage2Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage3Received(double)),
            this, SLOT(mod0CellVoltage3Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage4Received(double)),
            this, SLOT(mod0CellVoltage4Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage5Received(double)),
            this, SLOT(mod0CellVoltage5Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage6Received(double)),
            this, SLOT(mod0CellVoltage6Received(double)));
    connect(&presenter_, SIGNAL(mod0CellVoltage7Received(double)),
            this, SLOT(mod0CellVoltage7Received(double)));

    connect(&presenter_, SIGNAL(mod1CellTemperatureReceived(double)),
            this, SLOT(mod1CellTemperatureReceived(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage0Received(double)),
            this, SLOT(mod1CellVoltage0Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage1Received(double)),
            this, SLOT(mod1CellVoltage1Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage2Received(double)),
            this, SLOT(mod1CellVoltage2Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage3Received(double)),
            this, SLOT(mod1CellVoltage3Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage4Received(double)),
            this, SLOT(mod1CellVoltage4Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage5Received(double)),
            this, SLOT(mod1CellVoltage5Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage6Received(double)),
            this, SLOT(mod1CellVoltage6Received(double)));
    connect(&presenter_, SIGNAL(mod1CellVoltage7Received(double)),
            this, SLOT(mod1CellVoltage7Received(double)));

    connect(&presenter_, SIGNAL(mod2CellTemperatureReceived(double)),
            this, SLOT(mod2CellTemperatureReceived(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage0Received(double)),
            this, SLOT(mod2CellVoltage0Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage1Received(double)),
            this, SLOT(mod2CellVoltage1Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage2Received(double)),
            this, SLOT(mod2CellVoltage2Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage3Received(double)),
            this, SLOT(mod2CellVoltage3Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage4Received(double)),
            this, SLOT(mod2CellVoltage4Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage5Received(double)),
            this, SLOT(mod2CellVoltage5Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage6Received(double)),
            this, SLOT(mod2CellVoltage6Received(double)));
    connect(&presenter_, SIGNAL(mod2CellVoltage7Received(double)),
            this, SLOT(mod2CellVoltage7Received(double)));

    connect(&presenter_, SIGNAL(mod3CellTemperatureReceived(double)),
            this, SLOT(mod3CellTemperatureReceived(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage0Received(double)),
            this, SLOT(mod3CellVoltage0Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage1Received(double)),
            this, SLOT(mod3CellVoltage1Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage2Received(double)),
            this, SLOT(mod3CellVoltage2Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage3Received(double)),
            this, SLOT(mod3CellVoltage3Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage4Received(double)),
            this, SLOT(mod3CellVoltage4Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage5Received(double)),
            this, SLOT(mod3CellVoltage5Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage6Received(double)),
            this, SLOT(mod3CellVoltage6Received(double)));
    connect(&presenter_, SIGNAL(mod3CellVoltage7Received(double)),
            this, SLOT(mod3CellVoltage7Received(double)));

    connect(&ui.connectButton(), SIGNAL(clicked()),
            this, SLOT(handleConnectButtonClicked()));
    connect(&ui_.disconnectButton(), SIGNAL(clicked()),
            this, SLOT(handleDisconnectButtonClicked()));

    connect(&presenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));
    connect(&presenter_, SIGNAL(connectionSucceeded(QString)),
            this, SLOT(connectionSucceeded(QString)));
    connect(&presenter_, SIGNAL(sendDebugMessage(QString)),
            this, SLOT(writeToDebugLog(QString)));
}

void DisplayView::driverSetSpeedRPMReceived(double driverSetSpeedRPMReceived)
{
   ui_.setDriverSetSpeedRPM().display(driverSetSpeedRPMReceived);
}
void DisplayView::driverSetCurrentReceived(double driverSetCurrentReceived)
{
   ui_.setDriverSetCurrent().display(driverSetCurrentReceived);
}

void DisplayView::vehicleVelocityKphReceived(double vehicleVelocityKphReceived)
{
   ui_.setVehicleVelocityKph().display(vehicleVelocityKphReceived);
}
void DisplayView::busCurrentAReceived(double busCurrentA)
{
   ui_.setBusCurrentA().display(busCurrentA);
}
void DisplayView::busVoltageReceived(double busVoltage)
{
   ui_.setBusVoltage().display(busVoltage);
}

void DisplayView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{   ui_.setMod0CellTemperature().display(mod0PcbTemperature);

    ui_.setMod0CellTemperature_2().display(mod0PcbTemperature);
}
void DisplayView::mod0CellVoltage0Received(double mod0CellVoltage0)
{
   ui_.setMod0CellVoltage0().display(mod0CellVoltage0);
}
void DisplayView::mod0CellVoltage1Received(double mod0CellVoltage1)
{
   ui_.setMod0CellVoltage1().display(mod0CellVoltage1);
}
void DisplayView::mod0CellVoltage2Received(double mod0CellVoltage2)
{
   ui_.setMod0CellVoltage2().display(mod0CellVoltage2);
}
void DisplayView::mod0CellVoltage3Received(double mod0CellVoltage2)
{
   ui_.setMod0CellVoltage3().display(mod0CellVoltage2);
}
void DisplayView::mod0CellVoltage4Received(double mod0CellVoltage4)
{
   ui_.setMod0CellVoltage4().display(mod0CellVoltage4);
}
void DisplayView::mod0CellVoltage5Received(double mod0CellVoltage5)
{
   ui_.setMod0CellVoltage5().display(mod0CellVoltage5);
}
void DisplayView::mod0CellVoltage6Received(double mod0CellVoltage6)
{
   ui_.setMod0CellVoltage6().display(mod0CellVoltage6);
}
void DisplayView::mod0CellVoltage7Received(double mod0CellVoltage7)
{
   ui_.setMod0CellVoltage7().display(mod0CellVoltage7);
}

void DisplayView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{   ui_.setMod1CellTemperature().display(mod1PcbTemperature);

    ui_.setMod1CellTemperature_2().display(mod1PcbTemperature);
}
void DisplayView::mod1CellVoltage0Received(double mod1CellVoltage0)
{
   ui_.setMod1CellVoltage0().display(mod1CellVoltage0);
}
void DisplayView::mod1CellVoltage1Received(double mod1CellVoltage1)
{
   ui_.setMod1CellVoltage1().display(mod1CellVoltage1);
}
void DisplayView::mod1CellVoltage2Received(double mod1CellVoltage2)
{
   ui_.setMod1CellVoltage2().display(mod1CellVoltage2);
}
void DisplayView::mod1CellVoltage3Received(double mod1CellVoltage3)
{
   ui_.setMod1CellVoltage3().display(mod1CellVoltage3);
}
void DisplayView::mod1CellVoltage4Received(double mod1CellVoltage4)
{
   ui_.setMod1CellVoltage4().display(mod1CellVoltage4);
}
void DisplayView::mod1CellVoltage5Received(double mod1CellVoltage5)
{
   ui_.setMod1CellVoltage5().display(mod1CellVoltage5);
}
void DisplayView::mod1CellVoltage6Received(double mod1CellVoltage6)
{
   ui_.setMod1CellVoltage6().display(mod1CellVoltage6);
}
void DisplayView::mod1CellVoltage7Received(double mod1CellVoltage7)
{
   ui_.setMod1CellVoltage7().display(mod1CellVoltage7);
}

void DisplayView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.setMod2CellTemperature().display(mod2PcbTemperature);
    ui_.setMod2CellTemperature_2().display(mod2PcbTemperature);
}
void DisplayView::mod2CellVoltage0Received(double mod2CellVoltage0)
{
   ui_.setMod2CellVoltage0().display(mod2CellVoltage0);
}
void DisplayView::mod2CellVoltage1Received(double mod2CellVoltage1)
{
   ui_.setMod2CellVoltage1().display(mod2CellVoltage1);
}
void DisplayView::mod2CellVoltage2Received(double mod2CellVoltage2)
{
   ui_.setMod2CellVoltage2().display(mod2CellVoltage2);
}
void DisplayView::mod2CellVoltage3Received(double mod2CellVoltage3)
{
   ui_.setMod2CellVoltage3().display(mod2CellVoltage3);
}
void DisplayView::mod2CellVoltage4Received(double mod2CellVoltage4)
{
   ui_.setMod2CellVoltage4().display(mod2CellVoltage4);
}
void DisplayView::mod2CellVoltage5Received(double mod2CellVoltage5)
{
   ui_.setMod2CellVoltage5().display(mod2CellVoltage5);
}
void DisplayView::mod2CellVoltage6Received(double mod2CellVoltage6)
{
   ui_.setMod2CellVoltage6().display(mod2CellVoltage6);
}
void DisplayView::mod2CellVoltage7Received(double mod2CellVoltage7)
{
   ui_.setMod2CellVoltage7().display(mod2CellVoltage7);
}

void DisplayView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{
    ui_.setMod3CellTemperature().display(mod3PcbTemperature);
    ui_.setMod3CellTemperature_2().display(mod3PcbTemperature);
}
void DisplayView::mod3CellVoltage0Received(double mod3CellVoltage0)
{
   ui_.setMod3CellVoltage0().display(mod3CellVoltage0);
}
void DisplayView::mod3CellVoltage1Received(double mod3CellVoltage1)
{
   ui_.setMod3CellVoltage1().display(mod3CellVoltage1);
}
void DisplayView::mod3CellVoltage2Received(double mod3CellVoltage2)
{
   ui_.setMod3CellVoltage2().display(mod3CellVoltage2);
}
void DisplayView::mod3CellVoltage3Received(double mod3CellVoltage3)
{
   ui_.setMod3CellVoltage3().display(mod3CellVoltage3);
}
void DisplayView::mod3CellVoltage4Received(double mod3CellVoltage4)
{
   ui_.setMod3CellVoltage4().display(mod3CellVoltage4);
}
void DisplayView::mod3CellVoltage5Received(double mod3CellVoltage5)
{
   ui_.setMod3CellVoltage5().display(mod3CellVoltage5);
}
void DisplayView::mod3CellVoltage6Received(double mod3CellVoltage6)
{
   ui_.setMod3CellVoltage6().display(mod3CellVoltage6);
}
void DisplayView::mod3CellVoltage7Received(double mod3CellVoltage7)
{
   ui_.setMod3CellVoltage7().display(mod3CellVoltage7);
}

DisplayView::~DisplayView()
{
}

void DisplayView::handleConnectButtonClicked()
{
   clearDebugLog();
   ui_.setConnectionStatus().setText("Connecting...");
   presenter_.connectDataSource(ui_.getSerialPortName().text(),
                                ui_.getBaudRate().text().toDouble());
}
void DisplayView::handleDisconnectButtonClicked()
{
   presenter_.disconnectDataSource();
}

void DisplayView::connectionFailed(QString failureMessage)
{
   ui_.setConnectionStatus().setText(failureMessage);
}

void DisplayView::connectionSucceeded(QString successMessage)
{
   ui_.setConnectionStatus().setText(successMessage);
}

void DisplayView::clearDebugLog()
{
   ui_.setDebugLog().clear();
}

void DisplayView::writeToDebugLog(QString message)
{
   ui_.setDebugLog().append(message);
}

#include "DisplayView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../PowerUI/PowerUI.h"
#include <QDebug>

DisplayView::DisplayView(DisplayPresenter& presenter, PowerUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   ui_.show();

    // connect(&presenter_, SIGNAL(driverSetSpeedRPMReceived(double)),
    //         this, SLOT(driverSetSpeedRPMReceived(double)));
    // connect(&presenter_, SIGNAL(driverSetCurrentReceived(double)),
    //         this, SLOT(driverSetCurrentReceived(double)));

    // connect(&presenter_, SIGNAL(vehicleVelocityKphReceived(double)),
    //         this, SLOT(vehicleVelocityKphReceived(double)));
    // connect(&presenter_, SIGNAL(busCurrentAReceived(double)),
    //         this, SLOT(busCurrentAReceived(double)));
    // connect(&presenter_, SIGNAL(busVoltageReceived(double)),
    //         this, SLOT(busVoltageReceived(double)));

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
    // connect(&ui_.disconnectButton(), SIGNAL(clicked()),
    //         this, SLOT(handleDisconnectButtonClicked()));

    connect(&presenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));
    connect(&presenter_, SIGNAL(connectionSucceeded(QString)),
            this, SLOT(connectionSucceeded(QString)));
    connect(&presenter_, SIGNAL(sendDebugMessage(QString)),
            this, SLOT(writeToDebugLog(QString)));
}

// void DisplayView::driverSetSpeedRPMReceived(double driverSetSpeedRPMReceived)
// {
//    ui_.setDriverSetSpeedRPM().setText(driverSetSpeedRPMReceived);
// }
// void DisplayView::driverSetCurrentReceived(double driverSetCurrentReceived)
// {
//    ui_.setDriverSetCurrent().setText(driverSetCurrentReceived);
// }

// void DisplayView::vehicleVelocityKphReceived(double vehicleVelocityKphReceived)
// {
//    ui_.setVehicleVelocityKph().setText(vehicleVelocityKphReceived);
// }
// void DisplayView::busCurrentAReceived(double busCurrentA)
// {
//    ui_.setBusCurrentA().setText(busCurrentA);
// }
// void DisplayView::busVoltageReceived(double busVoltage)
// {
//    ui_.setBusVoltage().setText(busVoltage);
// }


void DisplayView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{   
   ui_.setBatteryCMU1Temp().setText(QString::number(mod0PcbTemperature));
}
void DisplayView::mod0CellVoltage0Received(double mod0CellVoltage0)
{
   ui_.setBatteryCMU1Cell1Voltage().setText(QString::number(mod0CellVoltage0));
}
void DisplayView::mod0CellVoltage1Received(double mod0CellVoltage1)
{
   ui_.setBatteryCMU1Cell2Voltage().setText(QString::number(mod0CellVoltage1));
}
void DisplayView::mod0CellVoltage2Received(double mod0CellVoltage2)
{
   ui_.setBatteryCMU1Cell3Voltage().setText(QString::number(mod0CellVoltage2));
}
void DisplayView::mod0CellVoltage3Received(double mod0CellVoltage3)
{
   ui_.setBatteryCMU1Cell4Voltage().setText(QString::number(mod0CellVoltage3));
}
void DisplayView::mod0CellVoltage4Received(double mod0CellVoltage4)
{
   ui_.setBatteryCMU1Cell5Voltage().setText(QString::number(mod0CellVoltage4));
}
void DisplayView::mod0CellVoltage5Received(double mod0CellVoltage5)
{
   ui_.setBatteryCMU1Cell6Voltage().setText(QString::number(mod0CellVoltage5));
}
void DisplayView::mod0CellVoltage6Received(double mod0CellVoltage6)
{
   ui_.setBatteryCMU1Cell7Voltage().setText(QString::number(mod0CellVoltage6));
}
void DisplayView::mod0CellVoltage7Received(double mod0CellVoltage7)
{
   ui_.setBatteryCMU1Cell8Voltage().setText(QString::number(mod0CellVoltage7));
}

void DisplayView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
    ui_.setBatteryCMU2Temp().setText(QString::number(mod1PcbTemperature));
}
void DisplayView::mod1CellVoltage0Received(double mod1CellVoltage0)
{
   ui_.setBatteryCMU2Cell1Voltage().setText(QString::number(mod1CellVoltage0));
}
void DisplayView::mod1CellVoltage1Received(double mod1CellVoltage1)
{
   ui_.setBatteryCMU2Cell2Voltage().setText(QString::number(mod1CellVoltage1));
}
void DisplayView::mod1CellVoltage2Received(double mod1CellVoltage2)
{
   ui_.setBatteryCMU2Cell3Voltage().setText(QString::number(mod1CellVoltage2));
}
void DisplayView::mod1CellVoltage3Received(double mod1CellVoltage3)
{
   ui_.setBatteryCMU2Cell4Voltage().setText(QString::number(mod1CellVoltage3));
}
void DisplayView::mod1CellVoltage4Received(double mod1CellVoltage4)
{
   ui_.setBatteryCMU2Cell5Voltage().setText(QString::number(mod1CellVoltage4));
}
void DisplayView::mod1CellVoltage5Received(double mod1CellVoltage5)
{
   ui_.setBatteryCMU2Cell6Voltage().setText(QString::number(mod1CellVoltage5));
}
void DisplayView::mod1CellVoltage6Received(double mod1CellVoltage6)
{
   ui_.setBatteryCMU2Cell7Voltage().setText(QString::number(mod1CellVoltage6));
}
void DisplayView::mod1CellVoltage7Received(double mod1CellVoltage7)
{
   ui_.setBatteryCMU2Cell8Voltage().setText(QString::number(mod1CellVoltage7));
} 

void DisplayView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.setBatteryCMU3Temp().setText(QString::number(mod2PcbTemperature));
}
void DisplayView::mod2CellVoltage0Received(double mod2CellVoltage0)
{
   ui_.setBatteryCMU3Cell1Voltage().setText(QString::number(mod2CellVoltage0));
}
void DisplayView::mod2CellVoltage1Received(double mod2CellVoltage1)
{
   ui_.setBatteryCMU3Cell2Voltage().setText(QString::number(mod2CellVoltage1));
}
void DisplayView::mod2CellVoltage2Received(double mod2CellVoltage2)
{
   ui_.setBatteryCMU3Cell3Voltage().setText(QString::number(mod2CellVoltage2));
}
void DisplayView::mod2CellVoltage3Received(double mod2CellVoltage3)
{
   ui_.setBatteryCMU3Cell4Voltage().setText(QString::number(mod2CellVoltage3));
}
void DisplayView::mod2CellVoltage4Received(double mod2CellVoltage4)
{
   ui_.setBatteryCMU3Cell5Voltage().setText(QString::number(mod2CellVoltage4));
}
void DisplayView::mod2CellVoltage5Received(double mod2CellVoltage5)
{
   ui_.setBatteryCMU3Cell6Voltage().setText(QString::number(mod2CellVoltage5));
}
void DisplayView::mod2CellVoltage6Received(double mod2CellVoltage6)
{
   ui_.setBatteryCMU3Cell7Voltage().setText(QString::number(mod2CellVoltage6));
}
void DisplayView::mod2CellVoltage7Received(double mod2CellVoltage7)
{
   ui_.setBatteryCMU3Cell8Voltage().setText(QString::number(mod2CellVoltage7));
} 

void DisplayView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{   
   ui_.setBatteryCMU4Temp().setText(QString::number(mod3PcbTemperature));
}
void DisplayView::mod3CellVoltage0Received(double mod3CellVoltage0)
{
   ui_.setBatteryCMU4Cell1Voltage().setText(QString::number(mod3CellVoltage0));
}
void DisplayView::mod3CellVoltage1Received(double mod3CellVoltage1)
{
   ui_.setBatteryCMU4Cell2Voltage().setText(QString::number(mod3CellVoltage1));
}
void DisplayView::mod3CellVoltage2Received(double mod3CellVoltage2)
{
   ui_.setBatteryCMU4Cell3Voltage().setText(QString::number(mod3CellVoltage2));
}
void DisplayView::mod3CellVoltage3Received(double mod3CellVoltage2)
{
   ui_.setBatteryCMU4Cell4Voltage().setText(QString::number(mod3CellVoltage2));
}
void DisplayView::mod3CellVoltage4Received(double mod3CellVoltage4)
{
   ui_.setBatteryCMU4Cell5Voltage().setText(QString::number(mod3CellVoltage4));
}
void DisplayView::mod3CellVoltage5Received(double mod3CellVoltage5)
{
   ui_.setBatteryCMU4Cell6Voltage().setText(QString::number(mod3CellVoltage5));
}
void DisplayView::mod3CellVoltage6Received(double mod3CellVoltage6)
{
   ui_.setBatteryCMU4Cell7Voltage().setText(QString::number(mod3CellVoltage6));
}
void DisplayView::mod3CellVoltage7Received(double mod3CellVoltage7)
{
   ui_.setBatteryCMU4Cell8Voltage().setText(QString::number(mod3CellVoltage7));
}

DisplayView::~DisplayView()
{
}

void DisplayView::handleConnectButtonClicked()
{
    qDebug() << "CHECK";
    clearDebugLog();
    ui_.setConnectionStatus().setText("Connecting...");
    presenter_.connectDataSource(ui_.getSerialPortName().text(),
                                 ui_.getBaudRate().text().toDouble());
}
// void DisplayView::handleDisconnectButtonClicked()
// {
   // presenter_.disconnectDataSource();
// }

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

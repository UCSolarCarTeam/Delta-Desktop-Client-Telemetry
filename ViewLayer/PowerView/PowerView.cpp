#include "PowerView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "../PowerUI/PowerUI.h"
#include <QDebug>

PowerView::PowerView(DisplayPresenter& presenter, 
                     BatteryPresenter& batteryPresenter, 
                     VehiclePresenter& vehiclePresenter,
                     PowerUI& ui)
: presenter_(presenter)
, batteryPresenter_(batteryPresenter)
, vehiclePresenter_(vehiclePresenter)
, ui_(ui)
{
#ifdef _WIN32
    ui_.getSerialPortName().setText("COM");
#else
    ui.getSerialPortName().setText("/dev/ttyUSB0");
#endif 

    connect(&presenter_, SIGNAL(driverSetSpeedRPMReceived(double)),
            this, SLOT(driverSetSpeedRPMReceived(double)));
    connect(&presenter_, SIGNAL(driverSetCurrentReceived(double)),
            this, SLOT(driverSetCurrentReceived(double)));
    connect(&presenter_, SIGNAL(vehicleVelocityKphReceived(double)),
            this, SLOT(vehicleVelocityKphReceived(double)));
    // connect(&presenter_, SIGNAL(busCurrentAReceived(double)),
    //         this, SLOT(busCurrentAReceived(double)));
    connect(&presenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));

    connect(&batteryPresenter_, SIGNAL(mod0CellTemperatureReceived(double)),
            this, SLOT(mod0CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage0Received(double)),
            this, SLOT(mod0CellVoltage0Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage1Received(double)),
            this, SLOT(mod0CellVoltage1Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage2Received(double)),
            this, SLOT(mod0CellVoltage2Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage3Received(double)),
            this, SLOT(mod0CellVoltage3Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage4Received(double)),
            this, SLOT(mod0CellVoltage4Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage5Received(double)),
            this, SLOT(mod0CellVoltage5Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage6Received(double)),
            this, SLOT(mod0CellVoltage6Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltage7Received(double)),
            this, SLOT(mod0CellVoltage7Received(double)));

    connect(&batteryPresenter_, SIGNAL(mod1CellTemperatureReceived(double)),
            this, SLOT(mod1CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage0Received(double)),
            this, SLOT(mod1CellVoltage0Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage1Received(double)),
            this, SLOT(mod1CellVoltage1Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage2Received(double)),
            this, SLOT(mod1CellVoltage2Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage3Received(double)),
            this, SLOT(mod1CellVoltage3Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage4Received(double)),
            this, SLOT(mod1CellVoltage4Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage5Received(double)),
            this, SLOT(mod1CellVoltage5Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage6Received(double)),
            this, SLOT(mod1CellVoltage6Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltage7Received(double)),
            this, SLOT(mod1CellVoltage7Received(double)));

    connect(&batteryPresenter_, SIGNAL(mod2CellTemperatureReceived(double)),
            this, SLOT(mod2CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage0Received(double)),
            this, SLOT(mod2CellVoltage0Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage1Received(double)),
            this, SLOT(mod2CellVoltage1Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage2Received(double)),
            this, SLOT(mod2CellVoltage2Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage3Received(double)),
            this, SLOT(mod2CellVoltage3Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage4Received(double)),
            this, SLOT(mod2CellVoltage4Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage5Received(double)),
            this, SLOT(mod2CellVoltage5Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage6Received(double)),
            this, SLOT(mod2CellVoltage6Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltage7Received(double)),
            this, SLOT(mod2CellVoltage7Received(double)));

    connect(&batteryPresenter_, SIGNAL(mod3CellTemperatureReceived(double)),
            this, SLOT(mod3CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage0Received(double)),
            this, SLOT(mod3CellVoltage0Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage1Received(double)),
            this, SLOT(mod3CellVoltage1Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage2Received(double)),
            this, SLOT(mod3CellVoltage2Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage3Received(double)),
            this, SLOT(mod3CellVoltage3Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage4Received(double)),
            this, SLOT(mod3CellVoltage4Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage5Received(double)),
            this, SLOT(mod3CellVoltage5Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage6Received(double)),
            this, SLOT(mod3CellVoltage6Received(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltage7Received(double)),
            this, SLOT(mod3CellVoltage7Received(double)));

    connect(&ui.connectButton(), SIGNAL(clicked()),
            this, SLOT(handleConnectButtonClicked()));
    connect(&presenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));
    connect(&presenter_, SIGNAL(connectionSucceeded(QString)),
            this, SLOT(connectionSucceeded(QString)));
    connect(&presenter_, SIGNAL(sendDebugMessage(QString)),
            this, SLOT(writeToDebugLog(QString)));
}

void PowerView::driverSetSpeedRPMReceived(double driverSetSpeedRPMReceived)
{
    ui_.setSetSpeed().setNum(driverSetSpeedRPMReceived);
}
void PowerView::driverSetCurrentReceived(double driverSetCurrentReceived)
{
    ui_.setSetCurrent().setNum(driverSetCurrentReceived);
} 
void PowerView::vehicleVelocityKphReceived(double vehicleVelocityKphReceived)
{
    ui_.setActualSpeed().setNum(vehicleVelocityKphReceived);
}
// void PowerView::busCurrentAReceived(double busCurrentA)
// {
//    ui_.setSetSpeed().setNum(busCurrentA);
// }
void PowerView::busVoltageReceived(double busVoltage)
{
    ui_.setBusVoltage().setNum(busVoltage);
}


void PowerView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{   
    ui_.setBatteryCMU1Temp().setNum(mod0PcbTemperature);
}
void PowerView::mod0CellVoltage0Received(double mod0CellVoltage0)
{
    ui_.setBatteryCMU1Cell1Voltage().setNum(mod0CellVoltage0);
}
void PowerView::mod0CellVoltage1Received(double mod0CellVoltage1)
{
    ui_.setBatteryCMU1Cell2Voltage().setNum(mod0CellVoltage1);
}
void PowerView::mod0CellVoltage2Received(double mod0CellVoltage2)
{
    ui_.setBatteryCMU1Cell3Voltage().setNum(mod0CellVoltage2);
}
void PowerView::mod0CellVoltage3Received(double mod0CellVoltage3)
{
    ui_.setBatteryCMU1Cell4Voltage().setNum(mod0CellVoltage3);
}
void PowerView::mod0CellVoltage4Received(double mod0CellVoltage4)
{
    ui_.setBatteryCMU1Cell5Voltage().setNum(mod0CellVoltage4);
}
void PowerView::mod0CellVoltage5Received(double mod0CellVoltage5)
{
    ui_.setBatteryCMU1Cell6Voltage().setNum(mod0CellVoltage5);
}
void PowerView::mod0CellVoltage6Received(double mod0CellVoltage6)
{
    ui_.setBatteryCMU1Cell7Voltage().setNum(mod0CellVoltage6);
}
void PowerView::mod0CellVoltage7Received(double mod0CellVoltage7)
{
    ui_.setBatteryCMU1Cell8Voltage().setNum(mod0CellVoltage7);
}

void PowerView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
     ui_.setBatteryCMU2Temp().setNum(mod1PcbTemperature);
}
void PowerView::mod1CellVoltage0Received(double mod1CellVoltage0)
{
    ui_.setBatteryCMU2Cell1Voltage().setNum(mod1CellVoltage0);
}
void PowerView::mod1CellVoltage1Received(double mod1CellVoltage1)
{
    ui_.setBatteryCMU2Cell2Voltage().setNum(mod1CellVoltage1);
}
void PowerView::mod1CellVoltage2Received(double mod1CellVoltage2)
{
    ui_.setBatteryCMU2Cell3Voltage().setNum(mod1CellVoltage2);
}
void PowerView::mod1CellVoltage3Received(double mod1CellVoltage3)
{
    ui_.setBatteryCMU2Cell4Voltage().setNum(mod1CellVoltage3);
}
void PowerView::mod1CellVoltage4Received(double mod1CellVoltage4)
{
    ui_.setBatteryCMU2Cell5Voltage().setNum(mod1CellVoltage4);
}
void PowerView::mod1CellVoltage5Received(double mod1CellVoltage5)
{
    ui_.setBatteryCMU2Cell6Voltage().setNum(mod1CellVoltage5);
}
void PowerView::mod1CellVoltage6Received(double mod1CellVoltage6)
{
    ui_.setBatteryCMU2Cell7Voltage().setNum(mod1CellVoltage6);
}
void PowerView::mod1CellVoltage7Received(double mod1CellVoltage7)
{
    ui_.setBatteryCMU2Cell8Voltage().setNum(mod1CellVoltage7);
} 

void PowerView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.setBatteryCMU3Temp().setNum(mod2PcbTemperature);
}
void PowerView::mod2CellVoltage0Received(double mod2CellVoltage0)
{
    ui_.setBatteryCMU3Cell1Voltage().setNum(mod2CellVoltage0);
}
void PowerView::mod2CellVoltage1Received(double mod2CellVoltage1)
{
    ui_.setBatteryCMU3Cell2Voltage().setNum(mod2CellVoltage1);
}
void PowerView::mod2CellVoltage2Received(double mod2CellVoltage2)
{
    ui_.setBatteryCMU3Cell3Voltage().setNum(mod2CellVoltage2);
}
void PowerView::mod2CellVoltage3Received(double mod2CellVoltage3)
{
    ui_.setBatteryCMU3Cell4Voltage().setNum(mod2CellVoltage3);
}
void PowerView::mod2CellVoltage4Received(double mod2CellVoltage4)
{
    ui_.setBatteryCMU3Cell5Voltage().setNum(mod2CellVoltage4);
}
void PowerView::mod2CellVoltage5Received(double mod2CellVoltage5)
{
    ui_.setBatteryCMU3Cell6Voltage().setNum(mod2CellVoltage5);
}
void PowerView::mod2CellVoltage6Received(double mod2CellVoltage6)
{
    ui_.setBatteryCMU3Cell7Voltage().setNum(mod2CellVoltage6);
}
void PowerView::mod2CellVoltage7Received(double mod2CellVoltage7)
{
    ui_.setBatteryCMU3Cell8Voltage().setNum(mod2CellVoltage7);
} 

void PowerView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{   
    ui_.setBatteryCMU4Temp().setNum(mod3PcbTemperature);
}
void PowerView::mod3CellVoltage0Received(double mod3CellVoltage0)
{
    ui_.setBatteryCMU4Cell1Voltage().setNum(mod3CellVoltage0);
}
void PowerView::mod3CellVoltage1Received(double mod3CellVoltage1)
{
    ui_.setBatteryCMU4Cell2Voltage().setNum(mod3CellVoltage1);
}
void PowerView::mod3CellVoltage2Received(double mod3CellVoltage2)
{
    ui_.setBatteryCMU4Cell3Voltage().setNum(mod3CellVoltage2);
}
void PowerView::mod3CellVoltage3Received(double mod3CellVoltage2)
{
    ui_.setBatteryCMU4Cell4Voltage().setNum(mod3CellVoltage2);
}
void PowerView::mod3CellVoltage4Received(double mod3CellVoltage4)
{
    ui_.setBatteryCMU4Cell5Voltage().setNum(mod3CellVoltage4);
}
void PowerView::mod3CellVoltage5Received(double mod3CellVoltage5)
{
    ui_.setBatteryCMU4Cell6Voltage().setNum(mod3CellVoltage5);
}
void PowerView::mod3CellVoltage6Received(double mod3CellVoltage6)
{
    ui_.setBatteryCMU4Cell7Voltage().setNum(mod3CellVoltage6);
}
void PowerView::mod3CellVoltage7Received(double mod3CellVoltage7)
{
    ui_.setBatteryCMU4Cell8Voltage().setNum(mod3CellVoltage7);
}

PowerView::~PowerView()
{
}

void PowerView::handleConnectButtonClicked()
{
    if(ui_.connectButton().text() == "Connect"){
        clearDebugLog();
        ui_.setConnectionStatus().setText("CONNECTING...");
        ui_.setConnectionStatus().setStyleSheet("text-align: centre; color: yellow; background-color: rgb(70,70,70);");
        presenter_.connectDataSource(ui_.getSerialPortName().text(),
                                     ui_.getBaudRate().text().toDouble());
    }
    else if(ui_.connectButton().text() == "Disconnect"){
        presenter_.disconnectDataSource();
    }
}

void PowerView::connectionFailed(QString failureMessage)
{
    ui_.connectButton().setText("Connect");
    ui_.setConnectionStatus().setText(failureMessage);
    ui_.setConnectionStatus().setStyleSheet("text-align: centre; color: rgb(255, 40, 40); background-color: rgb(70,70,70);"); // red text
    ui_.setConnectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth0of5.png);");
}

void PowerView::connectionSucceeded(QString successMessage)
{
    ui_.connectButton().setText("Disconnect");
    ui_.setConnectionStatus().setText(successMessage);
    ui_.setConnectionStatus().setStyleSheet("text-align: centre; color: rgb(0, 255, 0); background-color: rgb(70,70,70);");
    ui_.setConnectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth5of5.png);");//placeholder code
}

void PowerView::clearDebugLog()
{
    ui_.setDebugLog().clear();
}

void PowerView::writeToDebugLog(QString message)
{
    ui_.setDebugLog().append(message);
}

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
    ui_.getSerialPortName().setText("/dev/ttyUSB0");
#endif 

    connect(&vehiclePresenter_, SIGNAL(driverSetSpeedMetersPerSecondReceived(double)),
            this, SLOT(driverSetSpeedMetersPerSecondReceived(double)));
    connect(&vehiclePresenter_, SIGNAL(driverSetCurrentReceived(double)),
            this, SLOT(driverSetCurrentReceived(double)));
    connect(&vehiclePresenter_, SIGNAL(vehicleVelocityMetersPerSecondReceived(double)),
            this, SLOT(vehicleVelocityMetersPerSecondReceived(double)));
    // connect(&vehiclePresenter_, SIGNAL(???)),
            // this, SLOT(busCurrentAReceived(double)));
    connect(&vehiclePresenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));
    // connect(&vehiclePresenter_, SIGNAL(???),
    //         this, SLOT(arrayCurrentReceived(double)));
 
    connect(&batteryPresenter_, SIGNAL(mod0CellTemperatureReceived(double)),
            this, SLOT(mod0CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
            this, SLOT(mod0CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod1CellTemperatureReceived(double)),
            this, SLOT(mod1CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
            this, SLOT(mod1CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod2CellTemperatureReceived(double)),
            this, SLOT(mod2CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
            this, SLOT(mod2CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod3CellTemperatureReceived(double)),
            this, SLOT(mod3CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
            this, SLOT(mod3CellVoltagesReceived(QList<double>)));

    connect(&ui.connectButton(), SIGNAL(clicked()),
            this, SLOT(handleConnectButtonClicked()));
    connect(&presenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));
    connect(&presenter_, SIGNAL(connectionSucceeded(QString)),
            this, SLOT(connectionSucceeded(QString)));
    connect(&presenter_, SIGNAL(sendDebugMessage(QString)),
            this, SLOT(writeToDebugLog(QString)));
}

void PowerView::driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double driverSetSpeedKph = driverSetSpeedMetersPerSecond * 3.6; 
    ui_.setSetSpeed().setNum(driverSetSpeedKph);
}
void PowerView::driverSetCurrentReceived(double driverSetCurrent)
{
    ui_.setSetCurrent().setNum(driverSetCurrent);
} 
void PowerView::vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double vehicleVelocityKph = vehicleVelocityMetersPerSecond * 3.6;
    ui_.setActualSpeed().setNum(vehicleVelocityKph);
}
void PowerView::busCurrentAReceived(double busCurrentA)
{
   ui_.setBusCurrent().setNum(busCurrentA);
}
void PowerView::busVoltageReceived(double busVoltage)
{
    ui_.setBusVoltage().setNum(busVoltage);
}
void PowerView::arrayCurrentReceived(double arrayCurrentIn)
{
    ui_.setArrayCurrent().setNum(arrayCurrentIn);
}

void PowerView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{   
    ui_.setBatteryCMU1Temp().setNum(mod0PcbTemperature);
}

void PowerView::mod0CellVoltagesReceived(QList<double> mod0CellVoltages)
{
    ui_.setBatteryCMU1Cell1Voltage().setNum(mod0CellVoltages[0]);
    ui_.setBatteryCMU1Cell2Voltage().setNum(mod0CellVoltages[1]);
    ui_.setBatteryCMU1Cell3Voltage().setNum(mod0CellVoltages[2]);
    ui_.setBatteryCMU1Cell4Voltage().setNum(mod0CellVoltages[3]);
    ui_.setBatteryCMU1Cell5Voltage().setNum(mod0CellVoltages[4]);
    ui_.setBatteryCMU1Cell6Voltage().setNum(mod0CellVoltages[5]);
    ui_.setBatteryCMU1Cell7Voltage().setNum(mod0CellVoltages[6]);
    ui_.setBatteryCMU1Cell8Voltage().setNum(mod0CellVoltages[7]);
}

void PowerView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
     ui_.setBatteryCMU2Temp().setNum(mod1PcbTemperature);
} 

void PowerView::mod1CellVoltagesReceived(QList<double> mod1CellVoltages)
{
    ui_.setBatteryCMU2Cell1Voltage().setNum(mod1CellVoltages[0]);
    ui_.setBatteryCMU2Cell2Voltage().setNum(mod1CellVoltages[1]);
    ui_.setBatteryCMU2Cell3Voltage().setNum(mod1CellVoltages[2]);
    ui_.setBatteryCMU2Cell4Voltage().setNum(mod1CellVoltages[3]);
    ui_.setBatteryCMU2Cell5Voltage().setNum(mod1CellVoltages[4]);
    ui_.setBatteryCMU2Cell6Voltage().setNum(mod1CellVoltages[5]);
    ui_.setBatteryCMU2Cell7Voltage().setNum(mod1CellVoltages[6]);
    ui_.setBatteryCMU2Cell8Voltage().setNum(mod1CellVoltages[7]);
}

void PowerView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.setBatteryCMU3Temp().setNum(mod2PcbTemperature);
} 

void PowerView::mod2CellVoltagesReceived(QList<double> mod2CellVoltages)
{
    ui_.setBatteryCMU3Cell1Voltage().setNum(mod2CellVoltages[0]);
    ui_.setBatteryCMU3Cell2Voltage().setNum(mod2CellVoltages[1]);
    ui_.setBatteryCMU3Cell3Voltage().setNum(mod2CellVoltages[2]);
    ui_.setBatteryCMU3Cell4Voltage().setNum(mod2CellVoltages[3]);
    ui_.setBatteryCMU3Cell5Voltage().setNum(mod2CellVoltages[4]);
    ui_.setBatteryCMU3Cell6Voltage().setNum(mod2CellVoltages[5]);
    ui_.setBatteryCMU3Cell7Voltage().setNum(mod2CellVoltages[6]);
    ui_.setBatteryCMU3Cell8Voltage().setNum(mod2CellVoltages[7]);
}

void PowerView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{   
    ui_.setBatteryCMU4Temp().setNum(mod3PcbTemperature);
}

void PowerView::mod3CellVoltagesReceived(QList<double> mod3CellVoltages)
{
    ui_.setBatteryCMU4Cell1Voltage().setNum(mod3CellVoltages[0]);
    ui_.setBatteryCMU4Cell2Voltage().setNum(mod3CellVoltages[1]);
    ui_.setBatteryCMU4Cell3Voltage().setNum(mod3CellVoltages[2]);
    ui_.setBatteryCMU4Cell4Voltage().setNum(mod3CellVoltages[3]);
    ui_.setBatteryCMU4Cell5Voltage().setNum(mod3CellVoltages[4]);
    ui_.setBatteryCMU4Cell6Voltage().setNum(mod3CellVoltages[5]);
    ui_.setBatteryCMU4Cell7Voltage().setNum(mod3CellVoltages[6]);
    ui_.setBatteryCMU4Cell8Voltage().setNum(mod3CellVoltages[7]);
}

PowerView::~PowerView()
{
}


void PowerView::handleGraph1Selected()
{
    
}
void PowerView::handleGraph2Selected()
{
    
}
void PowerView::handleGraph3Selected()
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


#include "CommunicationLayer/CommDeviceControl/CommDefines.h"
#include "PowerView.h"
#include "PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "PresenterLayer/CommunicationPresenter/CommunicationPresenter.h"
#include "PresenterLayer/GraphsPresenter/PowerGraphsPresenter.h"
#include "PresenterLayer/PowerPresenter/PowerPresenter.h"
#include "PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "ViewLayer/PowerUI/PowerUI.h"
#include <QtGlobal>
#include <QDebug>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

PowerView::PowerView(BatteryPresenter& batteryPresenter,
                     VehiclePresenter& vehiclePresenter,
                     PowerPresenter& powerPresenter,
                     PowerGraphsPresenter& graphsPresenter,
                     CommunicationPresenter& communicationPresenter,
                     PowerUI& ui)
: batteryPresenter_(batteryPresenter)
, vehiclePresenter_(vehiclePresenter)
, powerPresenter_(powerPresenter)
, graphsPresenter_(graphsPresenter)
, communicationPresenter_(communicationPresenter)
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
    connect(&powerPresenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));
    connect(&powerPresenter_, SIGNAL(busCurrentAReceived(double)),
            this, SLOT(busCurrentAReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryCurrentReceived(double)),
            this, SLOT(batteryCurrentReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryVoltageReceived(double)),
            this, SLOT(batteryVoltageReceived(double)));

    connect(&communicationPresenter_, SIGNAL(secondsSinceLastPacketReceivedUpdated(int)),
            this, SLOT(secondsSinceLastPacketUpdated(int)));
    connect(&communicationPresenter_, SIGNAL(packetsReceivedInLastMinuteUpdated(int)),
            this, SLOT(packetInLastMinuteUpdated(int)));
    connect(&communicationPresenter_, SIGNAL(secondsSinceLastValidPacketReceivedUpdated(int)),
            this, SLOT(secondsSinceLastValidPacketUpdated(int)));
    connect(&communicationPresenter_, SIGNAL(validPacketsReceivedInLastMinuteUpdated(int)),
            this, SLOT(validPacketsInLastMinuteUpdated(int)));
    connect(&communicationPresenter_, SIGNAL(invalidPacketsReceivedInLastMinuteUpdated(int)),
            this, SLOT(invalidPacketsInLastMinuteUpdated(int)));

    connect(&batteryPresenter_, SIGNAL(mod0CellTemperatureReceived(double)),
            this, SLOT(mod0CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
            this, SLOT(mod0CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod0CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod1CellTemperatureReceived(double)),
            this, SLOT(mod1CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
            this, SLOT(mod1CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod1CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod2CellTemperatureReceived(double)),
            this, SLOT(mod2CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
            this, SLOT(mod2CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod2CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));
    connect(&batteryPresenter_, SIGNAL(mod3CellTemperatureReceived(double)),
            this, SLOT(mod3CellTemperatureReceived(double)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
            this, SLOT(mod3CellVoltagesReceived(QList<double>)));
    connect(&batteryPresenter_, SIGNAL(mod3CellVoltagesReceived(QList<double>)),
            this, SLOT(highlightMinMaxVoltages()));

    connect(&graphsPresenter_, SIGNAL(busCurrentGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateBusCurrentGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(busVoltageGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateBusVoltageGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(busPowerGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateBusPowerGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(drivingCurrentGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateDriverCurrentGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(drivingSpeedGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateDriverSpeedGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(cellTemperatureGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateBatteryCellTempGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(cellVoltageGraphDataUpdated(PowerGraphData)),
            this, SLOT(updateBatteryCellVoltageGraph(PowerGraphData)));
    connect(&graphsPresenter_, SIGNAL(batteryPowerGraphUpdated(PowerGraphData)),
            this, SLOT(updateBatteryPowerGraph(PowerGraphData)));

    connect(&ui.connectButton(), SIGNAL(clicked()),
            this, SLOT(handleConnectButtonClicked()));
    connect(&ui.busGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleBusGraphButtonClicked()));
    connect(&ui.driverGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleDriverGraphButtonClicked()));
    connect(&ui.batteryGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleBatteryGraphButtonClicked()));

    connect(&ui.getConnectionType(), SIGNAL(currentIndexChanged(QString)),
            this, SLOT(toggleSerialParameters(QString)));
    connect(&communicationPresenter_, SIGNAL(connectionSucceeded()),
            this, SLOT(connectionSucceeded()));
    connect(&communicationPresenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));

    ui_.getSerialParametersWidget().hide();
}

bool PowerView::isValuesGarbage(QList<double> values)
{
    foreach(double value, values){
        if(value < -10000 || value > 10000){
            return true;
        }
    }
    return false;
}


void PowerView::driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double driverSetSpeedKph = driverSetSpeedMetersPerSecond * 3.6;
    ui_.setSpeed().setNum(driverSetSpeedKph);
}
void PowerView::driverSetCurrentReceived(double driverSetCurrent)
{
    ui_.setCurrent().setNum(driverSetCurrent);
}
void PowerView::vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond)
{
    //Convert meters per second to kilometers per hour
    double vehicleVelocityKph = vehicleVelocityMetersPerSecond * 3.6;
    ui_.actualSpeed().setNum(vehicleVelocityKph);
}
void PowerView::busCurrentAReceived(double busCurrentA)
{
   ui_.busCurrent().setNum(busCurrentA);
}
void PowerView::busVoltageReceived(double busVoltage)
{
    ui_.busVoltage().setNum(busVoltage);
}
void PowerView::batteryCurrentReceived(double batteryCurrent)
{
    ui_.batteryCurrent().setNum(batteryCurrent);
}
void PowerView::batteryVoltageReceived(double batteryVoltage)
{
    ui_.batteryVoltage().setNum(batteryVoltage);
}



void PowerView::mod0CellTemperatureReceived(double mod0PcbTemperature)
{
    ui_.batteryCMU1Temp().setNum(mod0PcbTemperature);
}

void PowerView::mod0CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.batteryCMU1Cell1Voltage().setText("Err");
        ui_.batteryCMU1Cell2Voltage().setText("Err");
        ui_.batteryCMU1Cell3Voltage().setText("Err");
        ui_.batteryCMU1Cell4Voltage().setText("Err");
        ui_.batteryCMU1Cell5Voltage().setText("Err");
        ui_.batteryCMU1Cell6Voltage().setText("Err");
        ui_.batteryCMU1Cell7Voltage().setText("Err");
        ui_.batteryCMU1Cell8Voltage().setText("Err");
    } else {
        ui_.batteryCMU1Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.batteryCMU1Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.batteryCMU1Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.batteryCMU1Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.batteryCMU1Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.batteryCMU1Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.batteryCMU1Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.batteryCMU1Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void PowerView::mod1CellTemperatureReceived(double mod1PcbTemperature)
{
     ui_.batteryCMU2Temp().setNum(mod1PcbTemperature);
}

void PowerView::mod1CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.batteryCMU2Cell1Voltage().setText("Err");
        ui_.batteryCMU2Cell2Voltage().setText("Err");
        ui_.batteryCMU2Cell3Voltage().setText("Err");
        ui_.batteryCMU2Cell4Voltage().setText("Err");
        ui_.batteryCMU2Cell5Voltage().setText("Err");
        ui_.batteryCMU2Cell6Voltage().setText("Err");
        ui_.batteryCMU2Cell7Voltage().setText("Err");
        ui_.batteryCMU2Cell8Voltage().setText("Err");
    } else {
        ui_.batteryCMU2Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.batteryCMU2Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.batteryCMU2Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.batteryCMU2Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.batteryCMU2Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.batteryCMU2Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.batteryCMU2Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.batteryCMU2Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void PowerView::mod2CellTemperatureReceived(double mod2PcbTemperature)
{
    ui_.batteryCMU3Temp().setNum(mod2PcbTemperature);
}

void PowerView::mod2CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.batteryCMU3Cell1Voltage().setText("Err");
        ui_.batteryCMU3Cell2Voltage().setText("Err");
        ui_.batteryCMU3Cell3Voltage().setText("Err");
        ui_.batteryCMU3Cell4Voltage().setText("Err");
        ui_.batteryCMU3Cell5Voltage().setText("Err");
        ui_.batteryCMU3Cell6Voltage().setText("Err");
        ui_.batteryCMU3Cell7Voltage().setText("Err");
        ui_.batteryCMU3Cell8Voltage().setText("Err");
    } else {
        ui_.batteryCMU3Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.batteryCMU3Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.batteryCMU3Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.batteryCMU3Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.batteryCMU3Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.batteryCMU3Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.batteryCMU3Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.batteryCMU3Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void PowerView::mod3CellTemperatureReceived(double mod3PcbTemperature)
{
    ui_.batteryCMU4Temp().setNum(mod3PcbTemperature);
}

void PowerView::mod3CellVoltagesReceived(QList<double> cellVoltages)
{
    if (isValuesGarbage(cellVoltages)){
        ui_.batteryCMU4Cell1Voltage().setText("Err");
        ui_.batteryCMU4Cell2Voltage().setText("Err");
        ui_.batteryCMU4Cell3Voltage().setText("Err");
        ui_.batteryCMU4Cell4Voltage().setText("Err");
        ui_.batteryCMU4Cell5Voltage().setText("Err");
        ui_.batteryCMU4Cell6Voltage().setText("Err");
        ui_.batteryCMU4Cell7Voltage().setText("Err");
        ui_.batteryCMU4Cell8Voltage().setText("Err");
    } else {
        ui_.batteryCMU4Cell1Voltage().setText(QString::number(cellVoltages[0], 'f', 3));
        ui_.batteryCMU4Cell2Voltage().setText(QString::number(cellVoltages[1], 'f', 3));
        ui_.batteryCMU4Cell3Voltage().setText(QString::number(cellVoltages[2], 'f', 3));
        ui_.batteryCMU4Cell4Voltage().setText(QString::number(cellVoltages[3], 'f', 3));
        ui_.batteryCMU4Cell5Voltage().setText(QString::number(cellVoltages[4], 'f', 3));
        ui_.batteryCMU4Cell6Voltage().setText(QString::number(cellVoltages[5], 'f', 3));
        ui_.batteryCMU4Cell7Voltage().setText(QString::number(cellVoltages[6], 'f', 3));
        ui_.batteryCMU4Cell8Voltage().setText(QString::number(cellVoltages[7], 'f', 3));
    }
}

void PowerView::highlightMinMaxVoltages()
{
    QLabel* newMaxVoltageLabel = ui_.batteryCMUCellVoltageLabels()[0];
    double newMaxVoltage = newMaxVoltageLabel->text().toFloat();
    QLabel* newMinVoltageLabel = ui_.batteryCMUCellVoltageLabels()[0];
    double newMinVoltage = newMinVoltageLabel->text().toFloat();

    foreach(QLabel* cursorVoltageLabel, ui_.batteryCMUCellVoltageLabels())
    {
        double cursorVoltage = cursorVoltageLabel->text().toFloat();
        cursorVoltageLabel->setStyleSheet("");
        if(cursorVoltage > 0)
        {
            if(cursorVoltage > newMaxVoltage)
            {
                newMaxVoltageLabel = cursorVoltageLabel;
                newMaxVoltage = cursorVoltage;
            }
            if(cursorVoltage < newMinVoltage)
            {
                newMinVoltageLabel = cursorVoltageLabel;
                newMinVoltage = cursorVoltage;
            }
        }
    }
    newMaxVoltageLabel->setStyleSheet("font-weight: bold; background-color: rgb(100, 100, 100);");
    newMinVoltageLabel->setStyleSheet("font-weight: bold; background-color: rgb(100, 100, 100);");
    highlightUntrustedVoltages();
}

void PowerView::highlightUntrustedVoltages()
{
    foreach(QLabel* cursorVoltageLabel, ui_.batteryCMUCellVoltageLabels())
    {
        if(cursorVoltageLabel->text().toFloat() < 0)
        {
            QString stylesheet = cursorVoltageLabel->styleSheet();
            cursorVoltageLabel->setStyleSheet(stylesheet + "color: yellow");
            cursorVoltageLabel->setText(cursorVoltageLabel->text().right(1));
        }
    }
}

void PowerView::updateBusCurrentGraph(PowerGraphData graphData)
{
    ui_.positiveBusCurrentCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.negativeBusCurrentCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
}
void PowerView::updateBusVoltageGraph(PowerGraphData graphData)
{
    ui_.busVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateBusPowerGraph(PowerGraphData graphData)
{
    ui_.busPowerCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateDriverSpeedGraph(PowerGraphData graphData)
{
    ui_.setSpeedCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.actualSpeedCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
}
void PowerView::updateDriverCurrentGraph(PowerGraphData graphData)
{
    ui_.setCurrentCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateBatteryCellTempGraph(PowerGraphData graphData)
{
    ui_.mod0CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.mod1CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
    ui_.mod2CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[2]);
    ui_.mod3CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[3]);
}
void PowerView::updateBatteryCellVoltageGraph(PowerGraphData graphData)
{
    ui_.maxCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.avgCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
    ui_.minCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[2]);
}
void PowerView::updateBatteryPowerGraph(PowerGraphData graphData)
{
    ui_.batteryPowerCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}

void PowerView::secondsSinceLastPacketUpdated(int secondsSinceLastPacket)
{
    ui_.secondsSinceLastPacket().setNum(secondsSinceLastPacket);
    if(secondsSinceLastPacket <= 1)
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth5of5.png);");
    }
    else if(secondsSinceLastPacket <= 2)
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth4of5.png);");
    }
    else if(secondsSinceLastPacket <= 3)
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth3of5.png);");
    }
    else if(secondsSinceLastPacket <= 4)
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth2of5.png);");
    }
    else if(secondsSinceLastPacket <= 10)
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth1of5.png);");
    }
    else
    {
        ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth0of5.png);");
    }
}

void PowerView::packetInLastMinuteUpdated(int packetInLastMinute)
{
    ui_.packetInLastMinute().setNum(packetInLastMinute);
}

void PowerView::secondsSinceLastValidPacketUpdated(int secondsSinceLastValidPacket)
{
    ui_.secondsSinceLastValidPacket().setNum(secondsSinceLastValidPacket);
}

void PowerView::validPacketsInLastMinuteUpdated(int validPacketsInLastMinute)
{
    ui_.validPacketsInLastMinute().setNum(validPacketsInLastMinute);
}

void PowerView::invalidPacketsInLastMinuteUpdated(int invalidPacketsInLastMinute)
{
    ui_.invalidPacketsInLastMinute().setNum(invalidPacketsInLastMinute);
}


void PowerView::handleConnectButtonClicked()
{
    if(ui_.connectButton().text() == "Connect"){
        ui_.connectionStatus().setText("Connecting...");
        ui_.connectionStatus().setStyleSheet("text-align: centre; color: yellow; background-color: rgb(70,70,70);");
        if(ui_.getConnectionType().currentText() == "User")
        {
            communicationPresenter_.setMulticastNetwork(ui_.getUdpGroupAddress().text(),
                ui_.getUdpPortNumber().value());
            communicationPresenter_.connectToDataSource((CommDefines::Udp));
        }
        else if(ui_.getConnectionType().currentText() == "Host")
        {
            communicationPresenter_.setMulticastNetwork(ui_.getUdpGroupAddress().text(),
                ui_.getUdpPortNumber().value());
            communicationPresenter_.setSerialParameters(ui_.getSerialPortName().text(),
                ui_.getBaudRate().text().toDouble());
            communicationPresenter_.connectToDataSource(CommDefines::Serial);
        }
        else
        {
            qDebug() << "Connect button selecting connection type error, check PowerView.cpp";
        }
    }
    else if(ui_.connectButton().text() == "Disconnect"){
        communicationPresenter_.disconnectFromDataSource();
        graphsPresenter_.stopUpdating();
    }
}

void PowerView::handleBusGraphButtonClicked()
{
    ui_.graphsStackedWidget().setCurrentIndex(0); // Bus Graphs Index
    selectGraphButton(&ui_.busGraphButton());
}

void PowerView::handleDriverGraphButtonClicked()
{
    ui_.graphsStackedWidget().setCurrentIndex(1); // Driver Graphs Index
        selectGraphButton(&ui_.driverGraphButton());
}

void PowerView::handleBatteryGraphButtonClicked()
{
    ui_.graphsStackedWidget().setCurrentIndex(2); // Battery Graphs Index
        selectGraphButton(&ui_.batteryGraphButton());
}
void PowerView::selectGraphButton(QPushButton* selectedGraph)
{
    QList<QPushButton*> graphButtons;
    graphButtons.append(&ui_.batteryGraphButton());
    graphButtons.append(&ui_.busGraphButton());
    graphButtons.append(&ui_.driverGraphButton());

    const char *GRAPH_BUTTON_PRESSED =
    "QPushButton {"
        "background-color: rgb(130,130,130);"
        "border-radius: 1px;"
        "padding: 3px;"
    "}"
    "QPushButton:hover:!pressed {"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                          "stop: 0 rgb(130,130,130), stop: 1 rgb(150,150,150));"
    "}";

    const char *GRAPH_BUTTON_UNPRESSED =
    "QPushButton {"
        "background-color: rgb(90, 90, 90);"
        "border-radius: 1px;"
        "padding: 3px;"
    "}"
    "QPushButton:hover:!pressed {"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                          "stop: 0 rgb(90, 90, 90), stop: 1 rgb(120,120,120));"
    "}";
    foreach(QPushButton* button, graphButtons)
    {
        button->setStyleSheet(GRAPH_BUTTON_UNPRESSED);
    }
    selectedGraph->setStyleSheet(GRAPH_BUTTON_PRESSED);
}

void PowerView::toggleSerialParameters(QString connectionType)
{
    if(connectionType == "Host")
    {
        ui_.getSerialParametersWidget().show();
    }
    else 
    {
        ui_.getSerialParametersWidget().hide();
    }
}

void PowerView::connectionFailed(QString failureMessage)
{
    ui_.connectButton().setText("Connect");
    ui_.connectionStatus().setText(failureMessage);
    ui_.connectionStatus().setStyleSheet("text-align: centre; color: rgb(255, 40, 40); background-color: rgb(70,70,70);"); // red text
    ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth0of5.png);");
}

void PowerView::connectionSucceeded()
{
    ui_.connectButton().setText("Disconnect");
    ui_.connectionStatus().setText("Connected");
    ui_.connectionStatus().setStyleSheet("text-align: centre; color: rgb(0, 255, 0); background-color: rgb(70,70,70);");
    ui_.connectionHealth().setStyleSheet("background: url(:/Resources/ConnectionHealth1of5.png);");
    graphsPresenter_.startUpdating();
}

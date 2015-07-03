#include "PowerView.h"
#include "../../PresenterLayer/BatteryPresenter/BatteryPresenter.h"
#include "../../PresenterLayer/VehiclePresenter/VehiclePresenter.h"
#include "../../PresenterLayer/GraphsPresenter/PowerGraphsPresenter.h"
#include "../../PresenterLayer/CommunicationPresenter/CommunicationPresenter.h"
#include "../PowerUI/PowerUI.h"
#include <QDebug>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

PowerView::PowerView(BatteryPresenter& batteryPresenter,
                     VehiclePresenter& vehiclePresenter,
                     PowerGraphsPresenter& graphsPresenter,
                     CommunicationPresenter& communicationPresenter,
                     PowerUI& ui)
: batteryPresenter_(batteryPresenter)
, vehiclePresenter_(vehiclePresenter)
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
    connect(&vehiclePresenter_, SIGNAL(busVoltageReceived(double)),
            this, SLOT(busVoltageReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryCurrentReceived(double)),
            this, SLOT(batteryCurrentAReceived(double)));
    connect(&batteryPresenter_, SIGNAL(batteryVoltageReceived(double)),
            this, SLOT(batteryVoltageReceived(double)));

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

    connect(&ui.connectButton(), SIGNAL(clicked()),
            this, SLOT(handleConnectButtonClicked()));
    connect(&ui.busGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleBusGraphButtonClicked()));
    connect(&ui.driverGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleDriverGraphButtonClicked()));
    connect(&ui.batteryGraphButton(), SIGNAL(clicked()),
            this, SLOT(handleBatteryGraphButtonClicked()));

    connect(&communicationPresenter_, SIGNAL(connectionFailed(QString)),
            this, SLOT(connectionFailed(QString)));
    connect(&communicationPresenter_, SIGNAL(connectionSucceeded(QString)),
            this, SLOT(connectionSucceeded(QString)));
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
void PowerView::batteryCurrentReceived(double batteryCurrent)
{
    ui_.setBatteryCurrent().setNum(batteryCurrent);
}
void PowerView::batteryVoltageReceived(double batteryVoltage)
{
    ui_.setBatteryVoltage().setNum(batteryVoltage);
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

void PowerView::updateBusCurrentGraph(PowerGraphData graphData)
{
    ui_.setBusCurrentCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateBusVoltageGraph(PowerGraphData graphData)
{
    ui_.setBusVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateBusPowerGraph(PowerGraphData graphData)
{
    ui_.setBusPowerCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateDriverSpeedGraph(PowerGraphData graphData)
{
    ui_.setSetSpeedCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.setActualSpeedCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
}
void PowerView::updateDriverCurrentGraph(PowerGraphData graphData)
{
    ui_.setSetCurrentCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
}
void PowerView::updateBatteryCellTempGraph(PowerGraphData graphData)
{
    ui_.setMod0CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.setMod1CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
    ui_.setMod2CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[2]);
    ui_.setMod3CellTempCurve().setSamples(graphData.xData(), graphData.yDataSets()[3]);
}
void PowerView::updateBatteryCellVoltageGraph(PowerGraphData graphData)
{
    ui_.setMaxCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[0]);
    ui_.setAvgCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[1]);
    ui_.setMinCellVoltageCurve().setSamples(graphData.xData(), graphData.yDataSets()[2]);
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
        communicationPresenter_.connectDataSource(ui_.getSerialPortName().text(),
                                     ui_.getBaudRate().text().toDouble());
    }
    else if(ui_.connectButton().text() == "Disconnect"){
        communicationPresenter_.disconnectDataSource();
        graphsPresenter_.stopUpdating();
    }
}


void PowerView::handleBusGraphButtonClicked()
{
    ui_.setGraphsStackedWidget().setCurrentIndex(0); // Bus Graphs Index
    selectGraphButton(&ui_.busGraphButton());
}

void PowerView::handleDriverGraphButtonClicked()
{
    ui_.setGraphsStackedWidget().setCurrentIndex(1); // Driver Graphs Index
        selectGraphButton(&ui_.driverGraphButton());
}

void PowerView::handleBatteryGraphButtonClicked()
{
    ui_.setGraphsStackedWidget().setCurrentIndex(2); // Battery Graphs Index
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
    graphsPresenter_.startUpdating();
}

void PowerView::clearDebugLog()
{
    ui_.setDebugLog().clear();
}

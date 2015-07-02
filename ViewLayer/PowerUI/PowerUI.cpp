#include "PowerUI.h"
#include "ui_PowerUI.h"
#include <qwt_legend.h>
#include <QDebug>


PowerUI::PowerUI() 
: ui_(new Ui::PowerUI)
{

    ui_->setupUi(this);
    busCurrentCurve_ = new QwtPlotCurve("Bus Current");
    busVoltageCurve_ = new QwtPlotCurve("Bus Voltage");
    busPowerCurve_ = new QwtPlotCurve("Bus Power");
    setSpeedCurve_ = new QwtPlotCurve("Set");
    actualSpeedCurve_ = new QwtPlotCurve("Actual");
    setCurrentCurve_ = new QwtPlotCurve("Set Current");
    maxCellTempCurve_ = new QwtPlotCurve("Max");
    avgCellTempCurve_ = new QwtPlotCurve("Avg");
    minCellTempCurve_ = new QwtPlotCurve("Min");
    maxCellVoltageCurve_ = new QwtPlotCurve("Max");
    minCellVoltageCurve_ = new QwtPlotCurve("Min");
    avgCellVoltageCurve_ = new QwtPlotCurve("Avg");
    setupGraphs();
}

PowerUI::~PowerUI()
{
    delete ui_;
}

void PowerUI::hideHeaderBar()
{
    ui_->powerTitleBar->hide();
}

QPushButton& PowerUI::connectButton()
{
   return *ui_->connectButton;
}
QLabel& PowerUI::setConnectionStatus()
{
    return *ui_->connectionStatus;
}
QWidget& PowerUI::setConnectionHealth()
{
    return *ui_->connectionHealthImage;
}
QLineEdit& PowerUI::getSerialPortName()
{
   return *ui_->serialPortName;
}
QLineEdit& PowerUI::getBaudRate()
{
   return *ui_->baudrate;
}
QTextEdit& PowerUI::setDebugLog()
{
    return *ui_->connectionOutput;
}

QLabel& PowerUI::setSetSpeed()
{
    return *ui_->setSpeed;
}
QLabel& PowerUI::setSetCurrent()
{
    return *ui_->setCurrent;
}
QLabel& PowerUI::setActualSpeed()
{
    return *ui_->actualSpeed;
}    

QLabel& PowerUI::setBusCurrent()
{
    return *ui_->busCurrent;
}

QLabel& PowerUI::setBusVoltage()
{
    return *ui_->busVoltage;
}
QLabel& PowerUI::setBatteryCurrent()
{
    return *ui_->batteryCurrent;
}
QLabel& PowerUI::setBatteryVoltage()
{
    return *ui_->batteryVoltage;
}


QLabel& PowerUI::setBatteryCMU1Temp()
{
    return *ui_->batteryCMU1Temp;
}
QLabel& PowerUI::setBatteryCMU1Cell1Voltage()
{
    return *ui_->batteryCMU1Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell2Voltage()
{
    return *ui_->batteryCMU1Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell3Voltage()
{
    return *ui_->batteryCMU1Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell4Voltage()
{
    return *ui_->batteryCMU1Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell5Voltage()
{
    return *ui_->batteryCMU1Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell6Voltage()
{
    return *ui_->batteryCMU1Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell7Voltage()
{
    return *ui_->batteryCMU1Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU1Cell8Voltage()
{
    return *ui_->batteryCMU1Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU2Temp()
{
    return *ui_->batteryCMU2Temp;
}
QLabel& PowerUI::setBatteryCMU2Cell1Voltage()
{
    return *ui_->batteryCMU2Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell2Voltage()
{
    return *ui_->batteryCMU2Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell3Voltage()
{
    return *ui_->batteryCMU2Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell4Voltage()
{
    return *ui_->batteryCMU2Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell5Voltage()
{
    return *ui_->batteryCMU2Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell6Voltage()
{
    return *ui_->batteryCMU2Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell7Voltage()
{
    return *ui_->batteryCMU2Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU2Cell8Voltage()
{
    return *ui_->batteryCMU2Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU3Temp()
{
    return *ui_->batteryCMU3Temp;
}
QLabel& PowerUI::setBatteryCMU3Cell1Voltage()
{
    return *ui_->batteryCMU3Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell2Voltage()
{
    return *ui_->batteryCMU3Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell3Voltage()
{
    return *ui_->batteryCMU3Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell4Voltage()
{
    return *ui_->batteryCMU3Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell5Voltage()
{
    return *ui_->batteryCMU3Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell6Voltage()
{
    return *ui_->batteryCMU3Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell7Voltage()
{
    return *ui_->batteryCMU3Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU3Cell8Voltage()
{
    return *ui_->batteryCMU3Cell8Voltage;
}

QLabel& PowerUI::setBatteryCMU4Temp()
{
    return *ui_->batteryCMU4Temp;
}
QLabel& PowerUI::setBatteryCMU4Cell1Voltage()
{
    return *ui_->batteryCMU4Cell1Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell2Voltage()
{
    return *ui_->batteryCMU4Cell2Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell3Voltage()
{
    return *ui_->batteryCMU4Cell3Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell4Voltage()
{
    return *ui_->batteryCMU4Cell4Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell5Voltage()
{
    return *ui_->batteryCMU4Cell5Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell6Voltage()
{
    return *ui_->batteryCMU4Cell6Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell7Voltage()
{
    return *ui_->batteryCMU4Cell7Voltage;
}
QLabel& PowerUI::setBatteryCMU4Cell8Voltage()
{
    return *ui_->batteryCMU4Cell8Voltage;
}

QPushButton& PowerUI::busGraphButton()
{
    return *ui_->busGraphButton;
}
QPushButton& PowerUI::driverGraphButton()
{
    return *ui_->driverGraphButton;
}
QPushButton& PowerUI::batteryGraphButton()
{
    return *ui_->batteryGraphButton;
}


QStackedWidget& PowerUI::setGraphsStackedWidget()
{
    return *ui_->graphsStackedWidget;
}
QwtPlotCurve& PowerUI::setBusCurrentCurve()
{
    return *busCurrentCurve_;
} 
QwtPlotCurve& PowerUI::setBusVoltageCurve()
{
    return *busVoltageCurve_;
} 
QwtPlotCurve& PowerUI::setBusPowerCurve()
{
    return *busPowerCurve_;
} 
QwtPlotCurve& PowerUI::setSetSpeedCurve()
{
    return *setSpeedCurve_;
} 
QwtPlotCurve& PowerUI::setActualSpeedCurve()
{
    return *actualSpeedCurve_;
} 
QwtPlotCurve& PowerUI::setSetCurrentCurve()
{
    return *setCurrentCurve_;
}
QwtPlotCurve& PowerUI::setMaxCellTempCurve()
{
    return *maxCellTempCurve_;
}
QwtPlotCurve& PowerUI::setAvgCellTempCurve()
{
    return *avgCellTempCurve_;
}
QwtPlotCurve& PowerUI::setMinCellTempCurve()
{
    return *minCellTempCurve_;
}
QwtPlotCurve& PowerUI::setMaxCellVoltageCurve()
{
    return *maxCellVoltageCurve_;
}
QwtPlotCurve& PowerUI::setMinCellVoltageCurve()
{
    return *minCellVoltageCurve_;
}
QwtPlotCurve& PowerUI::setAvgCellVoltageCurve()
{
    return *avgCellVoltageCurve_;
}

void PowerUI::setupGraphs()
{
    int MAX_BUS_CURRENT = 100; // Amperes
    int MAX_BUS_VOLTAGE = 140; // Volts
    int MAX_BUS_POWER = 3000;  // Watts
    int MAX_DRIVER_CURRENT = 100; // Percentage
    int MAX_DRIVER_SPEED = 120; // Kilometers per hour
    int MAX_BATTERY_CELL_TEMP = 80; // Degrees Celsius
    int MAX_BATTERY_CELL_VOLTAGE = 4000; // Millivolts

    int MAX_SECONDS_ELAPSED = 60; 

    ui_->busCurrentGraph->setTitle("Bus Current Graph");
    ui_->busCurrentGraph->setAxisTitle(QwtPlot::yLeft, "Current (A)");
    ui_->busCurrentGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BUS_CURRENT, MAX_BUS_CURRENT/5);
    ui_->busCurrentGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->busCurrentGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    busCurrentCurve_->setPen(*new QPen(Qt::yellow));
    busCurrentCurve_->attach(ui_->busCurrentGraph);
    // QwtLegend* busCurrentGraphLegend = new QwtLegend;
    // ui_->busCurrentGraph->insertLegend(busCurrentGraphLegend, QwtPlot::RightLegend);

    ui_->busVoltageGraph->setTitle("Bus Voltage Graph");
    ui_->busVoltageGraph->setAxisTitle(QwtPlot::yLeft, "Voltage (V)");
    ui_->busVoltageGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BUS_VOLTAGE, MAX_BUS_VOLTAGE/5);
    ui_->busVoltageGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->busVoltageGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    busVoltageCurve_->setPen(*new QPen(Qt::yellow));
    busVoltageCurve_->attach(ui_->busVoltageGraph);
    // QwtLegend* busVoltageGraphLegend = new QwtLegend;
    // ui_->busVoltageGraph->insertLegend(busVoltageGraphLegend, QwtPlot::RightLegend);

    ui_->busPowerGraph->setTitle("Bus Power Graph");
    ui_->busPowerGraph->setAxisTitle(QwtPlot::yLeft, "Power (W)");
    ui_->busPowerGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BUS_POWER, MAX_BUS_POWER/5);
    ui_->busPowerGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->busPowerGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    busPowerCurve_->setPen(*new QPen(Qt::yellow));
    busPowerCurve_->attach(ui_->busPowerGraph);
    // QwtLegend* busPowerGraphLegend = new QwtLegend;
    // ui_->busPowerGraph->insertLegend(busPowerGraphLegend, QwtPlot::RightLegend);

    ui_->driverSpeedGraph->setTitle("Driver Speed Graph");
    ui_->driverSpeedGraph->setAxisTitle(QwtPlot::yLeft, "Speed (kph)");
    ui_->driverSpeedGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_DRIVER_SPEED, MAX_DRIVER_SPEED/5);
    ui_->driverSpeedGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->driverSpeedGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    setSpeedCurve_->setPen(*new QPen(Qt::yellow));
    setSpeedCurve_->attach(ui_->driverSpeedGraph);
    actualSpeedCurve_->setPen(*new QPen(Qt::red));
    actualSpeedCurve_->attach(ui_->driverSpeedGraph);
    QwtLegend* driverSpeedGraphLegend = new QwtLegend;
    ui_->driverSpeedGraph->insertLegend(driverSpeedGraphLegend, QwtPlot::RightLegend);

    ui_->driverCurrentGraph->setTitle("Driver Current Graph");
    ui_->driverCurrentGraph->setAxisTitle(QwtPlot::yLeft, "Percent (%)");
    ui_->driverCurrentGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_DRIVER_CURRENT, MAX_DRIVER_CURRENT/5);
    ui_->driverCurrentGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->driverCurrentGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    setCurrentCurve_->setPen(*new QPen(Qt::yellow));
    setCurrentCurve_->attach(ui_->driverCurrentGraph);
    // QwtLegend* driverCurrentGraphLegend = new QwtLegend;
    // ui_->driverCurrentGraph->insertLegend(driverCurrentGraphLegend, QwtPlot::RightLegend);

    ui_->batteryCellTempGraph->setTitle("Battery Cell Temp Graph");
    ui_->batteryCellTempGraph->setAxisTitle(QwtPlot::yLeft, "Temperature (C)");
    ui_->batteryCellTempGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BATTERY_CELL_TEMP, MAX_BATTERY_CELL_TEMP/5);
    ui_->batteryCellTempGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->batteryCellTempGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    maxCellTempCurve_->setPen(*new QPen(Qt::green));
    maxCellTempCurve_->attach(ui_->batteryCellTempGraph);
    avgCellTempCurve_->setPen(*new QPen(Qt::yellow));
    avgCellTempCurve_->attach(ui_->batteryCellTempGraph);
    minCellTempCurve_->setPen(*new QPen(Qt::red));
    minCellTempCurve_->attach(ui_->batteryCellTempGraph);
    QwtLegend* batteryCellTempGraphLegend = new QwtLegend;
    ui_->batteryCellTempGraph->insertLegend(batteryCellTempGraphLegend, QwtPlot::RightLegend);

    ui_->batteryCellVoltageGraph->setTitle("Battery Cell Voltage Graph");
    ui_->batteryCellVoltageGraph->setAxisTitle(QwtPlot::yLeft, "Voltage (mV)");
    ui_->batteryCellVoltageGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BATTERY_CELL_VOLTAGE, MAX_BATTERY_CELL_VOLTAGE/5);
    ui_->batteryCellVoltageGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->batteryCellVoltageGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
    maxCellVoltageCurve_->setPen(*new QPen(Qt::green));
    maxCellVoltageCurve_->attach(ui_->batteryCellVoltageGraph);
    avgCellVoltageCurve_->setPen(*new QPen(Qt::yellow));
    avgCellVoltageCurve_->attach(ui_->batteryCellVoltageGraph);
    minCellVoltageCurve_->setPen(*new QPen(Qt::red));
    minCellVoltageCurve_->attach(ui_->batteryCellVoltageGraph);
    QwtLegend* batteryCellVoltageGraphLegend = new QwtLegend;
    ui_->batteryCellVoltageGraph->insertLegend(batteryCellVoltageGraphLegend, QwtPlot::RightLegend);

}

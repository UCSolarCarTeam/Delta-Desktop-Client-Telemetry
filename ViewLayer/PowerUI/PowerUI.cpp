#include "PowerUI.h"
#include "ui_PowerUI.h"
#include <QDebug>


PowerUI::PowerUI() 
: ui_(new Ui::PowerUI)
{
    ui_->setupUi(this);
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
QLabel& PowerUI::setArrayCurrent()
{
    return *ui_->arrayCurrent;
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

QwtPlot& PowerUI::setBusCurrentGraph()
{
    return *ui_->busCurrentGraph;
} 

QwtPlot& PowerUI::setBusVoltageGraph()
{
    return *ui_->busVoltageGraph;
} 

QwtPlot& PowerUI::setBusPowerGraph()
{
    return *ui_->busPowerGraph;
} 

QwtPlot& PowerUI::setDriverCurrentGraph()
{
    return *ui_->driverCurrentGraph;
} 

QwtPlot& PowerUI::setDriverSpeedGraph()
{
    return *ui_->driverSpeedGraph;
} 

QwtPlot& PowerUI::setBatteryCellTempGraph()
{
    return *ui_->batteryCellTempGraph;
} 

QwtPlot& PowerUI::setBatteryCellVoltageGraph()
{
    return *ui_->batteryCellVoltageGraph;
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

    ui_->busVoltageGraph->setTitle("Bus Voltage Graph");
    ui_->busVoltageGraph->setAxisTitle(QwtPlot::yLeft, "Voltage (V)");
    ui_->busVoltageGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BUS_VOLTAGE, MAX_BUS_VOLTAGE/5);
    ui_->busVoltageGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->busVoltageGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);

    ui_->busPowerGraph->setTitle("Bus Power Graph");
    ui_->busPowerGraph->setAxisTitle(QwtPlot::yLeft, "Power (W)");
    ui_->busPowerGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BUS_POWER, MAX_BUS_POWER/5);
    ui_->busPowerGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->busPowerGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);

    ui_->driverCurrentGraph->setTitle("Driver Current Graph");
    ui_->driverCurrentGraph->setAxisTitle(QwtPlot::yLeft, "Percent (%)");
    ui_->driverCurrentGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_DRIVER_CURRENT, MAX_DRIVER_CURRENT/5);
    ui_->driverCurrentGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->driverCurrentGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);

    ui_->driverSpeedGraph->setTitle("Driver Speed Graph");
    ui_->driverSpeedGraph->setAxisTitle(QwtPlot::yLeft, "Speed (kph)");
    ui_->driverSpeedGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_DRIVER_SPEED, MAX_DRIVER_SPEED/5);
    ui_->driverSpeedGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->driverSpeedGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);

    ui_->batteryCellTempGraph->setTitle("Battery Cell Temp Graph");
    ui_->batteryCellTempGraph->setAxisTitle(QwtPlot::yLeft, "Temperature (C)");
    ui_->batteryCellTempGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BATTERY_CELL_TEMP, MAX_BATTERY_CELL_TEMP/5);
    ui_->batteryCellTempGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->batteryCellTempGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);

    ui_->batteryCellVoltageGraph->setTitle("Battery Cell Voltage Graph");
    ui_->batteryCellVoltageGraph->setAxisTitle(QwtPlot::yLeft, "Voltage (mV)");
    ui_->batteryCellVoltageGraph->setAxisScale(QwtPlot::yLeft, 0, MAX_BATTERY_CELL_VOLTAGE, MAX_BATTERY_CELL_VOLTAGE/5);
    ui_->batteryCellVoltageGraph->setAxisTitle(QwtPlot::xBottom, "Time Elapsed (s)");
    ui_->batteryCellVoltageGraph->setAxisScale(QwtPlot::xBottom, 0, MAX_SECONDS_ELAPSED, 10);
}

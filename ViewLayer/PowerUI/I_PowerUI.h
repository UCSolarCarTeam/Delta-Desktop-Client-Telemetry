#pragma once

#include "qwt_plot.h"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QStackedWidget>
#include <QWidget>
#include <qwt_plot_curve.h>

class I_PowerUI
{
public:
    virtual ~I_PowerUI() {}

    virtual QPushButton& connectButton() = 0;
    virtual QLabel& connectionStatus() = 0;
    virtual QWidget& connectionHealth() = 0;
    virtual QComboBox& getConnectionType() = 0;
    virtual QLineEdit& getUdpGroupAddress() = 0;
    virtual QSpinBox& getUdpPortNumber() = 0;
    virtual QWidget& getSerialParametersWidget() = 0;
    virtual QLineEdit& getSerialPortName() = 0;
    virtual QLineEdit& getBaudRate() = 0;

    virtual QLabel& secondsSinceLastPacket() = 0;
    virtual QLabel& packetInLastMinute() = 0;
    virtual QLabel& secondsSinceLastValidPacket() = 0;
    virtual QLabel& validPacketsInLastMinute() = 0;
    virtual QLabel& invalidPacketsInLastMinute() = 0;

    virtual QLabel& setSpeed() = 0;
    virtual QLabel& setCurrent() = 0;
    virtual QLabel& actualSpeed() = 0;
    virtual QLabel& busCurrent() = 0;
    virtual QLabel& busVoltage() = 0;
    virtual QLabel& batteryCurrent() = 0;
    virtual QLabel& batteryVoltage() = 0;

    virtual QLabel& batteryCMU1Temp() = 0;
    virtual QLabel& batteryCMU1Cell1Voltage() = 0;
    virtual QLabel& batteryCMU1Cell2Voltage() = 0;
    virtual QLabel& batteryCMU1Cell3Voltage() = 0;
    virtual QLabel& batteryCMU1Cell4Voltage() = 0;
    virtual QLabel& batteryCMU1Cell5Voltage() = 0;
    virtual QLabel& batteryCMU1Cell6Voltage() = 0;
    virtual QLabel& batteryCMU1Cell7Voltage() = 0;
    virtual QLabel& batteryCMU1Cell8Voltage() = 0;

    virtual QLabel& batteryCMU2Temp() = 0;
    virtual QLabel& batteryCMU2Cell1Voltage() = 0;
    virtual QLabel& batteryCMU2Cell2Voltage() = 0;
    virtual QLabel& batteryCMU2Cell3Voltage() = 0;
    virtual QLabel& batteryCMU2Cell4Voltage() = 0;
    virtual QLabel& batteryCMU2Cell5Voltage() = 0;
    virtual QLabel& batteryCMU2Cell6Voltage() = 0;
    virtual QLabel& batteryCMU2Cell7Voltage() = 0;
    virtual QLabel& batteryCMU2Cell8Voltage() = 0;

    virtual QLabel& batteryCMU3Temp() = 0;
    virtual QLabel& batteryCMU3Cell1Voltage() = 0;
    virtual QLabel& batteryCMU3Cell2Voltage() = 0;
    virtual QLabel& batteryCMU3Cell3Voltage() = 0;
    virtual QLabel& batteryCMU3Cell4Voltage() = 0;
    virtual QLabel& batteryCMU3Cell5Voltage() = 0;
    virtual QLabel& batteryCMU3Cell6Voltage() = 0;
    virtual QLabel& batteryCMU3Cell7Voltage() = 0;
    virtual QLabel& batteryCMU3Cell8Voltage() = 0;

    virtual QLabel& batteryCMU4Temp() = 0;
    virtual QLabel& batteryCMU4Cell1Voltage() = 0;
    virtual QLabel& batteryCMU4Cell2Voltage() = 0;
    virtual QLabel& batteryCMU4Cell3Voltage() = 0;
    virtual QLabel& batteryCMU4Cell4Voltage() = 0;
    virtual QLabel& batteryCMU4Cell5Voltage() = 0;
    virtual QLabel& batteryCMU4Cell6Voltage() = 0;
    virtual QLabel& batteryCMU4Cell7Voltage() = 0;
    virtual QLabel& batteryCMU4Cell8Voltage() = 0;

    virtual QList<QLabel*>& batteryCMUCellVoltageLabels() = 0;

    virtual QPushButton& busGraphButton() = 0;
    virtual QPushButton& driverGraphButton() = 0;
    virtual QPushButton& batteryGraphButton() = 0;

    virtual QStackedWidget& graphsStackedWidget() = 0;
    virtual QwtPlotCurve& positiveBusCurrentCurve() = 0;
    virtual QwtPlotCurve& negativeBusCurrentCurve() = 0;
    virtual QwtPlotCurve& busVoltageCurve() = 0;
    virtual QwtPlotCurve& busPowerCurve() = 0;
    virtual QwtPlotCurve& setSpeedCurve() = 0;
    virtual QwtPlotCurve& actualSpeedCurve() = 0;
    virtual QwtPlotCurve& setCurrentCurve() = 0;
    virtual QwtPlotCurve& mod0CellTempCurve() = 0;
    virtual QwtPlotCurve& mod1CellTempCurve() = 0;
    virtual QwtPlotCurve& mod2CellTempCurve() = 0;
    virtual QwtPlotCurve& mod3CellTempCurve() = 0;
    virtual QwtPlotCurve& maxCellVoltageCurve() = 0;
    virtual QwtPlotCurve& minCellVoltageCurve() = 0;
    virtual QwtPlotCurve& avgCellVoltageCurve() = 0;
    virtual QwtPlotCurve& batteryPowerCurve() = 0;
};

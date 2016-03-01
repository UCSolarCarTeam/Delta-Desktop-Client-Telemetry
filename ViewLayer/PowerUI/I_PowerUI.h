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

    virtual QLabel& batteryCmu1Temp() = 0;
    virtual QLabel& batteryCmu1Cell1Voltage() = 0;
    virtual QLabel& batteryCmu1Cell2Voltage() = 0;
    virtual QLabel& batteryCmu1Cell3Voltage() = 0;
    virtual QLabel& batteryCmu1Cell4Voltage() = 0;
    virtual QLabel& batteryCmu1Cell5Voltage() = 0;
    virtual QLabel& batteryCmu1Cell6Voltage() = 0;
    virtual QLabel& batteryCmu1Cell7Voltage() = 0;
    virtual QLabel& batteryCmu1Cell8Voltage() = 0;

    virtual QLabel& batteryCmu2Temp() = 0;
    virtual QLabel& batteryCmu2Cell1Voltage() = 0;
    virtual QLabel& batteryCmu2Cell2Voltage() = 0;
    virtual QLabel& batteryCmu2Cell3Voltage() = 0;
    virtual QLabel& batteryCmu2Cell4Voltage() = 0;
    virtual QLabel& batteryCmu2Cell5Voltage() = 0;
    virtual QLabel& batteryCmu2Cell6Voltage() = 0;
    virtual QLabel& batteryCmu2Cell7Voltage() = 0;
    virtual QLabel& batteryCmu2Cell8Voltage() = 0;

    virtual QLabel& batteryCmu3Temp() = 0;
    virtual QLabel& batteryCmu3Cell1Voltage() = 0;
    virtual QLabel& batteryCmu3Cell2Voltage() = 0;
    virtual QLabel& batteryCmu3Cell3Voltage() = 0;
    virtual QLabel& batteryCmu3Cell4Voltage() = 0;
    virtual QLabel& batteryCmu3Cell5Voltage() = 0;
    virtual QLabel& batteryCmu3Cell6Voltage() = 0;
    virtual QLabel& batteryCmu3Cell7Voltage() = 0;
    virtual QLabel& batteryCmu3Cell8Voltage() = 0;

    virtual QLabel& batteryCmu4Temp() = 0;
    virtual QLabel& batteryCmu4Cell1Voltage() = 0;
    virtual QLabel& batteryCmu4Cell2Voltage() = 0;
    virtual QLabel& batteryCmu4Cell3Voltage() = 0;
    virtual QLabel& batteryCmu4Cell4Voltage() = 0;
    virtual QLabel& batteryCmu4Cell5Voltage() = 0;
    virtual QLabel& batteryCmu4Cell6Voltage() = 0;
    virtual QLabel& batteryCmu4Cell7Voltage() = 0;
    virtual QLabel& batteryCmu4Cell8Voltage() = 0;

    virtual QList<QLabel*>& batteryCmuCellVoltageLabels() = 0;

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

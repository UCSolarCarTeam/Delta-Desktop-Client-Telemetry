#pragma once

#include "qwt_plot.h"
#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QStackedWidget>
#include <QWidget>
#include <qwt_plot_curve.h>

class I_PowerUI
{
public:
	virtual ~I_PowerUI() {}

    virtual QPushButton& connectButton() = 0;
    virtual QLabel& setConnectionStatus() = 0;
    virtual QWidget& setConnectionHealth() = 0;
    virtual QLineEdit& getSerialPortName() = 0;
    virtual QLineEdit& getBaudRate() = 0;
    virtual QTextEdit& setDebugLog() = 0;

    virtual QLabel& setSetSpeed() = 0;
    virtual QLabel& setSetCurrent() = 0;
    virtual QLabel& setActualSpeed() = 0;    
    virtual QLabel& setBusCurrent() = 0;
    virtual QLabel& setBusVoltage() = 0;
    virtual QLabel& setBatteryCurrent() = 0;
    virtual QLabel& setBatteryVoltage() = 0;

    virtual QLabel& setBatteryCMU1Temp() = 0;
    virtual QLabel& setBatteryCMU1Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU2Temp() = 0;
    virtual QLabel& setBatteryCMU2Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU3Temp() = 0;
    virtual QLabel& setBatteryCMU3Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU4Temp() = 0;
    virtual QLabel& setBatteryCMU4Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell8Voltage() = 0;

    virtual QList<QLabel*>& batteryCMUCellVoltageLabels() = 0;

    virtual QPushButton& busGraphButton() = 0;
    virtual QPushButton& driverGraphButton() = 0;
    virtual QPushButton& batteryGraphButton() = 0;

    virtual QStackedWidget& setGraphsStackedWidget() = 0;
    virtual QwtPlotCurve& setPositiveBusCurrentCurve() = 0; 
    virtual QwtPlotCurve& setNegativeBusCurrentCurve() = 0; 
    virtual QwtPlotCurve& setBusVoltageCurve() = 0; 
    virtual QwtPlotCurve& setBusPowerCurve() = 0; 
    virtual QwtPlotCurve& setSetSpeedCurve() = 0; 
    virtual QwtPlotCurve& setActualSpeedCurve() = 0; 
    virtual QwtPlotCurve& setSetCurrentCurve() = 0;
    virtual QwtPlotCurve& setMod0CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod1CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod2CellTempCurve() = 0;
    virtual QwtPlotCurve& setMod3CellTempCurve() = 0;
    virtual QwtPlotCurve& setMaxCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setMinCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setAvgCellVoltageCurve() = 0;
    virtual QwtPlotCurve& setBatteryPowerCurve() = 0;
};

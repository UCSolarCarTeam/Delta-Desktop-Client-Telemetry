#pragma once

#include <QMainWindow>
#include "ViewLayer/I_SolarCarWindow/I_SolarCarWindow.h"
#include "I_PowerUI.h"
namespace Ui {
class PowerUI;
}

class PowerUI : public I_SolarCarWindow, public I_PowerUI
{
    Q_OBJECT
public:
    explicit PowerUI();
    ~PowerUI();

    void hideHeaderBar();

    QPushButton& connectButton();
    QComboBox& getConnectionType();
    QLabel& connectionStatus();
    QWidget& connectionHealth();
    QLineEdit& getUdpGroupAddress();
    QSpinBox& getUdpPortNumber();
    QWidget& getSerialParametersWidget();
    QLineEdit& getSerialPortName();
    QLineEdit& getBaudRate();

    QLabel& secondsSinceLastPacket();
    QLabel& packetInLastMinute();
    QLabel& secondsSinceLastValidPacket();
    QLabel& validPacketsInLastMinute();
    QLabel& invalidPacketsInLastMinute();


    QLabel& setSpeed();
    QLabel& setCurrent();
    QLabel& actualSpeed();
    QLabel& busCurrent();
    QLabel& busVoltage();
    QLabel& batteryCurrent();
    QLabel& batteryVoltage();

    QLabel& batteryCmu1Temp();
    QLabel& batteryCmu1Cell1Voltage();
    QLabel& batteryCmu1Cell2Voltage();
    QLabel& batteryCmu1Cell3Voltage();
    QLabel& batteryCmu1Cell4Voltage();
    QLabel& batteryCmu1Cell5Voltage();
    QLabel& batteryCmu1Cell6Voltage();
    QLabel& batteryCmu1Cell7Voltage();
    QLabel& batteryCmu1Cell8Voltage();

    QLabel& batteryCmu2Temp();
    QLabel& batteryCmu2Cell1Voltage();
    QLabel& batteryCmu2Cell2Voltage();
    QLabel& batteryCmu2Cell3Voltage();
    QLabel& batteryCmu2Cell4Voltage();
    QLabel& batteryCmu2Cell5Voltage();
    QLabel& batteryCmu2Cell6Voltage();
    QLabel& batteryCmu2Cell7Voltage();
    QLabel& batteryCmu2Cell8Voltage();

    QLabel& batteryCmu3Temp();
    QLabel& batteryCmu3Cell1Voltage();
    QLabel& batteryCmu3Cell2Voltage();
    QLabel& batteryCmu3Cell3Voltage();
    QLabel& batteryCmu3Cell4Voltage();
    QLabel& batteryCmu3Cell5Voltage();
    QLabel& batteryCmu3Cell6Voltage();
    QLabel& batteryCmu3Cell7Voltage();
    QLabel& batteryCmu3Cell8Voltage();

    QLabel& batteryCmu4Temp();
    QLabel& batteryCmu4Cell1Voltage();
    QLabel& batteryCmu4Cell2Voltage();
    QLabel& batteryCmu4Cell3Voltage();
    QLabel& batteryCmu4Cell4Voltage();
    QLabel& batteryCmu4Cell5Voltage();
    QLabel& batteryCmu4Cell6Voltage();
    QLabel& batteryCmu4Cell7Voltage();
    QLabel& batteryCmu4Cell8Voltage();
    QList<QLabel*>& batteryCmuCellVoltageLabels();

    QPushButton& busGraphButton();
    QPushButton& driverGraphButton();
    QPushButton& batteryGraphButton();


    QStackedWidget& graphsStackedWidget();
    QwtPlotCurve& positiveBusCurrentCurve();
    QwtPlotCurve& negativeBusCurrentCurve();
    QwtPlotCurve& busVoltageCurve();
    QwtPlotCurve& busPowerCurve();
    QwtPlotCurve& setSpeedCurve();
    QwtPlotCurve& actualSpeedCurve();
    QwtPlotCurve& setCurrentCurve();
    QwtPlotCurve& mod0CellTempCurve();
    QwtPlotCurve& mod1CellTempCurve();
    QwtPlotCurve& mod2CellTempCurve();
    QwtPlotCurve& mod3CellTempCurve();
    QwtPlotCurve& maxCellVoltageCurve();
    QwtPlotCurve& minCellVoltageCurve();
    QwtPlotCurve& avgCellVoltageCurve();
    QwtPlotCurve& batteryPowerCurve();
private:
    Ui::PowerUI *ui_;
    QList<QLabel*> batteryCmuCellVoltageLabels_;
    QwtPlotCurve* positiveBusCurrentCurve_;
    QwtPlotCurve* negativeBusCurrentCurve_;
    QwtPlotCurve* busVoltageCurve_;
    QwtPlotCurve* busPowerCurve_;
    QwtPlotCurve* actualSpeedCurve_;
    QwtPlotCurve* setSpeedCurve_;
    QwtPlotCurve* mod0CellTempCurve_;
    QwtPlotCurve* setCurrentCurve_;
    QwtPlotCurve* mod1CellTempCurve_;
    QwtPlotCurve* mod2CellTempCurve_;
    QwtPlotCurve* mod3CellTempCurve_;
    QwtPlotCurve* maxCellVoltageCurve_;
    QwtPlotCurve* minCellVoltageCurve_;
    QwtPlotCurve* avgCellVoltageCurve_;
    QwtPlotCurve* batteryPowerCurve_;

    void setupGraphs();
};

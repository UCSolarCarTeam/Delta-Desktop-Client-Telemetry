#pragma once

#include <QMainWindow>
#include "../I_SolarCarWindow/I_SolarCarWindow.h"
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

    QLabel& batteryCMU1Temp();
    QLabel& batteryCMU1Cell1Voltage();
    QLabel& batteryCMU1Cell2Voltage();
    QLabel& batteryCMU1Cell3Voltage();
    QLabel& batteryCMU1Cell4Voltage();
    QLabel& batteryCMU1Cell5Voltage();
    QLabel& batteryCMU1Cell6Voltage();
    QLabel& batteryCMU1Cell7Voltage();
    QLabel& batteryCMU1Cell8Voltage();

    QLabel& batteryCMU2Temp();
    QLabel& batteryCMU2Cell1Voltage();
    QLabel& batteryCMU2Cell2Voltage();
    QLabel& batteryCMU2Cell3Voltage();
    QLabel& batteryCMU2Cell4Voltage();
    QLabel& batteryCMU2Cell5Voltage();
    QLabel& batteryCMU2Cell6Voltage();
    QLabel& batteryCMU2Cell7Voltage();
    QLabel& batteryCMU2Cell8Voltage();

    QLabel& batteryCMU3Temp();
    QLabel& batteryCMU3Cell1Voltage();
    QLabel& batteryCMU3Cell2Voltage();
    QLabel& batteryCMU3Cell3Voltage();
    QLabel& batteryCMU3Cell4Voltage();
    QLabel& batteryCMU3Cell5Voltage();
    QLabel& batteryCMU3Cell6Voltage();
    QLabel& batteryCMU3Cell7Voltage();
    QLabel& batteryCMU3Cell8Voltage();

    QLabel& batteryCMU4Temp();
    QLabel& batteryCMU4Cell1Voltage();
    QLabel& batteryCMU4Cell2Voltage();
    QLabel& batteryCMU4Cell3Voltage();
    QLabel& batteryCMU4Cell4Voltage();
    QLabel& batteryCMU4Cell5Voltage();
    QLabel& batteryCMU4Cell6Voltage();
    QLabel& batteryCMU4Cell7Voltage();
    QLabel& batteryCMU4Cell8Voltage();
    QList<QLabel*>& batteryCMUCellVoltageLabels();

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
   QList<QLabel*> batteryCMUCellVoltageLabels_;
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

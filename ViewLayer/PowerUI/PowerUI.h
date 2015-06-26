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
    QLabel& setConnectionStatus();
    QWidget& setConnectionHealth();
    QLineEdit& getSerialPortName();
    QLineEdit& getBaudRate();
    QTextEdit& setDebugLog();

    QLabel& setSetSpeed();
    QLabel& setSetCurrent();
    QLabel& setActualSpeed();
    QLabel& setBusCurrent();
    QLabel& setBusVoltage();
    QLabel& setArrayCurrent();


    QLabel& setBatteryCMU1Temp();
    QLabel& setBatteryCMU1Cell1Voltage();
    QLabel& setBatteryCMU1Cell2Voltage();
    QLabel& setBatteryCMU1Cell3Voltage();
    QLabel& setBatteryCMU1Cell4Voltage();
    QLabel& setBatteryCMU1Cell5Voltage();
    QLabel& setBatteryCMU1Cell6Voltage();
    QLabel& setBatteryCMU1Cell7Voltage();
    QLabel& setBatteryCMU1Cell8Voltage();

    QLabel& setBatteryCMU2Temp();
    QLabel& setBatteryCMU2Cell1Voltage();
    QLabel& setBatteryCMU2Cell2Voltage();
    QLabel& setBatteryCMU2Cell3Voltage();
    QLabel& setBatteryCMU2Cell4Voltage();
    QLabel& setBatteryCMU2Cell5Voltage();
    QLabel& setBatteryCMU2Cell6Voltage();
    QLabel& setBatteryCMU2Cell7Voltage();
    QLabel& setBatteryCMU2Cell8Voltage();

    QLabel& setBatteryCMU3Temp();
    QLabel& setBatteryCMU3Cell1Voltage();
    QLabel& setBatteryCMU3Cell2Voltage();
    QLabel& setBatteryCMU3Cell3Voltage();
    QLabel& setBatteryCMU3Cell4Voltage();
    QLabel& setBatteryCMU3Cell5Voltage();
    QLabel& setBatteryCMU3Cell6Voltage();
    QLabel& setBatteryCMU3Cell7Voltage();
    QLabel& setBatteryCMU3Cell8Voltage();

    QLabel& setBatteryCMU4Temp();
    QLabel& setBatteryCMU4Cell1Voltage();
    QLabel& setBatteryCMU4Cell2Voltage();
    QLabel& setBatteryCMU4Cell3Voltage();
    QLabel& setBatteryCMU4Cell4Voltage();
    QLabel& setBatteryCMU4Cell5Voltage();
    QLabel& setBatteryCMU4Cell6Voltage();
    QLabel& setBatteryCMU4Cell7Voltage();
    QLabel& setBatteryCMU4Cell8Voltage();

    QPushButton& busGraphButton();
    QPushButton& driverGraphButton();
    QPushButton& batteryGraphButton();

    QStackedWidget& setGraphsStackedWidget();
    QwtPlotCurve& setBusCurrentCurve(); 
    QwtPlotCurve& setBusVoltageCurve(); 
    QwtPlotCurve& setBusPowerCurve(); 
    QwtPlotCurve& setSetSpeedCurve(); 
    QwtPlotCurve& setActualSpeedCurve(); 
    QwtPlotCurve& setSetCurrentCurve();
    QwtPlotCurve& setMaxCellTempCurve();
    QwtPlotCurve& setAvgCellTempCurve();
    QwtPlotCurve& setMinCellTempCurve();
    QwtPlotCurve& setMaxCellVoltageCurve();
    QwtPlotCurve& setMinCellVoltageCurve();
    QwtPlotCurve& setAvgCellVoltageCurve();
    
private:
   Ui::PowerUI *ui_;
   QwtPlotCurve* busCurrentCurve_;
   QwtPlotCurve* busVoltageCurve_;
   QwtPlotCurve* busPowerCurve_;
   QwtPlotCurve* setSpeedCurve_;
   QwtPlotCurve* actualSpeedCurve_;
   QwtPlotCurve* setCurrentCurve_;
   QwtPlotCurve* maxCellTempCurve_;
   QwtPlotCurve* avgCellTempCurve_;
   QwtPlotCurve* minCellTempCurve_;
   QwtPlotCurve* maxCellVoltageCurve_;
   QwtPlotCurve* minCellVoltageCurve_;
   QwtPlotCurve* avgCellVoltageCurve_;
   void setupGraphs();

};

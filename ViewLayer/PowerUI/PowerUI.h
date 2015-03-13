#pragma once

#include <QMainWindow>
#include "I_PowerUI.h"

namespace Ui {
	class PowerUI;
}

class PowerUI : public QMainWindow, public I_PowerUI
{
	Q_OBJECT
public:
	explicit PowerUI(QWidget *parent = 0);
	~PowerUI();

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

private:
   Ui::PowerUI *ui;
};
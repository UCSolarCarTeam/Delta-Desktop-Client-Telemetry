#pragma once

#include <QMainWindow>
#include "I_SolarCarTestUI.h"
namespace Ui {
class SolarCarTestUI;
}

class SolarCarTestUI : public QMainWindow, public I_SolarCarTestUI
{
   Q_OBJECT

public:
   explicit SolarCarTestUI(QWidget *parent = 0);
   ~SolarCarTestUI();

   QLCDNumber& setDriverSetSpeedRPM();
   QLCDNumber& setDriverSetCurrent();

   QLCDNumber& setVehicleVelocityKph();
   QLCDNumber& setBusCurrentA();
   QLCDNumber& setBusVoltage();

//     QLCDNumber& setMotorVelocityRpm();
//     QLCDNumber& setMotorVoltageReal();
//     QLCDNumber& setMotorCurrentReal();
//     QLCDNumber& setBackEmfImaginary();
//     QLCDNumber& setIpmHeatSinkTemp();
//     QLCDNumber& setDspBoardTemp();
//     QLCDNumber& setDcBusAmpHours();
//     QLCDNumber& setReceivedErrorCount();
//     QLCDNumber& setTransmittedErrorCount();

   QLCDNumber& setMod0PcbTemperature();
   //QLCDNumber& setMod0CellTemperature();
   QLCDNumber& setMod0CellVoltage0();
   QLCDNumber& setMod0CellVoltage1();
   QLCDNumber& setMod0CellVoltage2();
   QLCDNumber& setMod0CellVoltage3();
   QLCDNumber& setMod0CellVoltage4();
   QLCDNumber& setMod0CellVoltage5();
   QLCDNumber& setMod0CellVoltage6();
   QLCDNumber& setMod0CellVoltage7();

   QLCDNumber& setMod1PcbTemperature();
   //QLCDNumber& setMod1CellTemperature();
   QLCDNumber& setMod1CellVoltage0();
   QLCDNumber& setMod1CellVoltage1();
   QLCDNumber& setMod1CellVoltage2();
   QLCDNumber& setMod1CellVoltage3();
   QLCDNumber& setMod1CellVoltage4();
   QLCDNumber& setMod1CellVoltage5();
   QLCDNumber& setMod1CellVoltage6();
   QLCDNumber& setMod1CellVoltage7();

   QLCDNumber& setMod2PcbTemperature();
   //QLCDNumber& setMod2CellTemperature();
   QLCDNumber& setMod2CellVoltage0();
   QLCDNumber& setMod2CellVoltage1();
   QLCDNumber& setMod2CellVoltage2();
   QLCDNumber& setMod2CellVoltage3();
   QLCDNumber& setMod2CellVoltage4();
   QLCDNumber& setMod2CellVoltage5();
   QLCDNumber& setMod2CellVoltage6();
   QLCDNumber& setMod2CellVoltage7();

   QLCDNumber& setMod3PcbTemperature();
   //QLCDNumber& setMod3CellTemperature();
   QLCDNumber& setMod3CellVoltage0();
   QLCDNumber& setMod3CellVoltage1();
   QLCDNumber& setMod3CellVoltage2();
   QLCDNumber& setMod3CellVoltage3();
   QLCDNumber& setMod3CellVoltage4();
   QLCDNumber& setMod3CellVoltage5();
   QLCDNumber& setMod3CellVoltage6();
   QLCDNumber& setMod3CellVoltage7();

//     QLCDNumber& setBatteryVoltage();
//     QLCDNumber& setBatteryCurrent();
//     QLCDNumber& setBatteryVoltageThresholdRising();
//     QLCDNumber& setBatteryVoltageThresholdFalling();

   QLabel& setMainStatus();
   QTextEdit& setDebugLog();

   QPushButton& connectButton();
   QPushButton& disconnectButton();
   QLineEdit& getSerialPortName();
   QLineEdit& getBaudRate();

private:
   Ui::SolarCarTestUI *ui;
};


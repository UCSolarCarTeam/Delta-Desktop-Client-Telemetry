#pragma once

#include <QLCDNumber>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>

class I_SolarCarTestUI
{

public:
    virtual ~I_SolarCarTestUI() {}

    virtual QLCDNumber& setDriverSetSpeedRPM() = 0;
    virtual QLCDNumber& setDriverSetCurrent() = 0;

    virtual QLCDNumber& setVehicleVelocityKph() = 0;
    virtual QLCDNumber& setBusCurrentA() = 0;
    virtual QLCDNumber& setBusVoltage() = 0;
//    virtual QLCDNumber& setMotorVelocityRpm() = 0;
//    virtual QLCDNumber& setMotorVoltageReal() = 0;
//    virtual QLCDNumber& setMotorCurrentReal() = 0;
//    virtual QLCDNumber& setBackEmfImaginary() = 0;
//    virtual QLCDNumber& setIpmHeatSinkTemp() = 0;
//    virtual QLCDNumber& setDspBoardTemp() = 0;
//    virtual QLCDNumber& setDcBusAmpHours() = 0;
//    virtual QLCDNumber& setReceivedErrorCount() = 0;
//    virtual QLCDNumber& setTransmittedErrorCount() = 0;

    virtual QLCDNumber& setMod0PcbTemperature() = 0;
//    virtual QLCDNumber& setMod0CellTemperature() = 0;
    virtual QLCDNumber& setMod0CellVoltage0() = 0;
    virtual QLCDNumber& setMod0CellVoltage1() = 0;
    virtual QLCDNumber& setMod0CellVoltage2() = 0;
    virtual QLCDNumber& setMod0CellVoltage3() = 0;
    virtual QLCDNumber& setMod0CellVoltage4() = 0;
    virtual QLCDNumber& setMod0CellVoltage5() = 0;
    virtual QLCDNumber& setMod0CellVoltage6() = 0;
    virtual QLCDNumber& setMod0CellVoltage7() = 0;

    virtual QLCDNumber& setMod1PcbTemperature() = 0;
//    virtual QLCDNumber& setMod1CellTemperature() = 0;
    virtual QLCDNumber& setMod1CellVoltage0() = 0;
    virtual QLCDNumber& setMod1CellVoltage1() = 0;
    virtual QLCDNumber& setMod1CellVoltage2() = 0;
    virtual QLCDNumber& setMod1CellVoltage3() = 0;
    virtual QLCDNumber& setMod1CellVoltage4() = 0;
    virtual QLCDNumber& setMod1CellVoltage5() = 0;
    virtual QLCDNumber& setMod1CellVoltage6() = 0;
    virtual QLCDNumber& setMod1CellVoltage7() = 0;

    virtual QLCDNumber& setMod2PcbTemperature() = 0;
//    virtual QLCDNumber& setMod2CellTemperature() = 0;
    virtual QLCDNumber& setMod2CellVoltage0() = 0;
    virtual QLCDNumber& setMod2CellVoltage1() = 0;
    virtual QLCDNumber& setMod2CellVoltage2() = 0;
    virtual QLCDNumber& setMod2CellVoltage3() = 0;
    virtual QLCDNumber& setMod2CellVoltage4() = 0;
    virtual QLCDNumber& setMod2CellVoltage5() = 0;
    virtual QLCDNumber& setMod2CellVoltage6() = 0;
    virtual QLCDNumber& setMod2CellVoltage7() = 0;

    virtual QLCDNumber& setMod3PcbTemperature() = 0;
//    virtual QLCDNumber& setMod3CellTemperature() = 0;
    virtual QLCDNumber& setMod3CellVoltage0() = 0;
    virtual QLCDNumber& setMod3CellVoltage1() = 0;
    virtual QLCDNumber& setMod3CellVoltage2() = 0;
    virtual QLCDNumber& setMod3CellVoltage3() = 0;
    virtual QLCDNumber& setMod3CellVoltage4() = 0;
    virtual QLCDNumber& setMod3CellVoltage5() = 0;
    virtual QLCDNumber& setMod3CellVoltage6() = 0;
    virtual QLCDNumber& setMod3CellVoltage7() = 0;

//    virtual QLCDNumber& setBatteryVoltage() = 0;
//    virtual QLCDNumber& setBatteryCurrent() = 0;
//    virtual QLCDNumber& setBatteryVoltageThresholdRising() = 0;
//    virtual QLCDNumber& setBatteryVoltageThresholdFalling() = 0;

    virtual QLabel& setMainStatus() = 0;
    virtual QTextEdit& setDebugLog() = 0;

    virtual QPushButton& connectButton() = 0;
    virtual QPushButton& disconnectButton() = 0;
    virtual QLineEdit& getSerialPortName() = 0;
    virtual QLineEdit& getBaudRate() = 0;
};

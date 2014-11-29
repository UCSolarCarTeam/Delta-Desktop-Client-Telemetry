#pragma once
#include <QObject>

class I_DataParser;
class I_TelemetryData;

class DataPopulator : public QObject
{
  Q_OBJECT



public:
  DataPopulator(const I_DataParser& dataParser, I_TelemetryData& data);

  enum Ids
  {
     DriverSetSpeedRPM       =  0,
     DriverSetCurrent        =  1,
     VehicleVelocity         =  2,
     BusCurrentA             =  3,
     BusVoltage              =  4,
     MotorVelocityRpm        =  5,
     MotorVoltageReal        =  6,
     MotorCurrentReal        =  7,
     BackEmfImaginary        =  8,
     IpmHeatSinkTemp         =  9,
     DspBoardTemp            =  10,
     DcBusAmpHours           =  11,
     ReceivedErrorCount      =  12,
     TransmittedErrorCount   =  13,

     Mod0PcbTemperature      =  14,
     Mod0CellTemperature     =  15,
     Mod0CellVoltage0        =  16,
     Mod0CellVoltage1        =  17,
     Mod0CellVoltage2        =  18,
     Mod0CellVoltage3        =  19,
     Mod0CellVoltage4        =  20,
     Mod0CellVoltage5        =  21,
     Mod0CellVoltage6        =  22,
     Mod0CellVoltage7        =  23,

     Mod1PcbTemperature      =  24,
     Mod1CellTemperature     =  25,
     Mod1CellVoltage0        =  26,
     Mod1CellVoltage1        =  27,
     Mod1CellVoltage2        =  28,
     Mod1CellVoltage3        =  29,
     Mod1CellVoltage4        =  30,
     Mod1CellVoltage5        =  31,
     Mod1CellVoltage6        =  32,
     Mod1CellVoltage7        =  33,

     Mod2PcbTemperature      =  34,
     Mod2CellTemperature     =  35,
     Mod2CellVoltage0        =  36,
     Mod2CellVoltage1        =  37,
     Mod2CellVoltage2        =  38,
     Mod2CellVoltage3        =  39,
     Mod2CellVoltage4        =  40,
     Mod2CellVoltage5        =  41,
     Mod2CellVoltage6        =  42,
     Mod2CellVoltage7        =  43,

     Mod3PcbTemperature      =  44,
     Mod3CellTemperature     =  45,
     Mod3CellVoltage0        =  46,
     Mod3CellVoltage1        =  47,
     Mod3CellVoltage2        =  48,
     Mod3CellVoltage3        =  49,
     Mod3CellVoltage4        =  50,
     Mod3CellVoltage5        =  51,
     Mod3CellVoltage6        =  52,
     Mod3CellVoltage7        =  53,

     BatteryVoltage                   =  54,
     BatteryCurrent                   =  55,
     BatteryVoltageThresholdRising    =  56,
     BatteryVoltageThresholdFalling   =  57,
  };

private slots:
  void handleDataReceived(int id, double value);

private:
  const I_DataParser& dataParser_;
  I_TelemetryData& data_;
};

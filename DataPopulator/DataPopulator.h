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
   DriverSetSpeedRPM       =  1,
   DriverSetCurrent        =  2,
   VehicleVelocity         =  3,
   BusCurrentA             =  4,
   BusVoltage              =  5,
   MotorVelocityRpm        =  6,
   MotorVoltageReal        =  7,
   MotorCurrentReal        =  8,
   BackEmfImaginary        =  9,
   IpmHeatSinkTemp         =  10,
   DspBoardTemp            =  11,
   DcBusAmpHours           =  12,
   ReceivedErrorCount      =  13,
   TransmittedErrorCount   =  14,

   Mod0PcbTemperature      =  15,
   Mod0CellTemperature     =  16,
   Mod0CellVoltage0        =  17,
   Mod0CellVoltage1        =  18,
   Mod0CellVoltage2        =  19,
   Mod0CellVoltage3        =  20,
   Mod0CellVoltage4        =  21,
   Mod0CellVoltage5        =  22,
   Mod0CellVoltage6        =  23,
   Mod0CellVoltage7        =  24,

   Mod1PcbTemperature      =  25,
   Mod1CellTemperature     =  26,
   Mod1CellVoltage0        =  27,
   Mod1CellVoltage1        =  28,
   Mod1CellVoltage2        =  29,
   Mod1CellVoltage3        =  30,
   Mod1CellVoltage4        =  31,
   Mod1CellVoltage5        =  32,
   Mod1CellVoltage6        =  33,
   Mod1CellVoltage7        =  34,

   Mod2PcbTemperature      =  35,
   Mod2CellTemperature     =  36,
   Mod2CellVoltage0        =  37,
   Mod2CellVoltage1        =  38,
   Mod2CellVoltage2        =  39,
   Mod2CellVoltage3        =  40,
   Mod2CellVoltage4        =  41,
   Mod2CellVoltage5        =  42,
   Mod2CellVoltage6        =  43,
   Mod2CellVoltage7        =  44,

   Mod3PcbTemperature      =  45,
   Mod3CellTemperature     =  46,
   Mod3CellVoltage0        =  47,
   Mod3CellVoltage1        =  48,
   Mod3CellVoltage2        =  49,
   Mod3CellVoltage3        =  50,
   Mod3CellVoltage4        =  51,
   Mod3CellVoltage5        =  52,
   Mod3CellVoltage6        =  53,
   Mod3CellVoltage7        =  54,

   BatteryVoltage                   =  55,
   BatteryCurrent                   =  56,
   BatteryVoltageThresholdRising    =  57,
   BatteryVoltageThresholdFalling   =  58,
  };

private slots:
  void handleDataReceived(int id, int value);

private:
  const I_DataParser& dataParser_;
  I_TelemetryData& data_;
};

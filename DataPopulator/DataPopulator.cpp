#include "DataPopulator.h"
#include "TelemetryData/I_TelemetryData.h"
#include "DataParser/I_DataParser.h"

namespace
{
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
}

DataPopulator::DataPopulator(const I_DataParser& dataParser, I_TelemetryData& data)
: dataParser_(dataParser)
, data_(data)
{
   connect(&dataParser, SIGNAL(dataReceived(int, int)), this, SLOT(handleDataReceived(int, int)));
}

//id will start with 1 instead of 0.
void DataPopulator::handleDataReceived(int id, int value)
{
   switch(id)
   {
      case DriverSetSpeedRPM:
      data_.setDriverSetSpeedRPM(value);
      break;
      case DriverSetCurrent:
      data_.setDriverSetCurrent(value);
      break;
      case VehicleVelocity:
      data_.setVehicleVelocityKph(value);
      break;
      case BusCurrentA:
      data_.setBusCurrentA(value);
      break;
      case BusVoltage:
      data_.setBusVoltage(value);
      break;
      case MotorVelocityRpm:
      data_.setMotorVelocityRpm(value);
      break;
      case MotorVoltageReal:
      data_.setMotorVoltageReal(value);
      break;
      case MotorCurrentReal:
      data_.setMotorCurrentReal(value);
      break;
      case BackEmfImaginary:
      data_.setBackEmfImaginary(value);
      break;
      case IpmHeatSinkTemp:
      data_.setIpmHeatSinkTemp(value);
      break;
      case DspBoardTemp:
      data_.setDspBoardTemp(value);
      break;
      case DcBusAmpHours:
      data_.setDcBusAmpHours(value);
      break;
      case ReceivedErrorCount:
      data_.setReceivedErrorCount(value);
      break;
      case TransmittedErrorCount:
      data_.setTransmittedErrorCount(value);
      break;

      case Mod0PcbTemperature:
      data_.setMod0PcbTemperature(value);
      break;
      case Mod0CellTemperature:
      data_.setMod0CellTemperature(value);
      break;
      case Mod0CellVoltage0:
      data_.setMod0CellVoltage0(value);
      break;
      case Mod0CellVoltage1:
      data_.setMod0CellVoltage1(value);
      break;
      case Mod0CellVoltage2:
      data_.setMod0CellVoltage2(value);
      break;
      case Mod0CellVoltage3:
      data_.setMod0CellVoltage3(value);
      break;
      case Mod0CellVoltage4:
      data_.setMod0CellVoltage4(value);
      break;
      case Mod0CellVoltage5:
      data_.setMod0CellVoltage5(value);
      break;
      case Mod0CellVoltage6:
      data_.setMod0CellVoltage6(value);
      break;
      case Mod0CellVoltage7:
      data_.setMod0CellVoltage7(value);
      break;

      case Mod1PcbTemperature:
      data_.setMod1PcbTemperature(value);
      break;
      case Mod1CellTemperature:
      data_.setMod1CellTemperature(value);
      break;
      case Mod1CellVoltage0:
      data_.setMod1CellVoltage0(value);
      break;
      case Mod1CellVoltage1:
      data_.setMod1CellVoltage1(value);
      break;
      case Mod1CellVoltage2:
      data_.setMod1CellVoltage2(value);
      break;
      case Mod1CellVoltage3:
      data_.setMod1CellVoltage3(value);
      break;
      case Mod1CellVoltage4:
      data_.setMod1CellVoltage4(value);
      break;
      case Mod1CellVoltage5:
      data_.setMod1CellVoltage5(value);
      break;
      case Mod1CellVoltage6:
      data_.setMod1CellVoltage6(value);
      break;
      case Mod1CellVoltage7:
      data_.setMod1CellVoltage7(value);
      break;

      case Mod2PcbTemperature:
      data_.setMod2PcbTemperature(value);
      break;
      case Mod2CellTemperature:
      data_.setMod2CellTemperature(value);
      break;
      case Mod2CellVoltage0:
      data_.setMod2CellVoltage0(value);
      break;
      case Mod2CellVoltage1:
      data_.setMod2CellVoltage1(value);
      break;
      case Mod2CellVoltage2:
      data_.setMod2CellVoltage2(value);
      break;
      case Mod2CellVoltage3:
      data_.setMod2CellVoltage3(value);
      break;
      case Mod2CellVoltage4:
      data_.setMod2CellVoltage4(value);
      break;
      case Mod2CellVoltage5:
      data_.setMod2CellVoltage5(value);
      break;
      case Mod2CellVoltage6:
      data_.setMod2CellVoltage6(value);
      break;
      case Mod2CellVoltage7:
      data_.setMod2CellVoltage7(value);
      break;

      case Mod3PcbTemperature:
      data_.setMod3PcbTemperature(value);
      break;
      case Mod3CellTemperature:
      data_.setMod3CellTemperature(value);
      break;
      case Mod3CellVoltage0:
      data_.setMod3CellVoltage0(value);
      break;
      case Mod3CellVoltage1:
      data_.setMod3CellVoltage1(value);
      break;
      case Mod3CellVoltage2:
      data_.setMod3CellVoltage2(value);
      break;
      case Mod3CellVoltage3:
      data_.setMod3CellVoltage3(value);
      break;
      case Mod3CellVoltage4:
      data_.setMod3CellVoltage4(value);
      break;
      case Mod3CellVoltage5:
      data_.setMod3CellVoltage5(value);
      break;
      case Mod3CellVoltage6:
      data_.setMod3CellVoltage6(value);
      break;
      case Mod3CellVoltage7:
      data_.setMod3CellVoltage7(value);
      break;

      case BatteryVoltage:
      data_.setBatteryVoltage(value);
      break;
      case BatteryCurrent:
      data_.setBatteryCurrent(value);
      break;
      case BatteryVoltageThresholdRising:
      data_.setBatteryVoltageThresholdRising(value);
      break;
      case BatteryVoltageThresholdFalling:
      data_.setBatteryVoltageThresholdFalling(value);
      break;


   }

}

#include "../DataParser/I_DataParser.h"
#include "../ArrayData/I_ArrayData.h"
#include "../PowerData/I_PowerData.h"
#include "../VehicleData/I_VehicleData.h"
#include "../BatteryData/I_BatteryData.h"
#include "DataPopulator.h"
#include <stdio.h>


DataPopulator::DataPopulator(const I_DataParser& dataParser, 
                             I_ArrayData& arrayData,
                             I_PowerData& powerData,
                             I_VehicleData& vehicleData,
                             I_BatteryData& batteryData)
: dataParser_(dataParser)
, arrayData_(arrayData)
, powerData_(powerData)
, vehicleData_(vehicleData)
, batteryData_(batteryData)
{
   connect(&dataParser, SIGNAL(dataReceived(int, double)), this, SLOT(handleDataReceived(int, double)));
}

void DataPopulator::handleDataReceived(int id, double value)
{
   switch(id)
   {
   /* ARRAY DATA */

   /* POWER DATA */
    case BusCurrentA:
        powerData_.setBusCurrentA(value);
        break;
    case BusVoltage:
        powerData_.setBusVoltage(value);
        break;
    case MotorVoltageReal:
        powerData_.setMotorVoltageReal(value);
        break;
    case MotorCurrentReal:
        powerData_.setMotorCurrentReal(value);
        break;
    case BackEmfImaginary:
        powerData_.setBackEmfImaginary(value);
        break;
    case DcBusAmpHours:
        powerData_.setDcBusAmpHours(value);
        break;

    /* VEHICLE DATA */
    case DriverSetSpeedRPM:
        vehicleData_.setDriverSetSpeedRPM(value);
        break;
    case DriverSetCurrent:
        vehicleData_.setDriverSetCurrent(value);
        break;
    case VehicleVelocity:
        vehicleData_.setVehicleVelocityKph(value);
        break;
    case MotorVelocityRpm:
        vehicleData_.setMotorVelocityRpm(value);
        break;
    case IpmHeatSinkTemp:
        vehicleData_.setIpmHeatSinkTemp(value);
        break;
    case ReceivedErrorCount:
        vehicleData_.setReceivedErrorCount(value);
        break;
    case TransmittedErrorCount:
        vehicleData_.setTransmittedErrorCount(value);
        break;

    /* BATTERY DATA */
    case Mod0PcbTemperature:
        batteryData_.setMod0PcbTemperature(value);
        break;
    case Mod0CellTemperature:
        batteryData_.setMod0CellTemperature(value);
        break;
    case Mod0CellVoltage0:
        batteryData_.setMod0CellVoltage0(value);
        break;
    case Mod0CellVoltage1:
        batteryData_.setMod0CellVoltage1(value);
        break;
    case Mod0CellVoltage2:
        batteryData_.setMod0CellVoltage2(value);
        break;
    case Mod0CellVoltage3:
        batteryData_.setMod0CellVoltage3(value);
        break;
    case Mod0CellVoltage4:
        batteryData_.setMod0CellVoltage4(value);
        break;
    case Mod0CellVoltage5:
        batteryData_.setMod0CellVoltage5(value);
        break;
    case Mod0CellVoltage6:
        batteryData_.setMod0CellVoltage6(value);
        break;
    case Mod0CellVoltage7:
        batteryData_.setMod0CellVoltage7(value);
        break;
    case Mod1PcbTemperature:
        batteryData_.setMod1PcbTemperature(value);
        break;
    case Mod1CellTemperature:
        batteryData_.setMod1CellTemperature(value);
        break;
    case Mod1CellVoltage0:
        batteryData_.setMod1CellVoltage0(value);
        break;
    case Mod1CellVoltage1:
        batteryData_.setMod1CellVoltage1(value);
        break;
    case Mod1CellVoltage2:
        batteryData_.setMod1CellVoltage2(value);
        break;
    case Mod1CellVoltage3:
        batteryData_.setMod1CellVoltage3(value);
        break;
    case Mod1CellVoltage4:
        batteryData_.setMod1CellVoltage4(value);
        break;
    case Mod1CellVoltage5:
        batteryData_.setMod1CellVoltage5(value);
        break;
    case Mod1CellVoltage6:
        batteryData_.setMod1CellVoltage6(value);
        break;
    case Mod1CellVoltage7:
        batteryData_.setMod1CellVoltage7(value);
        break;
    case Mod2PcbTemperature:
        batteryData_.setMod2PcbTemperature(value);
        break;
    case Mod2CellTemperature:
        batteryData_.setMod2CellTemperature(value);
        break;
    case Mod2CellVoltage0:
        batteryData_.setMod2CellVoltage0(value);
        break;
    case Mod2CellVoltage1:
        batteryData_.setMod2CellVoltage1(value);
        break;
    case Mod2CellVoltage2:
        batteryData_.setMod2CellVoltage2(value);
        break;
    case Mod2CellVoltage3:
        batteryData_.setMod2CellVoltage3(value);
        break;
    case Mod2CellVoltage4:
        batteryData_.setMod2CellVoltage4(value);
        break;
    case Mod2CellVoltage5:
        batteryData_.setMod2CellVoltage5(value);
        break;
    case Mod2CellVoltage6:
        batteryData_.setMod2CellVoltage6(value);
        break;
    case Mod2CellVoltage7:
        batteryData_.setMod2CellVoltage7(value);
        break;
    case Mod3PcbTemperature:
        batteryData_.setMod3PcbTemperature(value);
        break;
    case Mod3CellTemperature:
        batteryData_.setMod3CellTemperature(value);
        break;
    case Mod3CellVoltage0:
        batteryData_.setMod3CellVoltage0(value);
        break;
    case Mod3CellVoltage1:
        batteryData_.setMod3CellVoltage1(value);
        break;
    case Mod3CellVoltage2:
        batteryData_.setMod3CellVoltage2(value);
        break;
    case Mod3CellVoltage3:
        batteryData_.setMod3CellVoltage3(value);
        break;
    case Mod3CellVoltage4:
        batteryData_.setMod3CellVoltage4(value);
        break;
    case Mod3CellVoltage5:
        batteryData_.setMod3CellVoltage5(value);
        break;
    case Mod3CellVoltage6:
        batteryData_.setMod3CellVoltage6(value);
        break;
    case Mod3CellVoltage7:
        batteryData_.setMod3CellVoltage7(value);
        break;
    case BatteryVoltage:
        batteryData_.setBatteryVoltage(value);
        break;
    case BatteryCurrent:
        batteryData_.setBatteryCurrent(value);
        break;
    case BatteryVoltageThresholdRising:
        batteryData_.setBatteryVoltageThresholdRising(value);
        break;
    case BatteryVoltageThresholdFalling:
        batteryData_.setBatteryVoltageThresholdFalling(value);
        break;
   }
}

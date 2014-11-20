#include "DebugHandler.h"
#include "../ConnectionService/I_ConnectionService.h"
#include "../DataParser/I_DataParser.h"
#include "../DataPopulator/DataPopulator.h"

DebugHandler::DebugHandler(I_ConnectionService& connectionService, I_DataParser& dataParser)
: connectionService_(connectionService)
, dataParser_(dataParser)
{
   connect(&connectionService, SIGNAL(sendDebugMessage(QString)),
           this, SLOT (receivedConnectionService(QString)));

   connect(&dataParser, SIGNAL(sendDebugMessage(QString)),
           this, SLOT (receivedDebugDataParser(QString)));

   connect(&dataParser, SIGNAL(dataReceived(int,int)),
           this, SLOT (receivedDataParser(int, int)));
}

DebugHandler::~DebugHandler()
{

}

/** public functions **/
void DebugHandler::receivedConnectionService(QString debugMessage)
{
   emit sendDebugMessageToPresenter(debugMessage);
}

//gets the original RAW string that dataparse receieves (this will just be sent to the debugLogFile)
void DebugHandler::receivedDebugDataParser(QString debugMessage)
{

}

//gets the parsed values that dataparser emits and translates it to a human readable format
//and sends it to the debugLogFile
void DebugHandler::receivedParsedDataParser(int id, int value)
{

}


/** private **/
void DebugHandler::writeToDebugLogFile(QString debugMessage)
{


}

QString DebugHandler::convertIDtoString(int id)
{
   QString convertedID("");//Optional String appending Converted ID.

   switch(id)
   {
   case DataPopulator::DriverSetSpeedRPM:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::DriverSetCurrent:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::VehicleVelocity:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::BusCurrentA:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::BusVoltage:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::MotorVelocityRpm:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::MotorVoltageReal:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::MotorCurrentReal:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::BackEmfImaginary:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::IpmHeatSinkTemp:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::DspBoardTemp:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::DcBusAmpHours:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::ReceivedErrorCount:
      convertedID.append("DriverSetSpeedRPM");
      break;
   case DataPopulator::TransmittedErrorCount:
      convertedID.append("DriverSetSpeedRPM");
      break;

   case DataPopulator::Mod0PcbTemperature:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellTemperature:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage0:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage1:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage2:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage3:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage4:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage5:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage6:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod0CellVoltage7:
      convertedID.append("Mod0PcbTemperature");
      break;

   case DataPopulator::Mod1PcbTemperature:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellTemperature:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage0:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage1:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage2:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage3:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage4:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage5:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage6:
      convertedID.append("Mod0PcbTemperature");
      break;
   case DataPopulator::Mod1CellVoltage7:
      convertedID.append("Mod0PcbTemperature");
      break;

   case DataPopulator::Mod2PcbTemperature:
      break;
   case DataPopulator::Mod2CellTemperature:
      break;
   case DataPopulator::Mod2CellVoltage0:
      break;
   case DataPopulator::Mod2CellVoltage1:
      break;
   case DataPopulator::Mod2CellVoltage2:
      break;
   case DataPopulator::Mod2CellVoltage3:
      break;
   case DataPopulator::Mod2CellVoltage4:
      break;
   case DataPopulator::Mod2CellVoltage5:
      break;
   case DataPopulator::Mod2CellVoltage6:
      break;
   case DataPopulator::Mod2CellVoltage7:
      break;

   case DataPopulator::Mod3PcbTemperature:
      break;
   case DataPopulator::Mod3CellTemperature:
      break;
   case DataPopulator::Mod3CellVoltage0:
      break;
   case DataPopulator::Mod3CellVoltage1:
      break;
   case DataPopulator::Mod3CellVoltage2:
      break;
   case DataPopulator::Mod3CellVoltage3:
      break;
   case DataPopulator::Mod3CellVoltage4:
      break;
   case DataPopulator::Mod3CellVoltage5:
      break;
   case DataPopulator::Mod3CellVoltage6:
      break;
   case DataPopulator::Mod3CellVoltage7:
      break;

   case DataPopulator::BatteryVoltage:
      break;
   case DataPopulator::BatteryCurrent:
      break;
   case DataPopulator::BatteryVoltageThresholdRising:
      break;
   case DataPopulator::BatteryVoltageThresholdFalling:
      break;


   }

return convertedID;
}

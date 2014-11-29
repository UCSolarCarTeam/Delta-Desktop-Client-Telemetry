#include "DebugHandler.h"
#include "../ConnectionService/I_ConnectionService.h"
#include "../DataParser/I_DataParser.h"
#include "../DataPopulator/DataPopulator.h"




DebugHandler::DebugHandler(I_ConnectionService& connectionService, I_DataParser& dataParser, QString filename)
: connectionService_(connectionService)
, dataParser_(dataParser)
, logTxtFile_(filename)
, logCsvFile_(filename)
{
    /********************Connections********************/
    connect(&connectionService, SIGNAL(sendDebugMessage(QString)),
            this, SLOT (receivedConnectionService(QString)));
    //RAW String
    connect(&dataParser, SIGNAL(sendDebugMessage(QString)),
            this, SLOT (receivedDebugDataParser(QString)));
    //PARSED values
    connect(&dataParser, SIGNAL(dataReceived(int,int)),
            this, SLOT (receivedParsedDataParser(int, int)));

    /********************File Initializing********************/
    QDateTime date = QDateTime::currentDateTime();
    QString DebugFilePath("../gen-4.5-telemetry-c/DebugHandler/DebugLogs/"); //can only create ONE NEW folder.
    if(!QDir(DebugFilePath).exists())
        QDir().mkdir(DebugFilePath);


    filename.prepend(date.toString("yyyy.MM.dd_hh.mm.ss")); //following Canadian Standard 'ISO 8601'
    filename.prepend(DebugFilePath);

    /*Log Csv File*/
    logCsvFile_.setFileName(filename + ".csv");
    if(logCsvFile_.open(QIODevice::WriteOnly | QIODevice::Text))
    {

    }


    /*Log Text File*/
    logTxtFile_.setFileName(filename + ".txt");
    if(logTxtFile_.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writer(&logTxtFile_);
        writer << "|======================";
        writer << date.toString("ddd MMM d yyyy");
        writer << "======================|" << endl;
        writer <<  "                     SOLARCAR  DEBUG  LOG" << endl;
        writer << "|===========================================================|" << endl;
    }
}

DebugHandler::~DebugHandler()
{
    logTxtFile_.close();
    logCsvFile_.close();
}

/** public functions **/
void DebugHandler::receivedConnectionService(QString debugMessage)
{
   emit sendDebugMessageToPresenter(debugMessage);
}

//gets the original RAW string that dataparse receieves (this will just be sent to the debuglogTxtFile)
void DebugHandler::receivedDebugDataParser(QString debugMessage)
{
    QString messageToFile("             | RAW-STRING   : "); //Optional String prepending Message
    messageToFile.append(debugMessage);

    printlnToDebuglogTxtFile(messageToFile);
}

//gets the parsed values that dataparser emits and translates it to a human readable format
//and sends it to the debuglogTxtFile
void DebugHandler::receivedParsedDataParser(int id, int value)
{
    QDateTime date = QDateTime::currentDateTime();

    QString messageToFile(" | PARSED-STRING: "); //Optional String prepending Message.

    messageToFile.prepend(date.toString("hh:mm:ss:zzz"));

    messageToFile.append(convertIDtoString(id));
    messageToFile.append(QString::number(value)); //May need to change this if we don't want raw 'value' going in.

    printlnToDebuglogTxtFile(messageToFile);
}


/** private **/
void DebugHandler::printlnToDebuglogTxtFile(QString debugMessage)
{
    QTextStream writer(&logTxtFile_);
    writer << debugMessage << endl;
}

void DebugHandler::printlnToDebuglogCsvFile(QString debugMessage)
{
    QTextStream writer(&logCsvFile_);
    writer << debugMessage << endl;

}

QString DebugHandler::convertIDtoString(int id)
{
   QString convertedID("");//Optional String prepending Converted ID.

   switch(id)
   {
   case DataPopulator::DriverSetSpeedRPM:
      convertedID.append("DriverSetSpeedRPM:");
      break;
   case DataPopulator::DriverSetCurrent:
      convertedID.append("DriverSetCurrent:");
      break;
   case DataPopulator::VehicleVelocity:
      convertedID.append("VehicleVelocity:");
      break;
   case DataPopulator::BusCurrentA:
      convertedID.append("BusCurrentA:");
      break;
   case DataPopulator::BusVoltage:
      convertedID.append("BusVoltage:");
      break;
   case DataPopulator::MotorVelocityRpm:
      convertedID.append("MotorVelocityRpm:");
      break;
   case DataPopulator::MotorVoltageReal:
      convertedID.append("MotorVoltageReal:");
      break;
   case DataPopulator::MotorCurrentReal:
      convertedID.append("MotorCurrentReal:");
      break;
   case DataPopulator::BackEmfImaginary:
      convertedID.append("BackEmfImaginary:");
      break;
   case DataPopulator::IpmHeatSinkTemp:
      convertedID.append("IpmHeatSinkTemp:");
      break;
   case DataPopulator::DspBoardTemp:
      convertedID.append("DspBoardTemp:");
      break;
   case DataPopulator::DcBusAmpHours:
      convertedID.append("DcBusAmpHours:");
      break;
   case DataPopulator::ReceivedErrorCount:
      convertedID.append("ReceivedErrorCount:");
      break;
   case DataPopulator::TransmittedErrorCount:
      convertedID.append("TransmittedErrorCount:");
      break;

   case DataPopulator::Mod0PcbTemperature:
      convertedID.append("Mod0PcbTemperature:");
      break;
   case DataPopulator::Mod0CellTemperature:
      convertedID.append("Mod0CellTemperature:");
      break;
   case DataPopulator::Mod0CellVoltage0:
      convertedID.append("Mod0CellVoltage0:");
      break;
   case DataPopulator::Mod0CellVoltage1:
      convertedID.append("Mod0CellVoltage1:");
      break;
   case DataPopulator::Mod0CellVoltage2:
      convertedID.append("Mod0CellVoltage2:");
      break;
   case DataPopulator::Mod0CellVoltage3:
      convertedID.append("Mod0PcbTemperature:");
      break;
   case DataPopulator::Mod0CellVoltage4:
      convertedID.append("Mod0CellVoltage4:");
      break;
   case DataPopulator::Mod0CellVoltage5:
      convertedID.append("Mod0CellVoltage5:");
      break;
   case DataPopulator::Mod0CellVoltage6:
      convertedID.append("Mod0CellVoltage6:");
      break;
   case DataPopulator::Mod0CellVoltage7:
      convertedID.append("Mod0CellVoltage7:");
      break;

   case DataPopulator::Mod1PcbTemperature:
      convertedID.append("Mod1PcbTemperature:");
      break;
   case DataPopulator::Mod1CellTemperature:
      convertedID.append("Mod1CellTemperature:");
      break;
   case DataPopulator::Mod1CellVoltage0:
      convertedID.append("Mod1CellVoltage0:");
      break;
   case DataPopulator::Mod1CellVoltage1:
      convertedID.append("Mod1CellVoltage1:");
      break;
   case DataPopulator::Mod1CellVoltage2:
      convertedID.append("Mod1CellVoltage2:");
      break;
   case DataPopulator::Mod1CellVoltage3:
      convertedID.append("Mod1CellVoltage3:");
      break;
   case DataPopulator::Mod1CellVoltage4:
      convertedID.append("Mod1CellVoltage4:");
      break;
   case DataPopulator::Mod1CellVoltage5:
      convertedID.append("Mod1CellVoltage5:");
      break;
   case DataPopulator::Mod1CellVoltage6:
      convertedID.append("Mod1CellVoltage6:");
      break;
   case DataPopulator::Mod1CellVoltage7:
      convertedID.append("Mod1CellVoltage7:");
      break;

   case DataPopulator::Mod2PcbTemperature:
       convertedID.append("Mod2PcbTemperature:");
       break;
   case DataPopulator::Mod2CellTemperature:
        convertedID.append("Mod2CellTemperature:");
      break;
   case DataPopulator::Mod2CellVoltage0:
        convertedID.append("Mod2CellVoltage0:");
      break;
   case DataPopulator::Mod2CellVoltage1:
        convertedID.append("Mod2CellVoltage1:");
      break;
   case DataPopulator::Mod2CellVoltage2:
        convertedID.append("Mod2CellVoltage2:");
      break;
   case DataPopulator::Mod2CellVoltage3:
        convertedID.append("Mod2CellVoltage3:");
      break;
   case DataPopulator::Mod2CellVoltage4:
        convertedID.append("Mod2CellVoltage4:");
      break;
   case DataPopulator::Mod2CellVoltage5:
        convertedID.append("Mod2CellVoltage5:");
      break;
   case DataPopulator::Mod2CellVoltage6:
        convertedID.append("Mod2CellVoltage6:");
      break;
   case DataPopulator::Mod2CellVoltage7:
        convertedID.append("Mod2CellVoltage7:");
      break;

   case DataPopulator::Mod3PcbTemperature:
        convertedID.append("Mod3PcbTemperature:");
      break;
   case DataPopulator::Mod3CellTemperature:
        convertedID.append("Mod3CellTemperature:");
      break;
   case DataPopulator::Mod3CellVoltage0:
        convertedID.append("Mod3CellVoltage0:");
      break;
   case DataPopulator::Mod3CellVoltage1:
        convertedID.append("Mod3CellVoltage1:");
      break;
   case DataPopulator::Mod3CellVoltage2:
        convertedID.append("Mod3CellVoltage2:");
      break;
   case DataPopulator::Mod3CellVoltage3:
        convertedID.append("Mod3CellVoltage3:");
      break;
   case DataPopulator::Mod3CellVoltage4:
        convertedID.append("Mod3CellVoltage4:");
      break;
   case DataPopulator::Mod3CellVoltage5:
        convertedID.append("Mod3CellVoltage5:");
      break;
   case DataPopulator::Mod3CellVoltage6:
        convertedID.append("Mod3CellVoltage6:");
      break;
   case DataPopulator::Mod3CellVoltage7:
        convertedID.append("Mod3CellVoltage7:");
      break;

   case DataPopulator::BatteryVoltage:
        convertedID.append("BatteryVoltage:");
      break;
   case DataPopulator::BatteryCurrent:
        convertedID.append("BatteryCurrent:");
      break;
   case DataPopulator::BatteryVoltageThresholdRising:
        convertedID.append("BatteryVoltageThresholdRising:");
      break;
   case DataPopulator::BatteryVoltageThresholdFalling:
        convertedID.append("BatteryVoltageThresholdFalling:");
      break;
   }

return convertedID;
}

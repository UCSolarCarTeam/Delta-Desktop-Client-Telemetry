#include "LoggerService.h"
#include "../../CommunicationLayer/ConnectionService/I_ConnectionService.h"

LoggerService::LoggerService(I_ConnectionService& connectionService,
                           QString filename)
: logTxtFile_(filename)
, logCsvFile_(filename)
, connectionService_(connectionService)
{
   /********************Connections********************/
   connect(&connectionService, SIGNAL(sendDebugMessage(QString)),
           this, SLOT (receivedConnectionService(QString)));

   /********************File Initializing********************/
   QDateTime date = QDateTime::currentDateTime();
   QString DebugFilePath("DebugLogs/"); //can only create ONE NEW folder.
   if(!QDir(DebugFilePath).exists()){
      QDir().mkdir(DebugFilePath);
   }

   filename.prepend(date.toString("yyyy.MM.dd_hh.mm.ss")); //following Canadian Standard 'ISO 8601'
   filename.prepend(DebugFilePath);

   /*Log Csv File*/
   logCsvFile_.setFileName(filename + ".csv");
   logCsvFile_.open(QIODevice::WriteOnly | QIODevice::Text);

   /*Log Text File*/
   logTxtFile_.setFileName(filename + ".txt");
   if(logTxtFile_.open(QIODevice::WriteOnly | QIODevice::Text)){
      QTextStream writer(&logTxtFile_);
      writer << "|======================";
      writer << date.toString("ddd MMM d yyyy");
      writer << "======================|" << endl;
      writer <<  "                     SOLARCAR  DEBUG  LOG" << endl;
      writer << "|===========================================================|" << endl;
   }
}

LoggerService::~LoggerService()
{
   printToDebuglogCsvFile();
   logTxtFile_.close();
   logCsvFile_.close();
}

void LoggerService::receivedConnectionService(QString debugMessage)
{
   emit sendDebugMessageToPresenter(debugMessage);
}

// gets the original RAW string that dataparse receieves
// (this will just be sent to the debuglogTxtFile)
void LoggerService::receivedDebugDataParser(QString debugMessage)
{
   QString messageToFile("             | RAW-STRING   : "); //Optional String prepending Message
   messageToFile.append(debugMessage);
   printlnToDebuglogTxtFile(messageToFile);
}

// gets the parsed values that dataparser emits and translates it to a human readable format
// and sends it to the debuglogTxtFile
void LoggerService::receivedParsedDataParser(int id, double value)
{
   QDateTime date = QDateTime::currentDateTime();
   QString messageToFile(" | PARSED-STRING: "); //Optional String prepending Message.
   messageToFile.prepend(date.toString("hh:mm:ss:zzz"));

   messageToFile.append(convertIDtoString(id));
   messageToFile.append(QString::number(value)); //May need to change this if we don't want raw 'value' going in.

   printlnToDebuglogTxtFile(messageToFile);

   storeCsv2DArray(id, value);
}

// Orientation of the Vectors is Vectors pointing downwards. Each Vector represents a columnn
void LoggerService::storeCsv2DArray(int id, int value)
{
   int currentMaxId = csv2DArray_.length(); // Number of Columns there are.
   int missing = id - currentMaxId + 1;

   if(missing > 0){    // if missing is postive, id doesn't have a spot within the array yet
     for(int i = 0; i < missing; i++)
     {
         QVector<int> newColumn;
         csv2DArray_.push_back(newColumn);
      }
   }

   csv2DArray_[id].push_back(value);
}

void LoggerService::printlnToDebuglogTxtFile(QString debugMessage)
{
   QTextStream writer(&logTxtFile_);
   writer << debugMessage << endl;
}

void LoggerService::printToDebuglogCsvFile(void)
{
   QTextStream writer(&logCsvFile_);
   QString messageToFile;

   int numOfColumns = csv2DArray_.length();
   int longestColumnLength = 0;

   messageToFile.clear();
   for(int i = 0; i < numOfColumns; i++)
   {
      messageToFile.append(convertIDtoString(i));
      messageToFile.append(",");
   }

   messageToFile.append("\n");
   writer << messageToFile;

   /*finds longest column*/
   for(int i = 0; i < numOfColumns; i++)
   {
      if(longestColumnLength < csv2DArray_.at(i).length()){
         longestColumnLength = csv2DArray_.at(i).length();
      }
   }

   /*write the values into the csv*/
   for(int currentRow = 0; currentRow < longestColumnLength; currentRow++)
   {
      messageToFile.clear();
      for(int index = 0; index < numOfColumns; index++)
      {
         if(csv2DArray_[index].length() > currentRow){
            messageToFile.append(QString::number(csv2DArray_[index].at(currentRow)));
         }
         messageToFile.append(",");
      }
      messageToFile.append("\n");
      writer << messageToFile;
   }
}

QString LoggerService::convertIDtoString(int id)
{
   QString convertedID;

   switch(id)
   {
   default:
      convertedID.append("**NO ID**");
      break;
   }
   return convertedID;
}


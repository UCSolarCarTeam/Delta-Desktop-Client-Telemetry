#include "DataParser.h"
#include "../ConnectionService/I_ConnectionService.h"
#include <QDebug>


DataParser::DataParser(QIODevice& device, I_ConnectionService& connectionService)
: ioDevice_(device)
, connectionService_ (connectionService)
{
  connect(&connectionService, SIGNAL(connectionSucceeded(QString)),
          this, SLOT (connectionOK(QString)));
}

DataParser::~DataParser()
{
}

void DataParser::connectionOK(QString)
{
   connect(&ioDevice_, SIGNAL(readyRead()),
           this, SLOT(handleInformationIncoming()));
}

void DataParser::handleInformationIncoming()
{
  ioDevice_.seek(0); //For qbuffer in testing, not required for serialport
  while(ioDevice_.canReadLine())
  {
    QByteArray data = ioDevice_.readLine();
    QString string(data);
    if(!data.isNull() && string.at(0) == '#')
    {
      for(int i = 1; i <string.length()-1; i++){
          if(string.at(i) < 48||string.at(i) > 57){
              if(string.at(i) != 45)
              return;
          }
      }
      int id = string.mid(1,2).toInt();
      double value = string.mid(3).toDouble();
      emit dataReceived(id, value);
      emit sendDebugMessage(data);
    }
  }
}


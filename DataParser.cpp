#include "DataParser.h"

DataParser::DataParser(QIODevice& device, I_ConnectionService& connectionService)
: ioDevice_(device)
, connectionService_ (connectionService)
{
  connect(&connectionService, SIGNAL(connectionSucceeded()),
          this, SLOT (connectionOK()));
}

DataParser::~DataParser()
{
}

void DataParser::connectionOK()
{
   connect(&ioDevice_, SIGNAL(readyRead()),
           this, SLOT(handleInformationIncomming()));
}

void DataParser::handleInformationIncoming()
{
  while(ioDevice_.canReadLine())
  {
    QByteArray data = ioDevice_.readLine();
    QString string(data);
    if(!data.isNull() && string.at(0) == '#')
    {
      int id = string.mid(1,2).toInt();
      int value = string.mid(3).toInt();
      emit dataReceived(id, value);
    }
  }
}

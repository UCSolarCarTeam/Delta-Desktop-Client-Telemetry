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
    if(!data.isNull())
    {
      QString string(data);
      int id = string.left(2).toInt();
      int value = string.mid(2).toInt();
      emit dataReceived(id, value);
    }
  }
}

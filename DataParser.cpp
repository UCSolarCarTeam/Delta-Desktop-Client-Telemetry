#include "DataParser.h"

DataParser::DataParser(QIODevice& device)
: ioDevice_(device)
{
  connect(&ioDevice_, SIGNAL(readyRead()), this, SLOT(handleInformationIncomming()));
}

DataParser::~DataParser()
{
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

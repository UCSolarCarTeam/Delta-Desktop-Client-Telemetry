#include "DebugHandler.h"
#include "../ConnectionService/I_ConnectionService.h"
#include "../DataParser/I_DataParser.h"

DebugHandler::DebugHandler(I_ConnectionService& connectionService, I_DataParser& dataParser)
: connectionService_(connectionService)
, dataParser_(dataParser)
{
   connect(&connectionService, SIGNAL(sendDebugMessage(QString)),
           this, SLOT (receivedConnectionService(QString)));

   connect(&dataParser, SIGNAL(sendDebugMessage),
           this, SLOT (receivedDataParser(QString)));
}

DebugHandler::~DebugHandler()
{

}


void DebugHandler::receivedConnectionService(QString debugMessage)
{
   emit sendDebugMessageToUI(debugMessage);

}

void DebugHandler::receivedDataParser(QString debugMessage)
{

}

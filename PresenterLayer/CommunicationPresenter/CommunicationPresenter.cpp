#include "CommunicationPresenter.h"
#include "../../CommunicationLayer/ConnectionService/I_ConnectionService.h"

CommunicationPresenter::CommunicationPresenter(I_ConnectionService& connectionService)
: connectionService_(connectionService)
{
    relayConnectionStatus();
}

void CommunicationPresenter::connectDataSource(QString portName, int baudRate)
{
    connectionService_.connectDataSource(portName, baudRate);
}
void CommunicationPresenter::disconnectDataSource()
{
   connectionService_.disconnectDataSource();
}

void CommunicationPresenter::relayConnectionStatus()
{
    connect(&connectionService_, SIGNAL(connectionFailed(QString)),
            this, SIGNAL(connectionFailed(QString)));
    connect(&connectionService_, SIGNAL(connectionSucceeded(QString)),
            this, SIGNAL(connectionSucceeded(QString)));
}
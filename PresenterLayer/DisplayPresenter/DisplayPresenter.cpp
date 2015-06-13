#include "DisplayPresenter.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../CommunicationLayer/ConnectionService/I_ConnectionService.h"


DisplayPresenter::DisplayPresenter(const I_PowerData& powerData,
                                   I_ConnectionService& connectionService)
: powerData_(powerData)
, connectionService_(connectionService)
{
    relayPowerData();
    relayConnectionStatus();
}

void DisplayPresenter::connectDataSource(QString portName, int baudRate)
{
    connectionService_.connectDataSource(portName, baudRate);
}
void DisplayPresenter::disconnectDataSource()
{
   connectionService_.disconnectDataSource();
}

void DisplayPresenter::relayConnectionStatus()
{
    connect(&connectionService_, SIGNAL(connectionFailed(QString)),
            this, SIGNAL(connectionFailed(QString)));
    connect(&connectionService_, SIGNAL(connectionSucceeded(QString)),
            this, SIGNAL(connectionSucceeded(QString)));
}

void DisplayPresenter::relayPowerData()
{
   connect(&powerData_, SIGNAL(busCurrentAReceived(double)),
           this, SIGNAL(busCurrentAReceived(double)));
   connect(&powerData_, SIGNAL(busVoltageReceived(double)),
           this, SIGNAL(busVoltageReceived(double)));
   connect(&powerData_, SIGNAL(motorVoltageRealReceived(double)),
           this, SIGNAL(motorVoltageRealReceived(double)));
   connect(&powerData_, SIGNAL(motorCurrentRealReceived(double)),
           this, SIGNAL(motorCurrentRealReceived(double)));
   connect(&powerData_, SIGNAL(backEmfImaginaryReceived(double)),
           this, SIGNAL(backEmfImaginaryReceived(double)));
   connect(&powerData_, SIGNAL(dcBusAmpHoursReceived(double)),
           this, SIGNAL(dcBusAmpHoursReceived(double)));
}

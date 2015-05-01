#include "DisplayPresenter.h"
#include "../../DataLayer/ArrayData/I_ArrayData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../CommunicationLayer/ConnectionService/I_ConnectionService.h"
#include "../../BusinessLayer/LoggerService/LoggerService.h"


DisplayPresenter::DisplayPresenter(const I_ArrayData& arrayData,
                                   const I_PowerData& powerData,
                                   I_ConnectionService& connectionService,
                                   LoggerService& loggerService)
: arrayData_(arrayData)
, powerData_(powerData)
, connectionService_(connectionService)
, loggerService_(loggerService)
{
    relayArrayData();
    relayPowerData();
    relayConnectionStatus();
    relayDebugMessage();
}

void DisplayPresenter::connectDataSource(QString portName, int baudRate)
{
    connectionService_.connectDataSource(portName, baudRate);
}
void DisplayPresenter::disconnectDataSource()
{
   connectionService_.disconnectDataSource();
}

void DisplayPresenter::relayDebugMessage()
{
   connect(&loggerService_, SIGNAL(sendDebugMessageToPresenter(QString)), this, SIGNAL(sendDebugMessage(QString)));
}

void DisplayPresenter::relayConnectionStatus()
{
    connect(&connectionService_, SIGNAL(connectionFailed(QString)), 
            this, SIGNAL(connectionFailed(QString)));
    connect(&connectionService_, SIGNAL(connectionSucceeded(QString)), 
            this, SIGNAL(connectionSucceeded(QString)));
}

void DisplayPresenter::relayArrayData()
{
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
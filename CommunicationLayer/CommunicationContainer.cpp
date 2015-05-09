#include <QtSerialPort/QSerialPort>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "ConnectionService/SerialPortConnectionService.h"
#include "DataParser/DataParser.h"
#include "DataPopulator/DataPopulator.h"

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer)
: port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(*port_))
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_,
                                   dataContainer.arrayData(),
                                   dataContainer.powerData(),
                                   dataContainer.vehicleData(),
                                   dataContainer.batteryData()))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

I_ConnectionService& CommunicationContainer::connectionService()
{
   return *connectionService_;
}

I_DataParser& CommunicationContainer::dataParser()
{
   return *dataParser_;
}

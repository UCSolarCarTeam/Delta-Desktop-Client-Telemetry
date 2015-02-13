#include <QtSerialPort/QSerialPort>
#include <QSharedPointer>

#include "../DataLayer/DataContainer.h"
#include "ConnectionService/SerialPortConnectionService.h"
#include "DataParser/DataParser.h"
#include "DataPopulator/DataPopulator.h"

#include "CommunicationContainer.h"
namespace
{
    const QString defaultPortName = "COM";
	const int defaultBaudrate = 115200;
}

CommunicationContainer::CommunicationContainer(QSharedPointer<DataContainer> dataContainer)
: dataContainer_(dataContainer)
, port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate, *port_))
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_,
                                   *(dataContainer_->arrayData()),
                                   *(dataContainer_->powerData()),
                                   *(dataContainer_->vehicleData()),
                                   *(dataContainer_->batteryData())))
{
}
QSharedPointer<QSerialPort> CommunicationContainer::port()
{
    return port_;
}
QSharedPointer<I_ConnectionService> CommunicationContainer::connectionService()
{
	return connectionService_;
}
QSharedPointer<I_DataParser> CommunicationContainer::dataParser()
{
	return dataParser_;
}
QSharedPointer<DataPopulator> CommunicationContainer::dataPopulator()
{
	return dataPopulator_;
}
CommunicationContainer::~CommunicationContainer()
{
}


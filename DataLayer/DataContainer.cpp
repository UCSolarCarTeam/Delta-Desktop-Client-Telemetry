#include "DataContainer.h"
#include <QtSerialPort/QSerialPort>

#include "DataParser/DataParser.h"
#include "DataPopulator/DataPopulator.h"
#include "ConnectionService/SerialPortConnectionService.h"

namespace
{
	const Qstring defaultPortName = "COM";
	const int defaultBaudrate = 115200;
}

DataContainer::DataContainer()
: port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate, *port_))
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_, *dataw))
{
}

DataContainer::~DataContainer()
{
}


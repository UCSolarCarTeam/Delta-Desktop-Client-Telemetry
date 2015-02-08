#include <QtSerialPort/QSerialPort>
#include <QSharedPointer>

#include "ConnectionService/SerialPortConnectionService.h"
#include "DataParser/DataParser.h"
#include "ArrayData/ArrayData.h"
#include "VehicleData/VehicleData.h"
#include "PowerData/PowerData.h"
#include "BatteryData/BatteryData.h"
#include "DataPopulator/DataPopulator.h"

#include "DataContainer.h"
namespace
{
    const QString defaultPortName = "COM";
	const int defaultBaudrate = 115200;
}

DataContainer::DataContainer()
: port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate, *port_))
, dataParser_(new DataParser(*port_, *connectionService_))
, arrayData_(new ArrayData())
, vehicleData_(new VehicleData())
, powerData_(new PowerData())
, batteryData_(new BatteryData()) 
, dataPopulator_(new DataPopulator(*dataParser_,
                                   *arrayData_,
                                   *powerData_,
                                   *vehicleData_,
                                   *batteryData_))
{
}
QSharedPointer<QSerialPort> DataContainer::port()
{
    return port_;
}
QSharedPointer<I_ConnectionService> DataContainer::connectionService()
{
	return connectionService_;
}
QSharedPointer<I_DataParser> DataContainer::dataParser()
{
	return dataParser_;
}
QSharedPointer<I_ArrayData> DataContainer::arrayData()
{
	return arrayData_;
}
QSharedPointer<I_PowerData> DataContainer::powerData()
{
	return powerData_;
}
QSharedPointer<I_VehicleData> DataContainer::vehicleData()
{
	return vehicleData_;
}
QSharedPointer<I_BatteryData> DataContainer::batteryData()
{
	return batteryData_;
}
QSharedPointer<DataPopulator> DataContainer::dataPopulator()
{
	return dataPopulator_;
}
DataContainer::~DataContainer()
{
}


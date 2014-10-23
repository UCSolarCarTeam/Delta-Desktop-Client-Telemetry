#include <QtSerialPort/QSerialPort>

#include "SolarCarTelemetry.h"
#include "TelemetryData.h"
#include "DataParser.h"
#include "DataPopulator.h"
#include "SerialPortConnectionService.h"

namespace
{
   const QString defaultPortName = "COM1";
   const int defaultBaudrate = 115200;
}
SolarCarTelemetry::SolarCarTelemetry(int& argc, char** argv)
: QApplication(argc, argv)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate))
, data_(new TelemetryData())
, port_(new QSerialPort)
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_, *data_))
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

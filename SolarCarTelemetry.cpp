#include <QtSerialPort/QSerialPort>

#include "SolarCarTelemetry.h"
#include "Data.h"
#include "DataParser.h"
#include "DataPopulator.h"

SolarCarTelemetry::SolarCarTelemetry()
: data_(new Data())
, port_(new QSerialPort)
, dataParser_(new DataParser(*port_))
, dataPopulator_(new DataPopulator(*dataParser_, *data_))
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

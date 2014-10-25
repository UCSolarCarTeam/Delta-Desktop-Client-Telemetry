#include <QtSerialPort/QSerialPort>

#include "SolarCarTelemetry.h"
#include "../TelemetryData/TelemetryData.h"
#include "../DataParser/DataParser.h"
#include "../DataPopulator/DataPopulator.h"
#include "../ConnectionService/SerialPortConnectionService.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"
#include "../DisplayPresenter/DisplayPresenter.h"

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
, displayPresenter_(new DisplayPresenter(*data_, *connectionService_))
, mainWindow_(new SolarCarTestUI())
{
   mainWindow_->show();
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

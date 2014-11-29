#include <QtSerialPort/QSerialPort>

#include "../ConnectionService/SerialPortConnectionService.h"
#include "../DataParser/DataParser.h"
#include "../DataPopulator/DataPopulator.h"
#include "../DebugHandler/DebugHandler.h"
#include "../DisplayPresenter/DisplayPresenter.h"
#include "../DisplayView/DisplayView.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"
#include "../TelemetryData/TelemetryData.h"
#include "SolarCarTelemetry.h"

namespace
{
   const QString defaultPortName = "COM1";
   const int defaultBaudrate = 115200;
   const QString defaultFilename = "DefaultSolarCarDebugLog";
}
SolarCarTelemetry::SolarCarTelemetry(int& argc, char** argv)
: QApplication(argc, argv)
, port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate, *port_))
, data_(new TelemetryData())
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_, *data_))
, debugHandler_(new DebugHandler(*connectionService_, *dataParser_, defaultFilename))
, displayPresenter_(new DisplayPresenter(*data_, *connectionService_, *debugHandler_))
, mainWindow_(new SolarCarTestUI())
, displayView_(new DisplayView(*displayPresenter_, *mainWindow_))
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

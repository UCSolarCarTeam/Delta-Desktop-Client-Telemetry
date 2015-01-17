#include <QtSerialPort/QSerialPort>

#include "../DataLayer/ConnectionService/SerialPortConnectionService.h"
#include "../DataLayer/DataParser/DataParser.h"
#include "../DataLayer/DataPopulator/DataPopulator.h"
#include "../BusinessLayer/DebugHandler/DebugHandler.h"
#include "../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../ViewLayer/DisplayView/DisplayView.h"
#include "../ViewLayer/SolarCarTestUi/SolarCarTestUI.h"
#include "../BusinessLayer/TelemetryData/TelemetryData.h"
#include "SolarCarTelemetry.h"

namespace
{
   const QString defaultPortName = "COM";
   const int defaultBaudrate = 115200;
   const QString defaultFilename = "SolarCarDebugLog";
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

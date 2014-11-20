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
}
SolarCarTelemetry::SolarCarTelemetry(int& argc, char** argv)
: QApplication(argc, argv)
, connectionService_(new SerialPortConnectionService(defaultPortName, defaultBaudrate))
, data_(new TelemetryData())
, port_(new QSerialPort)
, dataParser_(new DataParser(*port_, *connectionService_))
, dataPopulator_(new DataPopulator(*dataParser_, *data_))
, debugHandler_(new DebugHandler(*connectionService_, *dataParser_))
, displayPresenter_(new DisplayPresenter(*data_, *connectionService_))
, mainWindow_(new SolarCarTestUI())
, displayView_(new DisplayView(*displayPresenter_, *mainWindow_))
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

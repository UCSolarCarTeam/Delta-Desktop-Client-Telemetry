#include <QtSerialPort/QSerialPort>

#include "ViewLayer/ViewContainer.h"
#include "SolarCarTelemetry.h"

SolarCarTelemetry::SolarCarTelemetry(int& argc, char** argv)
: QApplication(argc, argv)
, viewLayer_(new ViewContainer())
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

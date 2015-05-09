#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewLayer/ViewContainer.h"

#include "SolarCarTelemetry.h"

SolarCarTelemetry::SolarCarTelemetry(int& argc, char** argv)
: QApplication(argc, argv)
, dataContainer_(new DataContainer())
, communicationContainer_(new CommunicationContainer(*dataContainer_))
, businessContainer_(new BusinessContainer(*communicationContainer_))
, presenterContainer_(new PresenterContainer(*dataContainer_,
      *communicationContainer_,
      *businessContainer_))
, viewContainer_(new ViewContainer(*presenterContainer_))
{
}

SolarCarTelemetry::~SolarCarTelemetry()
{
}

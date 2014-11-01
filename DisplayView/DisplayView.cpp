#include "../DisplayPresenter/DisplayPresenter.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"
#include "DisplayView.h"

DisplayView::DisplayView(class DisplayPresenter& presenter, class SolarCarTestUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   ui_.show();
    connect(&presenter, SIGNAL(driverSetSpeedRPMReceived(double)), this, SLOT(driverSetSpeedRPMReceived(double)));
}

DisplayView::driverSetSpeedRPMReceived(double RPMReceived)
{
    ui_.setDriverSetSpeedRPM().display(RPMReceived);
}

DisplayView::~DisplayView()
{
}


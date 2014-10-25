#include "../DisplayPresenter/DisplayPresenter.h"
#include "../SolarCarTestUi/SolarCarTestUI.h"
#include "DisplayView.h"

DisplayView::DisplayView(class DisplayPresenter& presenter, class SolarCarTestUI& ui)
: presenter_(presenter)
, ui_(ui)
{
   ui_.show();
}

DisplayView::~DisplayView()
{
}


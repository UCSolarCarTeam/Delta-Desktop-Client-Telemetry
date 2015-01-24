#include "ViewContainer.h"

#include "SolarCarTestUI/SolarCarTestUI.h"
#include "DisplayView/DisplayView.h"

ViewContainer::ViewContainer()
: mainWindow_(new SolarCarTestUI())
, displayView_(new DisplayView(*displayPresenter_, *mainWindow_))
{
}

ViewContainer::~ViewContainer()
{
}


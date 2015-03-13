#include <QSharedPointer>

#include "PresenterLayer/PresenterContainer.h"
#include "PowerUI/PowerUI.h"
#include "SolarCarTestUi/SolarCarTestUI.h"
#include "DisplayView/DisplayView.h"

#include "ViewContainer.h"

ViewContainer::ViewContainer(QSharedPointer<PresenterContainer> presenterContainer)
: presenterContainer_(presenterContainer)
, powerWidget_(new PowerUI())
, mainWindow_(new SolarCarTestUI())
, displayView_(new DisplayView(*(presenterContainer->displayPresenter()), 
			  				   *mainWindow_))
{
}

QSharedPointer<PowerUI> ViewContainer::powerWidget()
{
	return powerWidget_;
}

QSharedPointer<SolarCarTestUI> ViewContainer::mainWindow()
{
	return mainWindow_;
}
QSharedPointer<DisplayView> ViewContainer::displayView()
{
	return displayView_;
}

ViewContainer::~ViewContainer()
{
}


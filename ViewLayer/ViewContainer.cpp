#include <QSharedPointer>

#include "PresenterLayer/PresenterContainer.h"
#include "PowerUI/PowerUI.h"
#include "SolarCarTestUi/SolarCarTestUI.h"
#include "DisplayView/DisplayView.h"

#include "ViewContainer.h"

ViewContainer::ViewContainer(QSharedPointer<PresenterContainer> presenterContainer)
: presenterContainer_(presenterContainer)
, mainWindow_(new PowerUI())
, displayView_(new DisplayView(*(presenterContainer->displayPresenter()), 
			  				   *mainWindow_))
{
}

// QSharedPointer<PowerUI> ViewContainer::powerWidget()
// {
// 	return powerWidget_;
// }

QSharedPointer<PowerUI> ViewContainer::mainWindow()
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


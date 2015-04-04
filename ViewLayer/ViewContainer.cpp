#include <QSharedPointer>

#include "PresenterLayer/PresenterContainer.h"
#include "PowerUI/PowerUI.h"
#include "MpptUI/MpptUI.h"
#include "FaultsUI/FaultsUI.h"
#include "I_SolarCarWindow/I_SolarCarWindow.h"
#include "PowerView/PowerView.h"
#include "MpptView/MpptView.h"
#include "FaultsView/FaultsView.h"
#include "OverlordWidget/OverlordWidget.h"
#include "DisplayView/DisplayView.h"

#include "ViewContainer.h"

ViewContainer::ViewContainer(QSharedPointer<PresenterContainer> presenterContainer)
: presenterContainer_(presenterContainer)
, powerUI_(new PowerUI())
, mpptUI_(new MpptUI())
, faultsUI_(new FaultsUI())
, powerView_(new PowerView(*(presenterContainer_->displayPresenter()), *powerUI_))
, mpptView_(new MpptView(*(presenterContainer_->displayPresenter()), *mpptUI_))
, faultsView_(new FaultsView(*(presenterContainer_->displayPresenter()), *faultsUI_))
, overlordWidget_(new OverlordWidget(QList<I_SolarCarWindow*>() << powerUI_ << mpptUI_ << faultsUI_))
, displayView_(new DisplayView(*(presenterContainer_->displayPresenter()), *overlordWidget_))
{
}

PowerUI* ViewContainer::powerUI()
{
	return powerUI_;
}
MpptUI* ViewContainer::mpptUI()
{
	return mpptUI_;
}
FaultsUI* ViewContainer::faultsUI()
{
	return faultsUI_;
}
QSharedPointer<PowerView> ViewContainer::powerView()
{
	return powerView_;
}
QSharedPointer<MpptView> ViewContainer::mpptView()
{
	return mpptView_;
}
QSharedPointer<FaultsView> ViewContainer::faultsView()
{
	return faultsView_;
}
QSharedPointer<OverlordWidget> ViewContainer::overlordWidget()
{
	return overlordWidget_;
}
QSharedPointer<DisplayView> ViewContainer::displayView()
{
	return displayView_;
}

ViewContainer::~ViewContainer()
{
}


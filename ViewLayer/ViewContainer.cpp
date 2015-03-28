#include <QSharedPointer>

#include "PresenterLayer/PresenterContainer.h"
#include "PowerUI/PowerUI.h"
// #include "MpptUI/MpptUI.h"
// #include "FaultsUI/FaultsUI.h"
#include "PowerView/PowerView.h"
// #include "MpptView/MpptView.h"
// #include "FaultsView/FaultsView.h"
#include "OverlordWidget/OverlordWidget.h"
#include "DisplayView/DisplayView.h"

#include "ViewContainer.h"

ViewContainer::ViewContainer(QSharedPointer<PresenterContainer> presenterContainer)
: presenterContainer_(presenterContainer)
, powerUI_(new PowerUI())
// , mpptUI_(new mpptUI())
// , FaultsUI_(new FaultsUI())
, powerView_(new PowerView(*(presenterContainer_->displayPresenter()), *powerUI_))
// , mpptView_(new mpptView())
// , faultsView_(new faultsView())
, overlordWidget_(new OverlordWidget(QList<QWidget*>() << powerUI_))
, displayView_(new DisplayView(*(presenterContainer_->displayPresenter()), *overlordWidget_))
{
}

PowerUI* ViewContainer::powerUI()
{
	return powerUI_;
}
// QSharedPointer<MpptUI> ViewContainer::mpptUI()
// {
	// return mpptUI_;
// }
// QSharedPointer<FaultUI> ViewContainer::FaultsUI()
// {
	// return FaultsUI_;
// }
QSharedPointer<PowerView> ViewContainer::powerView()
{
	return powerView_;
}
// QSharedPointer<MpptView> ViewContainer::mpptView()
// {
	// return mpptView_;
// }
// QSharedPointer<FaultsView> ViewContainer::faultsView()
// {
	// return faultsView_;
// }
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


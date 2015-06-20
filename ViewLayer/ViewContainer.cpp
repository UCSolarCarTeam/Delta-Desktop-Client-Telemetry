#include "DisplayView/DisplayView.h"
#include "EscapeDialog/EscapeDialog.h"
#include "EscapeDialogView/EscapeDialogView.h"
#include "FaultsUI/FaultsUI.h"
#include "FaultsView/FaultsView.h"
#include "I_SolarCarWindow/I_SolarCarWindow.h"
#include "MpptUI/MpptUI.h"
#include "MpptView/MpptView.h"
#include "OverlordWidget/OverlordWidget.h"
#include "PowerUI/PowerUI.h"
#include "PowerView/PowerView.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer)
: escapeDialog_(new EscapeDialog())
, powerUI_(new PowerUI())
, mpptUI_(new MpptUI())
, faultsUI_(new FaultsUI())
, escapeDialogView_(new EscapeDialogView(*escapeDialog_))
, powerView_(new PowerView(
      presenterContainer.displayPresenter(),
      presenterContainer.batteryPresenter(),
      presenterContainer.vehiclePresenter(),
      presenterContainer.powerGraphsPresenter(),
      *powerUI_))
, mpptView_(new MpptView(presenterContainer.displayPresenter(), *mpptUI_))
, faultsView_(new FaultsView(presenterContainer.faultsPresenter(), *faultsUI_))
, overlordWidget_(new OverlordWidget(QList<I_SolarCarWindow*>() << powerUI_ << mpptUI_ << faultsUI_,
      escapeDialog_))
, displayView_(new DisplayView(presenterContainer.displayPresenter(), *overlordWidget_))
{
}

ViewContainer::~ViewContainer()
{
}

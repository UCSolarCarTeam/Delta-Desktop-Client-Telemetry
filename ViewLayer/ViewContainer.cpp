#include "DisplayView/DisplayView.h"
#include "EscapeDialog/EscapeDialog.h"
#include "EscapeDialogView/EscapeDialogView.h"
#include "FaultsUI/FaultsUI.h"
#include "FaultsView/FaultsView.h"
#include "I_SolarCarWindow/I_SolarCarWindow.h"
#include "MpptUI/MpptUI.h"
#include "MpptView/MpptView.h"
#include "OverlordWidget/OverlordWidget.h"
#include "PlaybackUI/PlaybackUI.h"
#include "PlaybackView/PlaybackView.h"
#include "PowerUI/PowerUI.h"
#include "PowerView/PowerView.h"
#include "PresenterLayer/PresenterContainer.h"
#include "ViewContainer.h"

ViewContainer::ViewContainer(PresenterContainer& presenterContainer)
: escapeDialog_(new EscapeDialog())
, powerUI_(new PowerUI())
, faultsUI_(new FaultsUI())
, playbackUI_(new PlaybackUI)
, escapeDialogView_(new EscapeDialogView(
      *escapeDialog_, *playbackUI_))
, powerView_(new PowerView(
      presenterContainer.batteryPresenter(),
      presenterContainer.vehiclePresenter(),
      presenterContainer.powerPresenter(),
      presenterContainer.powerGraphsPresenter(),
      presenterContainer.communicationPresenter(),
      *powerUI_))
, faultsView_(new FaultsView(presenterContainer.faultsPresenter(), *faultsUI_))
, overlordWidget_(new OverlordWidget(QList<I_SolarCarWindow*>() << powerUI_ << faultsUI_, escapeDialog_))
, displayView_(new DisplayView(*overlordWidget_))
, playbackView_(new PlaybackView(
   presenterContainer.playbackPresenter(),
   *playbackUI_))
{
}

ViewContainer::~ViewContainer()
{
}

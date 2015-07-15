#pragma once

#include <QScopedPointer>

class DisplayView;
class EscapeDialog;
class EscapeDialogView;
class FaultsUI;
class FaultsView;
class MpptUI;
class MpptView;
class OverlordWidget;
class PlaybackUI;
class PlaybackView;
class PowerUI;
class PowerView;
class PresenterContainer;

class ViewContainer
{
public:
   explicit ViewContainer(PresenterContainer& presenterContainer);
   ~ViewContainer();

private:
   EscapeDialog* escapeDialog_;
   PowerUI* powerUI_;
   MpptUI* mpptUI_;
   FaultsUI* faultsUI_;
   QScopedPointer<PlaybackUI> playbackUI_;
   QScopedPointer<EscapeDialogView> escapeDialogView_;
   QScopedPointer<PowerView> powerView_;
   QScopedPointer<MpptView> mpptView_;
   QScopedPointer<FaultsView> faultsView_;
   QScopedPointer<OverlordWidget> overlordWidget_;
   QScopedPointer<DisplayView> displayView_;
   QScopedPointer<PlaybackView> playbackView_;
};

#pragma once

#include <QScopedPointer>

class PresenterContainer;
class EscapeDialog;
class PowerUI;
class MpptUI;
class FaultsUI;
class EscapeDialogView;
class PowerView;
class MpptView;
class FaultsView;
class OverlordWidget;
class DisplayView;

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
   QScopedPointer<EscapeDialogView> escapeDialogView_;
   QScopedPointer<PowerView> powerView_;
   QScopedPointer<MpptView> mpptView_;
   QScopedPointer<FaultsView> faultsView_;
   QScopedPointer<OverlordWidget> overlordWidget_;
   QScopedPointer<DisplayView> displayView_;
};

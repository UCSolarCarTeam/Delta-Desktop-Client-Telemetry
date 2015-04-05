#pragma once

#include <QSharedPointer>

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
    QSharedPointer<EscapeDialogView> escapeDialogView();
	QSharedPointer<PowerView> powerView();
	QSharedPointer<MpptView> mpptView();
	QSharedPointer<FaultsView> faultsView();
    EscapeDialog* escapeDialog();
	PowerUI* powerUI();
	MpptUI* mpptUI();
	FaultsUI* faultsUI();
	QSharedPointer<OverlordWidget> overlordWidget();
	QSharedPointer<DisplayView> displayView();

    explicit ViewContainer(QSharedPointer<PresenterContainer> presenterContainer);
    ~ViewContainer();

private:
	QSharedPointer<PresenterContainer> presenterContainer_;
    EscapeDialog* escapeDialog_;
	PowerUI* powerUI_; 
	MpptUI* mpptUI_;
	FaultsUI* faultsUI_;
    QSharedPointer<EscapeDialogView> escapeDialogView_;
	QSharedPointer<PowerView> powerView_;
	QSharedPointer<MpptView> mpptView_;
	QSharedPointer<FaultsView> faultsView_;
	QSharedPointer<OverlordWidget> overlordWidget_;
	QSharedPointer<DisplayView> displayView_; 
};


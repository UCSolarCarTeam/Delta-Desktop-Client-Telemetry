#pragma once

#include <QSharedPointer>

class PresenterContainer;
class PowerUI;
// class MpptUI;
// class FaultsUI;
class PowerView;
// class MpptView;
// class FaultsView;
class OverlordWidget;
class DisplayView;

class ViewContainer
{
public:
	QSharedPointer<PowerView> powerView();
	// QSharedPointer<MpptView> mpptView();
	// QSharedPointer<FaultsView> faultsView();
	PowerUI* powerUI();
	// QSharedPointer<MpptUI> mpptUI();
	// QSharedPointer<FaultUI> FaultsUI();
	QSharedPointer<OverlordWidget> overlordWidget();
	QSharedPointer<DisplayView> displayView();

    explicit ViewContainer(QSharedPointer<PresenterContainer> presenterContainer);
    ~ViewContainer();

private:
	QSharedPointer<PresenterContainer> presenterContainer_;
	PowerUI* powerUI_; 
	// QSharedPointer<MpptUI> mpptUI_;
	// QSharedPointer<FaultsUI> faultsUI_;
	QSharedPointer<PowerView> powerView_;
	// QSharedPointer<MpptView> mpptView_;
	// QSharedPointer<FaultsView> faultsView_;
	QSharedPointer<OverlordWidget> overlordWidget_;
	QSharedPointer<DisplayView> displayView_; 
};


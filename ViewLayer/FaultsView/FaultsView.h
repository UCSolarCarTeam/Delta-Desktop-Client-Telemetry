#pragma once

#include <QObject>
#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"

class FaultsPresenter;
class FaultsUI;

class FaultsView : public QObject
{
	Q_OBJECT
public:
    FaultsView(FaultsPresenter& presenter, FaultsUI& ui);
    ~FaultsView();

private:
	FaultsPresenter& faultsPresenter_;
	FaultsUI& ui_;

private slots:
	void motorFaultsReceived(MotorFaults motorFaults);
	void limitFlagsReceived(LimitFlags limitFlags);
	void batteryFaultsReceived(BatteryFaults batteryFaults);
};


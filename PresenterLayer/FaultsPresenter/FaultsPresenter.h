#pragma once

#include <QObject>
#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"

class I_FaultsData;

class FaultsPresenter : public QObject
{
	Q_OBJECT
public:
	explicit FaultsPresenter(const I_FaultsData& faultsData);

private:
	void relayFaultsData();

	const I_FaultsData& faultsData_;

signals:
	void motorFaultsReceived(MotorFaults motorFaults);
	void limitFlagsReceived(LimitFlags limitFlags);
	void batteryFaultsReceived(BatteryFaults batteryFaults);
}; 
#pragma once

#include <QObject>

#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"

class I_FaultsData : public QObject
{
	Q_OBJECT
public:
	virtual ~I_FaultsData() {}

	/* FaultData Gets */
	virtual MotorFaults motorOneFaults() const = 0;
	virtual LimitFlags motorOneLimitFlags() const = 0;
	virtual MotorFaults motorTwoFaults() const = 0;
	virtual LimitFlags motorTwoLimitFlags() const = 0;
	virtual BatteryFaults batteryFaults() const = 0;

	/* FaultData Sets */
	virtual void setMotorOneFaults(MotorFaults motorFaults) = 0;
	virtual void setMotorOneLimitFlags(LimitFlags limitFlags) = 0;
	virtual void setMotorTwoFaults(MotorFaults motorFaults) = 0;
	virtual void setMotorTwoLimitFlags(LimitFlags limitFlags) = 0;
	virtual void setBatteryFaults(BatteryFaults batteryFaults) = 0;

signals:
	void motorOneFaultsReceived(MotorFaults motorFaults);
	void motorOneLimitFlagsReceived(LimitFlags limitFlags);
	void motorTwoFaultsReceived(MotorFaults motorFaults);
	void motorTwoLimitFlagsReceived(LimitFlags limitFlags);
	void batteryFaultsReceived(BatteryFaults batteryFaults);
};

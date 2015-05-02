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
	virtual MotorFaults motorFaults() const = 0;
	virtual LimitFlags limitFlags() const = 0;
	virtual BatteryFaults batteryFaults() const = 0;

	/* FaultData Sets */
	virtual void setMotorFaults(MotorFaults motorFaults) = 0;	
	virtual void setLimitFlags(LimitFlags limitFlags) = 0;
	virtual void setBatteryFaults(BatteryFaults batteryFaults) = 0;

signals:
	void motorFaultsReceived(MotorFaults motorFaults);
	void limitFlagsReceived(LimitFlags limitFlags);
	void batteryFaultsReceived(BatteryFaults batteryFaults);
};
#pragma once

#include "I_FaultsData.h"

#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"	
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"	
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"	

class FaultsData : public I_FaultsData
{
public:
	FaultsData();
	virtual ~FaultsData();

	/* FaultData Gets */
	virtual MotorFaults motorFaults() const;
	virtual LimitFlags limitFlags() const;
	virtual BatteryFaults batteryFaults() const;

	/* FaultData Sets */
	virtual void setMotorFaults(MotorFaults motorFaults);	
	virtual void setLimitFlags(LimitFlags limitFlags);
	virtual void setBatteryFaults(BatteryFaults batteryFaults);

private:
	MotorFaults motorFaults_;
	LimitFlags limitFlags_;
	BatteryFaults batteryFaults_;
};
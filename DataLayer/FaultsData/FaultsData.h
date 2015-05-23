#pragma once

#include "I_FaultsData.h"

class MotorFaults;	
class LimitFlags;	
class BatteryFaults;	

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
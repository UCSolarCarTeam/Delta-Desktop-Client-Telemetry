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
	MotorFaults motorOneFaults() const;
	LimitFlags motorOneLimitFlags() const;
	MotorFaults motorTwoFaults() const;
	LimitFlags motorTwoLimitFlags() const;
	BatteryFaults batteryFaults() const;

	/* FaultData Sets */
	void setMotorOneFaults(MotorFaults motorFaults);
	void setMotorOneLimitFlags(LimitFlags limitFlags);
	void setMotorTwoFaults(MotorFaults motorFaults);
	void setMotorTwoLimitFlags(LimitFlags limitFlags);
	void setBatteryFaults(BatteryFaults batteryFaults);

private:
	MotorFaults motorOneFaults_;
	LimitFlags motorOneLimitFlags_;
	MotorFaults motorTwoFaults_;
	LimitFlags motorTwoLimitFlags_;
	BatteryFaults batteryFaults_;
};

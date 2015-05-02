#include "FaultsData.h"

FaultsData::FaultsData()
: motorFaults_(0)
, limitFlags_(0)
, batteryFaults_(0)
{
}
FaultsData::~FaultsData()
{
}

/* FaultData Gets */
MotorFaults FaultsData::motorFaults() const
{
	return motorFaults_;
}
LimitFlags FaultsData::limitFlags() const
{
    return limitFlags_;
}
BatteryFaults FaultsData::batteryFaults() const
{
	return batteryFaults_;
}

/* FaultData Sets */
void FaultsData::setMotorFaults(MotorFaults motorFaults)
{
	motorFaults_ = motorFaults;
	emit motorFaultsReceived(motorFaults_);
}	
void FaultsData::setLimitFlags(LimitFlags limitFlags)
{
	limitFlags_ = limitFlags;
	emit limitFlagsReceived(limitFlags_);
}
void FaultsData::setBatteryFaults(BatteryFaults batteryFaults)
{
	batteryFaults_ = batteryFaults;
	emit batteryFaultsReceived(batteryFaults_);
}

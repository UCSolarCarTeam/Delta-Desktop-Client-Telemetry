#include "FaultsData.h"

FaultsData::FaultsData()
: motorOneFaults_(0)
, motorOneLimitFlags_(0)
, motorTwoFaults_(0)
, motorTwoLimitFlags_(0)
, batteryFaults_(0)
{
}
FaultsData::~FaultsData()
{
}

/* FaultData Gets */
MotorFaults FaultsData::motorOneFaults() const
{
   return motorOneFaults_;
}

LimitFlags FaultsData::motorOneLimitFlags() const
{
   return motorOneLimitFlags_;
}

MotorFaults FaultsData::motorTwoFaults() const
{
   return motorTwoFaults_;
}

LimitFlags FaultsData::motorTwoLimitFlags() const
{
   return motorTwoLimitFlags_;
}
BatteryFaults FaultsData::batteryFaults() const
{
   return batteryFaults_;
}

/* FaultData Sets */
void FaultsData::setMotorOneFaults(MotorFaults motorFaults)
{
   motorOneFaults_ = motorFaults;
   emit motorOneFaultsReceived(motorOneFaults_);
}
void FaultsData::setMotorOneLimitFlags(LimitFlags limitFlags)
{
   motorOneLimitFlags_ = limitFlags;
   emit motorOneLimitFlagsReceived(motorOneLimitFlags_);
}
void FaultsData::setMotorTwoFaults(MotorFaults motorFaults)
{
   motorTwoFaults_ = motorFaults;
   emit motorTwoFaultsReceived(motorTwoFaults_);
}
void FaultsData::setMotorTwoLimitFlags(LimitFlags limitFlags)
{
   motorTwoLimitFlags_ = limitFlags;
   emit motorTwoLimitFlagsReceived(motorTwoLimitFlags_);
}
void FaultsData::setBatteryFaults(BatteryFaults batteryFaults)
{
   batteryFaults_ = batteryFaults;
   emit batteryFaultsReceived(batteryFaults_);
}

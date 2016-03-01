#include "FaultsPresenter.h"
#include "DataLayer/FaultsData/I_FaultsData.h"

FaultsPresenter::FaultsPresenter(const I_FaultsData& faultsData)
: faultsData_ (faultsData)
{
   relayFaultsData();
}

void FaultsPresenter::relayFaultsData()
{
   connect(&faultsData_, SIGNAL(motorOneFaultsReceived(MotorFaults)),
         this, SIGNAL(motorOneFaultsReceived(MotorFaults)));
   connect(&faultsData_, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
         this, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)));
   connect(&faultsData_, SIGNAL(motorTwoFaultsReceived(MotorFaults)),
         this, SIGNAL(motorTwoFaultsReceived(MotorFaults)));
   connect(&faultsData_, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)),
         this, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)));
   connect(&faultsData_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
         this, SIGNAL(batteryFaultsReceived(BatteryFaults)));
}

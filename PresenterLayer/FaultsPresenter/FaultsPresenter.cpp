#include "FaultsPresenter.h"
#include "../../DataLayer/FaultsData/I_FaultsData.h"

FaultsPresenter::FaultsPresenter(const I_FaultsData& faultsData)
: faultsData_ (faultsData)
{
	relayFaultsData();
}

void FaultsPresenter::relayFaultsData()
{
	connect(&faultsData_, SIGNAL(motorFaultsReceived(MotorFaults)),
			this, SIGNAL(motorFaultsReceived(MotorFaults)));
	connect(&faultsData_, SIGNAL(limitFlagsReceived(LimitFlags)),
			this, SIGNAL(limitFlagsReceived(LimitFlags)));
	connect(&faultsData_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
			this, SIGNAL(batteryFaultsReceived(BatteryFaults)));
}

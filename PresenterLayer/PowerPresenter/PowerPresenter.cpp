#include "PowerPresenter.h"
#include "DataLayer/PowerData/I_PowerData.h"

PowerPresenter::PowerPresenter(const I_PowerData& powerData)
: powerData_(powerData)
{
   relayPowerData();
}

void PowerPresenter::relayPowerData()
{
   connect(&powerData_, SIGNAL(busCurrentAReceived(double)),
           this, SIGNAL(busCurrentAReceived(double)));
   connect(&powerData_, SIGNAL(busVoltageReceived(double)),
           this, SIGNAL(busVoltageReceived(double)));
}

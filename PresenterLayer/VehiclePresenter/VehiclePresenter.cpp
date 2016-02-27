#include "VehiclePresenter.h"
#include "DataLayer/VehicleData/I_VehicleData.h"

VehiclePresenter::VehiclePresenter(const I_VehicleData& vehicleData)
: vehicleData_(vehicleData)
{
   relayVehicleData();
}

void VehiclePresenter::relayVehicleData()
{
   connect(&vehicleData_, SIGNAL(driverSetSpeedMetersPerSecondReceived(double)),
           this, SIGNAL(driverSetSpeedMetersPerSecondReceived(double)));
   connect(&vehicleData_, SIGNAL(driverSetCurrentReceived(double)),
           this, SIGNAL(driverSetCurrentReceived(double)));
   connect(&vehicleData_, SIGNAL(vehicleVelocityMetersPerSecondReceived(double)),
           this, SIGNAL(vehicleVelocityMetersPerSecondReceived(double)));
   connect(&vehicleData_, SIGNAL(motorVelocityRpmReceived(double)),
           this, SIGNAL(motorVelocityRpmReceived(double)));
   connect(&vehicleData_, SIGNAL(ipmHeatSinkTempReceived(double)),
           this, SIGNAL(ipmHeatSinkTempReceived(double)));
   connect(&vehicleData_, SIGNAL(dspBoardTempReceived(double)),
           this, SIGNAL(dspBoardTempReceived(double)));
   connect(&vehicleData_, SIGNAL(receivedErrorCountReceived(double)),
           this, SIGNAL(receivedErrorCountReceived(double)));
   connect(&vehicleData_, SIGNAL(transmittedErrorCountReceived(double)),
           this, SIGNAL(transmittedErrorCountReceived(double)));
}

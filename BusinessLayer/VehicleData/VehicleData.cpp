#include "VehicleData.h"

VehicleData::VehicleData()
{
}

VehicleData::~VehicleData()
{
}

/*PowerData "Gets"*/
double VehicleData::driverSetSpeedRPM() const
{   
   return driverSetSpeedRPM_;
}

double VehicleData::driverSetCurrent() const
{
   return driverSetCurrent_;
}

double VehicleData::vehicleVelocityKph() const
{
   return vehicleVelocityKph_;
}

double VehicleData::motorVelocityRpm() const
{
   return motorVelocityRpm_;
}

double VehicleData::ipmHeatSinkTemp() const
{
   return ipmHeatSinkTemp_;
}
double VehicleData::dspBoardTemp() const
{
   return dspBoardTemp_;
}

double VehicleData::receivedErrorCount() const
{
   return receivedErrorCount_;
}
double VehicleData::transmittedErrorCount() const
{
   return transmittedErrorCount_;
}

/*PowerData "Sets"*/
void VehicleData::setDriverSetSpeedRPM(double driverSetSpeedRPM)
{
   driverSetSpeedRPM_ = driverSetSpeedRPM;
   emit driverSetSpeedRPMReceived(driverSetSpeedRPM_);
}
void VehicleData::setDriverSetCurrent(double driverSetCurrent)
{
   driverSetCurrent_ = driverSetCurrent;
   emit driverSetCurrentReceived(driverSetCurrent_);
}

void VehicleData::setVehicleVelocityKph(double vehicleVelocityKph)
{
   vehicleVelocityKph_ = vehicleVelocityKph;
   emit vehicleVelocityKphReceived(vehicleVelocityKph_);
}

void VehicleData::setMotorVelocityRpm(double motorVelocityRpm)
{
   motorVelocityRpm_ = motorVelocityRpm;
   emit motorVelocityRpmReceived(motorVelocityRpm_);
}

void VehicleData::setIpmHeatSinkTemp(double ipmHeatSinkTemp)
{
   ipmHeatSinkTemp_ = ipmHeatSinkTemp;
   emit ipmHeatSinkTempReceived(ipmHeatSinkTemp_);
}
void VehicleData::setDspBoardTemp(double dspBoardTemp)
{
   dspBoardTemp_ = dspBoardTemp;
   emit dspBoardTempReceived(dspBoardTemp_);
}

void VehicleData::setReceivedErrorCount(double receivedErrorCount)
{
   receivedErrorCount_ = receivedErrorCount;
   emit receivedErrorCountReceived(receivedErrorCount_);
}
void VehicleData::setTransmittedErrorCount(double transmittedErrorCount)
{
   transmittedErrorCount_ = transmittedErrorCount;
   emit transmittedErrorCountReceived(transmittedErrorCount_);
}



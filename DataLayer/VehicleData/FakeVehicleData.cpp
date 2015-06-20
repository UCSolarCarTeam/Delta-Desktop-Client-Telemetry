#include "FakeVehicleData.h"

FakeVehicleData::FakeVehicleData()
{
}

FakeVehicleData::~FakeVehicleData()
{
}

/*PowerData "Gets"*/
double FakeVehicleData::driverSetSpeedMetersPerSecond() const
{   
   return 1;
}

double FakeVehicleData::driverSetCurrent() const
{
   return 2;
}

double FakeVehicleData::vehicleVelocityMetersPerSecond() const
{
   return 3;
}

double FakeVehicleData::motorVelocityRpm() const
{
   return 4;
}

double FakeVehicleData::ipmHeatSinkTemp() const
{
   return 5;
}
double FakeVehicleData::dspBoardTemp() const
{
   return 6;
}

double FakeVehicleData::receivedErrorCount() const
{
   return 7;
}
double FakeVehicleData::transmittedErrorCount() const
{
   return 8;
}

/*PowerData "Sets"*/
void FakeVehicleData::setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond){}
void FakeVehicleData::setDriverSetCurrent(double driverSetCurrent){}
void FakeVehicleData::setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond){}
void FakeVehicleData::setMotorVelocityRpm(double motorVelocityRpm){}
void FakeVehicleData::setIpmHeatSinkTemp(double ipmHeatSinkTemp){}
void FakeVehicleData::setDspBoardTemp(double dspBoardTemp){}
void FakeVehicleData::setReceivedErrorCount(double receivedErrorCount){}
void FakeVehicleData::setTransmittedErrorCount(double transmittedErrorCount){}
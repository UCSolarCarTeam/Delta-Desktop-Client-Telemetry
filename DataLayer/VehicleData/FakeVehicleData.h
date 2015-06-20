#pragma once

#include "I_VehicleData.h"

class FakeVehicleData : public I_VehicleData
{
public:
    FakeVehicleData();
    virtual ~FakeVehicleData();

    /*VehicleData "Gets"*/
    double driverSetSpeedMetersPerSecond() const;
    double driverSetCurrent() const;
    double vehicleVelocityMetersPerSecond() const;
    double motorVelocityRpm() const;
    double ipmHeatSinkTemp() const;
    double dspBoardTemp() const;
    double receivedErrorCount() const;
    double transmittedErrorCount() const;

    /*VehicleData "Sets"*/
    void setDriverSetSpeedMetersPerSecond(double driverSetSpeedMetersPerSecond);
    void setDriverSetCurrent(double driverSetCurrent);
    void setVehicleVelocityMetersPerSecond(double vehicleVelocityMetersPerSecond);
    void setMotorVelocityRpm(double motorVelocityRpm);
    void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
    void setDspBoardTemp(double dspBoardTemp);
    void setReceivedErrorCount(double receivedErrorCount);
    void setTransmittedErrorCount(double transmittedErrorCount);
};

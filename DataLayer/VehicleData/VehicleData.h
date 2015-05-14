#pragma once

#include "I_VehicleData.h"

class VehicleData : public I_VehicleData
{
public:
    VehicleData();
    virtual ~VehicleData();

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

private:
    double driverSetSpeedMetersPerSecond_;
    double driverSetCurrent_;
    double vehicleVelocityMetersPerSecond_;
    double motorVelocityRpm_;
    double ipmHeatSinkTemp_;
    double dspBoardTemp_;
    double receivedErrorCount_;
    double transmittedErrorCount_;
};

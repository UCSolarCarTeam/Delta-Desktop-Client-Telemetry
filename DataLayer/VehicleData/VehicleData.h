#pragma once

#include "I_VehicleData.h"

class VehicleData : public I_VehicleData
{
public:
    VehicleData();
    virtual ~VehicleData();

    /*VehicleData "Gets"*/
    double driverSetSpeedRPM() const;
    double driverSetCurrent() const;
    double vehicleVelocityKph() const;
    double motorVelocityRpm() const;
    double ipmHeatSinkTemp() const;
    double dspBoardTemp() const;
    double receivedErrorCount() const;
    double transmittedErrorCount() const;

    /*VehicleData "Sets"*/
    void setDriverSetSpeedRPM(double driverSetSpeedRPM);
    void setDriverSetCurrent(double driverSetCurrent);
    void setVehicleVelocityKph(double vehicleVelocityKph);
    void setMotorVelocityRpm(double motorVelocityRpm);
    void setIpmHeatSinkTemp(double ipmHeatSinkTemp);
    void setDspBoardTemp(double dspBoardTemp);
    void setReceivedErrorCount(double receivedErrorCount);
    void setTransmittedErrorCount(double transmittedErrorCount);

private:
    double driverSetSpeedRPM_;
    double driverSetCurrent_;
    double vehicleVelocityKph_;
    double motorVelocityRpm_;
    double ipmHeatSinkTemp_;
    double dspBoardTemp_;
    double receivedErrorCount_;
    double transmittedErrorCount_;
};

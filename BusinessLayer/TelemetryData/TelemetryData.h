#pragma once

#include "I_TelemetryData.h"

class TelemetryData : public I_TelemetryData
{
public:
  TelemetryData();
  virtual ~TelemetryData();

  /*Data "Gets"*/
  double driverSetSpeedRPM() const;
  double driverSetCurrent() const;

  double vehicleVelocityKph() const;

  double motorVelocityRpm() const;

  
  double ipmHeatSinkTemp() const;
  double dspBoardTemp() const;


  double receivedErrorCount() const;
  double transmittedErrorCount() const;



   /*Data "Sets"*/
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



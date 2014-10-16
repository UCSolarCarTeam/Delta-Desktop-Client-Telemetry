#pragma once

#include "I_TelemetryData.h"

class TelemetryData : public I_TelemetryData
{
public:
  TelemetryData();
  virtual ~TelemetryData();

  double vehicleVelocity() const;
  void setVehicleVelocity(double vehicleVelocity);

private:
  double vehicleVelocity_;
};

#include "TelemetryData.h"

TelemetryData::TelemetryData()
{
}

TelemetryData::~TelemetryData()
{
}

double TelemetryData::vehicleVelocity() const
{
  return vehicleVelocity_;
}

void TelemetryData::setVehicleVelocity(double vehicleVelocity)
{
  vehicleVelocity_ = vehicleVelocity;
  emit vehicleVelocityReceived(vehicleVelocity_);
}


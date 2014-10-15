#include "Data.h"

Data::Data()
{
}

Data::~Data()
{
}

double Data::vehicleVelocity() const
{
  return vehicleVelocity_;
}

void Data::setVehicleVelocity(double vehicleVelocity)
{
  vehicleVelocity_ = vehicleVelocity;
  emit vehicleVelocityReceived(vehicleVelocity_);
}


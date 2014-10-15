#pragma once

#include "I_Data.h"

class Data : public I_Data
{
public:
  Data();
  virtual ~Data();

  double vehicleVelocity() const;
  void setVehicleVelocity(double vehicleVelocity);

private:
  double vehicleVelocity_;
};

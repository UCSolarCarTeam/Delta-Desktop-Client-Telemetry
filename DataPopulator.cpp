#include "DataPopulator.h"
#include "I_TelemetryData.h"
#include "I_DataParser.h"

namespace
{
  enum Ids
  {
    VehicleVelocity = 1 // change this with actual value
  };
}

DataPopulator::DataPopulator(const I_DataParser& dataParser, I_TelemetryData& data)
: dataParser_(dataParser)
, data_(data)
{
  connect(&dataParser, SIGNAL(dataReceived(int, int)), this, SLOT(handleDataReceived(int, int)));
}

void DataPopulator::handleDataReceived(int id, int value)
{
  switch(id)
  {
  case VehicleVelocity:
    data_.setVehicleVelocityKph(value);
    break;
  }
}

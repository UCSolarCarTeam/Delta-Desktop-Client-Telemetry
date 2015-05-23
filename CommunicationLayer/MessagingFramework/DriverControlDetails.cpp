#include "DriverControlDetails.h"
#include "MessageDecodingHelpers.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int motorVelocityIndex = 1;
   const int motorVoltageIndex = 5;
   const int motorCurrentRealIndex = 9;
   const int backEmfIndex = 13;
   const int dpsBoardTemperatureIndex = 17;
   const int dcBusAmpHoursIndex = 21;
   const int odometerIndex = 25;
}

DriverControlDetails::DriverControlDetails(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float DriverControlDetails::motorVelocity() const
{
   return getFloat(messageData_, motorVelocityIndex);
}

float DriverControlDetails::motorVoltage() const
{
   return getFloat(messageData_, motorVoltageIndex);
}

float DriverControlDetails::motorCurrentReal() const
{
   return getFloat(messageData_, motorCurrentRealIndex);
}

float DriverControlDetails::backEmf() const
{
   return getFloat(messageData_, backEmfIndex);
}

float DriverControlDetails::dpsBoardTemperature() const
{
   return getFloat(messageData_, dpsBoardTemperatureIndex);
}

float DriverControlDetails::dcBusAmpHours() const
{
   return getFloat(messageData_, dcBusAmpHoursIndex);
}

float DriverControlDetails::odometer() const
{
   return getFloat(messageData_, odometerIndex);
}

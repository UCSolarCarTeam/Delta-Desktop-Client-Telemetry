#include "BatteryDataMessage.h"
#include "MessageDecodingHelpers.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int BATTERY_VOLTAGE_INDEX = 1;
   const int BATTERY_CURRENT_INDEX = 5;
   const int STATE_OF_CHARGE_INDEX = 9;
   const int BALANCE_SOC_INDEX = 13;
   const int SECONDARY_ERROR_INDEX = 17;
}

BatteryDataMessage::BatteryDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

float BatteryDataMessage::batteryVoltage() const
{
   return getFloat(messageData_, BATTERY_VOLTAGE_INDEX);
}

float BatteryDataMessage::batteryCurrent() const
{
   return getFloat(messageData_, BATTERY_CURRENT_INDEX);
}

float BatteryDataMessage::stateOfCharge() const
{
   return getFloat(messageData_, STATE_OF_CHARGE_INDEX);
}

float BatteryDataMessage::balanceStateOfCharge() const
{
   return getFloat(messageData_, BALANCE_SOC_INDEX);
}

bool BatteryDataMessage::secondaryBatteryUnderVoltage() const
{
   return static_cast<bool>(messageData_.at(SECONDARY_ERROR_INDEX));
}

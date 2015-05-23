#include "FaultsMessage.h"

namespace
{
   const int MOTOR_FAULTS_INDEX = 1;
   const int LIMIT_FAULTS_INDEX = 2;
   const int BATTERY_FAULTS_INDEX = 3;
   const int CAN_RX_ERROR_COUNTS_INDEX = 5;
   const int CAN_TX_ERROR_COUNTS_INDEX = 6;
}

FaultsMessage::FaultsMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

MotorFaults FaultsMessage::motorFaults() const
{
   return MotorFaults(messageData_.at(MOTOR_FAULTS_INDEX));
}

LimitFlags FaultsMessage::limitFlags() const
{
   return LimitFlags(messageData_.at(LIMIT_FAULTS_INDEX));
}

BatteryFaults FaultsMessage::batteryFaults() const
{
   quint16 batteryFaultFlags =
      (messageData_.at(BATTERY_FAULTS_INDEX + 1) << 8)
      | messageData_.at(BATTERY_FAULTS_INDEX);
   return BatteryFaults(batteryFaultFlags);
}

quint8 FaultsMessage::canReceivedErrorCounts() const
{
   return messageData_.at(CAN_RX_ERROR_COUNTS_INDEX);
}

quint8 FaultsMessage::canTransmittedErrorCounts() const
{
   return messageData_.at(CAN_TX_ERROR_COUNTS_INDEX);
}

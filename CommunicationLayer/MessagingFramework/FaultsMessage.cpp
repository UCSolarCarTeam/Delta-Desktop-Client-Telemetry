#include "FaultsMessage.h"
#include "MessageDefines.h"

namespace
{
   const int MOTOR_ONE_FAULTS_INDEX = 1;
   const int MOTOR_ONE_LIMIT_FAULTS_INDEX = 2;
   const int MOTOR_TWO_FAULTS_INDEX = 3;
   const int MOTOR_TWO_LIMIT_FAULTS_INDEX = 4;
   const int BATTERY_FAULTS_INDEX = 5;
   const int CAN_RX_ERROR_COUNTS_INDEX = 7;
   const int CAN_TX_ERROR_COUNTS_INDEX = 8;
}

FaultsMessage::FaultsMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

MotorFaults FaultsMessage::motorOneFaults() const
{
   return MotorFaults(messageData_.at(MOTOR_ONE_FAULTS_INDEX));
}

LimitFlags FaultsMessage::motorOneLimitFlags() const
{
   return LimitFlags(messageData_.at(MOTOR_ONE_LIMIT_FAULTS_INDEX));
}

MotorFaults FaultsMessage::motorTwoFaults() const
{
   return MotorFaults(messageData_.at(MOTOR_TWO_FAULTS_INDEX));
}

LimitFlags FaultsMessage::motorTwoLimitFlags() const
{
   return LimitFlags(messageData_.at(MOTOR_TWO_LIMIT_FAULTS_INDEX));
}

BatteryFaults FaultsMessage::batteryFaults() const
{
   const quint8 upperBatteryFaults = messageData_.at(BATTERY_FAULTS_INDEX + 1);
   const quint8 lowerBatteryFaults = messageData_.at(BATTERY_FAULTS_INDEX);
   quint16 batteryFaultFlags =
      (upperBatteryFaults << 8)
      | lowerBatteryFaults;
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

QString FaultsMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::Faults) + ", ";
   messageString += motorOneFaults().toString() + ", ";
   messageString += motorOneLimitFlags().toString() + ", ";
   messageString += motorTwoFaults().toString() + ", ";
   messageString += motorTwoLimitFlags().toString() + ", ";
   messageString += batteryFaults().toString() + ", ";
   messageString += QString::number(canReceivedErrorCounts()) + ", ";
   messageString += QString::number(canTransmittedErrorCounts()) + ", ";
   return messageString;
}

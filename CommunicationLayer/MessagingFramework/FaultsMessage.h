#pragma once

#include <QByteArray>
#include <QString>
#include "BatteryFaults.h"
#include "LimitFlags.h"
#include "MotorFaults.h"

class FaultsMessage
{
public:
   FaultsMessage(const QByteArray& messageData);

   MotorFaults motorOneFaults() const;
   LimitFlags motorOneLimitFlags() const;
   MotorFaults motorTwoFaults() const;
   LimitFlags motorTwoLimitFlags() const;
   BatteryFaults batteryFaults() const;

   quint8 canReceivedErrorCounts() const;
   quint8 canTransmittedErrorCounts() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};

#pragma once

#include <QByteArray>
#include "BatteryFaults.h"
#include "LimitFlags.h"
#include "MotorFaults.h"

class FaultsMessage
{
public:
   FaultsMessage(const QByteArray& messageData);

   MotorFaults motorFaults() const;
   LimitFlags limitFlags() const;
   BatteryFaults batteryFaults() const;

   quint8 canReceivedErrorCounts() const;
   quint8 canTransmittedErrorCounts() const;

private:
   const QByteArray messageData_;
};

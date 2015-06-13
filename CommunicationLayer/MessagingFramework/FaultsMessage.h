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

   MotorFaults motorFaults() const;
   LimitFlags limitFlags() const;
   BatteryFaults batteryFaults() const;

   quint8 canReceivedErrorCounts() const;
   quint8 canTransmittedErrorCounts() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};

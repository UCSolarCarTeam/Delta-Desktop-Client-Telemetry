#pragma once

#include <QByteArray>

class BatteryDataMessage
{
public:
   BatteryDataMessage(const QByteArray& messageData);

   float batteryVoltage() const;
   float batteryCurrent() const;
   float stateOfCharge() const;
   float balanceStateOfCharge() const;
   bool secondaryBatteryUnderVoltage() const;

private:
   const QByteArray messageData_;
};

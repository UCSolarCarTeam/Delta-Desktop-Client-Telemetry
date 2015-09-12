#pragma once

#include <QByteArray>
#include <QString>

class BatteryDataMessage
{
public:
   BatteryDataMessage(const QByteArray& messageData);

   float batteryVoltage() const;
   float batteryCurrent() const;
   float stateOfCharge() const;
   float balanceStateOfCharge() const;
   bool secondaryBatteryUnderVoltage() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};

#pragma once

#include <QtCore>

class MotorFaults
{
public:
   MotorFaults(quint8 flags);

   bool hardwareOverCurrent() const;
   bool softwareOverCurrent() const;
   bool dcBusOverVoltage() const;
   bool badMotorPositionHallSequence() const;
   bool watchdogCausedLastReset() const;
   bool configReadError() const;
   bool railUnderVoltageLockOut() const;
   bool desaturationFault() const;

   bool operator==(const MotorFaults& other) const;

private:
   quint8 flags_;
};

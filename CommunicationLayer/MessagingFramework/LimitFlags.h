#pragma once

#include <QString>

class LimitFlags
{
public:
   LimitFlags(quint8 flags);

   bool outputVoltagePwmLimit() const;
   bool motorCurrentLimit() const;
   bool velocityLimit() const;
   bool busCurrentLimit() const;
   bool busVoltageUpperLimit() const;
   bool busVoltageLowerLimit() const;
   bool ipmOrMotorTelemetryLimit() const;

   bool operator==(const LimitFlags& other) const;
   QString toString() const;

private:
   quint8 flags_;
};

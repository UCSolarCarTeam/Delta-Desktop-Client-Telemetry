#pragma once

#include <QString>

class BatteryFaults
{
public:
   BatteryFaults(quint16 flags);

   bool cellOverVoltage() const;
   bool cellUnderVoltage() const;
   bool cellOverTemperature() const;
   bool measurementUntrusted() const;
   bool cmuCommTimeout() const;
   bool vehicleCommTimeout() const;
   bool bmuIsInSetupMode() const;
   bool cmuCanBusPowerStatus() const;
   bool packIsolationTestFailure() const;
   bool softwareOverCurrentMeasured() const;
   bool canSupplyIsLow() const;
   bool contactorIsStuck() const;
   bool cmuDetectedExtraCellPresent() const;

   bool operator==(const BatteryFaults& other) const;
   QString toString() const;

private:
   quint16 flags_;
};

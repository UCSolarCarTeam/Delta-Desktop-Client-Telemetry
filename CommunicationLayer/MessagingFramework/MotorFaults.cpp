#include "MotorFaults.h"

namespace
{
   const quint8 HARDWARE_OVER_CURRENT_MASK = 0x01;
   const quint8 SOFTWARE_OVER_CURRENT_MASK = 0x02;
   const quint8 DC_BUS_OVER_VOLTAGE_MASK = 0x04;
   const quint8 BAD_MOTOR_POS_HALL_MASK = 0x08;
   const quint8 WATCHDOG_CAUSED_LAST_RESET_MASK = 0x10;
   const quint8 CONFIG_READ_ERROR_MASK = 0x20;
   const quint8 RAIL_UNDER_VOLT_MASK = 0x40;
   const quint8 DESATURATION_FAULT_MASK = 0x80;
}

MotorFaults::MotorFaults(quint8 flags)
: flags_(flags)
{
}

bool MotorFaults::hardwareOverCurrent() const
{
   return static_cast<bool>(flags_ & HARDWARE_OVER_CURRENT_MASK);
}

bool MotorFaults::softwareOverCurrent() const
{
   return static_cast<bool>(flags_ & SOFTWARE_OVER_CURRENT_MASK);
}

bool MotorFaults::dcBusOverVoltage() const
{
   return static_cast<bool>(flags_ & DC_BUS_OVER_VOLTAGE_MASK);
}

bool MotorFaults::badMotorPositionHallSequence() const
{
   return static_cast<bool>(flags_ & BAD_MOTOR_POS_HALL_MASK);
}

bool MotorFaults::watchdogCausedLastReset() const
{
   return static_cast<bool>(flags_ & WATCHDOG_CAUSED_LAST_RESET_MASK);
}

bool MotorFaults::configReadError() const
{
   return static_cast<bool>(flags_ & CONFIG_READ_ERROR_MASK);
}

bool MotorFaults::railUnderVoltageLockOut() const
{
   return static_cast<bool>(flags_ & RAIL_UNDER_VOLT_MASK);
}

bool MotorFaults::desaturationFault() const
{
   return static_cast<bool>(flags_ & DESATURATION_FAULT_MASK);
}

bool MotorFaults::operator==(const MotorFaults& other) const
{
   return flags_ == other.flags_;
}

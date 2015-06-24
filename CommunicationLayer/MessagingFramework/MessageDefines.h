#pragma once

namespace MessageDefines
{
   enum Type
   {
      KeyDriverControlTelemetry = 1,
      DriverControlDetails = 2,
      Faults = 3,
      BatteryData = 4,
      CmuData = 5,
      MpptData = 6
   };

   int getLengthForMessage(Type type);
}

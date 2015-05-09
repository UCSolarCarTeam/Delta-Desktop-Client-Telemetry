#include "MessageDefines.h"

namespace
{
   const int KEY_DRIVER_CONTROL_LENGTH = 22;
   const int DRIVER_CONTROL_DETAILS_LENGTH = 30;
   const int FAULTS_LENGTH = 7;
   const int BATTERY_DATA_LENGTH = 18;
   const int CMU_DATA_LENGTH = 43;
}

int MessageDefines::getLengthForMessage(MessageDefines::Type type)
{
   switch(type)
   {
   case KeyDriverControlTelemetry:
      return KEY_DRIVER_CONTROL_LENGTH;
   case DriverControlDetails:
      return DRIVER_CONTROL_DETAILS_LENGTH;
   case Faults:
      return FAULTS_LENGTH;
   case BatteryData:
      return BATTERY_DATA_LENGTH;
   case CmuData:
      return CMU_DATA_LENGTH;
   default:
      return 0;
   }
}

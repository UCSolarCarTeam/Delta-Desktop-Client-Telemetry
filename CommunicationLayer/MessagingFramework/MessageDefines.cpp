#include "MessageDefines.h"

namespace
{
   const int KEY_DRIVER_CONTROL_LENGTH = 21;
   const int DRIVER_CONTROL_DETAILS_LENGTH = 29;
   const int FAULTS_LENGTH = 7;
   const int BATTERY_DATA_LENGTH = 18;
   const int CMU_DATA_LENGTH = 42;
   const int MPPT_DATA_LENGTH = 21;
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
   case MpptData:
      return MPPT_DATA_LENGTH;
   default:
      return 0;
   }
}

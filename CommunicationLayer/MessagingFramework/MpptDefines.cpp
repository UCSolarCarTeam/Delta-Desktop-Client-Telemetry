#include "MpptDefines.h"

QString MpptDefines::typeToString(Type type)
{
   switch (type)
   {
   case Helianthus:
      return "Helianthus";
   case Dilithium:
      return "Dilithium";
   default:
      return "Invalid type";
   }
}

QString MpptDefines::modeToString(Mode mode)
{
   switch (mode)
   {
   case Static:
      return "Static";
   case Dynamic:
      return "Dynamic";
   case IvTrace:
      return "IvTrace";
   case Open:
      return "Open";
   default:
      return "Invalid mode";
   }
}


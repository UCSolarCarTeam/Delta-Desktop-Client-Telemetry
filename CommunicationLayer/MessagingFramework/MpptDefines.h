#pragma once

#include <QString>

namespace MpptDefines
{
   enum Type
   {
      Helianthus = 0,
      Dilithium = 1
   };

   enum Mode
   {
      Static = 0,
      Dynamic = 1,
      IvTrace = 2,
      Open = 3,
      Invalid = 4
   };

   QString typeToString(Type type);
   QString modeToString(Mode mode);
}

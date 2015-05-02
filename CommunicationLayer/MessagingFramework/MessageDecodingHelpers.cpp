#include "MessageDecodingHelpers.h"

namespace
{
   const int NUMBER_OF_BYTES_IN_FLOAT = 4;

   union FloatCharTranslator
   {
      float floatData;
      char charData[NUMBER_OF_BYTES_IN_FLOAT];
   };
}

float MessageDecodingHelpers::getFloat(
   const QByteArray& data, int startIndex)
{
   FloatCharTranslator dataUnion;
   for (int i = 0; i < NUMBER_OF_BYTES_IN_FLOAT; i++)
   {
      dataUnion.charData[i] = data.at(i + startIndex);
   }

   return dataUnion.floatData;
}

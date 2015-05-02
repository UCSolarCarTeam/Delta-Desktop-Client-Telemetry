#pragma once

#include <QByteArray>

namespace MessageDecodingHelpers
{
   float getFloat(const QByteArray& data, int startIndex);
}

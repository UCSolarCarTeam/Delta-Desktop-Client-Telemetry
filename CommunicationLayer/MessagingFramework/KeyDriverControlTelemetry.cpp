#include "KeyDriverControlTelemetry.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int setSpeedIndex = 1;
   const int setCurrentIndex = 5;
   const int busCurrentIndex = 9;
   const int busVoltageIndex = 13;
   const int speedIndex = 17;
}

KeyDriverControlTelemetry::KeyDriverControlTelemetry(
   const QByteArray& messageData)
: messageData_(messageData)
{
}

float KeyDriverControlTelemetry::setSpeed() const
{
   return getFloat(messageData_, setSpeedIndex);
}

float KeyDriverControlTelemetry::setCurrent() const
{
   return getFloat(messageData_, setCurrentIndex);
}

float KeyDriverControlTelemetry::busCurrent() const
{
   return getFloat(messageData_, busCurrentIndex);
}

float KeyDriverControlTelemetry::busVoltage() const
{
   return getFloat(messageData_, busVoltageIndex);
}

float KeyDriverControlTelemetry::speed() const
{
   return getFloat(messageData_, speedIndex);
}

QString KeyDriverControlTelemetry::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::KeyDriverControlTelemetry) + ", ";
   messageString += QString::number(setSpeed()) + ", ";
   messageString += QString::number(setCurrent()) + ", ";
   messageString += QString::number(busCurrent()) + ", ";
   messageString += QString::number(busVoltage()) + ", ";
   messageString += QString::number(speed()) + ", ";
   return messageString;
}

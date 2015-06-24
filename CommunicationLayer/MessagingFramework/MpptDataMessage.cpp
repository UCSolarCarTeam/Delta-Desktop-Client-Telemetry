#include "MpptDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int MPPT_NUMBER_INDEX = 1;
   const int TYPE_INDEX = 2;
   const int VALIDITY_INDEX = 3;
   const int VOLTAGE_IN_INDEX = 4;
   const int CURRENT_IN_INDEX = 8;
   const int VOLTAGE_OUT_INDEX = 12;
   const int CURRENT_OUT_INDEX = 16;
   const int MODE_INDEX = 20;

   const quint8 VOLTAGE_IN_MASK = 0x01;
   const quint8 CURRENT_IN_MASK = 0x02;
   const quint8 VOLTAGE_OUT_MASK = 0x04;
   const quint8 CURRENT_OUT_MASK = 0x08;
   const quint8 MODE_MASK = 0x10;
}

MpptDataMessage::MpptDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

quint8 MpptDataMessage::mpptNumber() const
{
   return messageData_.at(MPPT_NUMBER_INDEX);
}

MpptDefines::Type MpptDataMessage::type() const
{
   return static_cast<MpptDefines::Type>(messageData_.at(TYPE_INDEX));
}

bool MpptDataMessage::isVoltageInValid() const
{
   return validityFlags() & VOLTAGE_IN_MASK;
}

float MpptDataMessage::voltageIn() const
{
   return getFloat(messageData_, VOLTAGE_IN_INDEX);
}

bool MpptDataMessage::isCurrentInValid() const
{
   return validityFlags() & CURRENT_IN_MASK;
}

float MpptDataMessage::currentIn() const
{
   return getFloat(messageData_, CURRENT_IN_INDEX);
}

bool MpptDataMessage::isVoltageOutValid() const
{
   return validityFlags() & VOLTAGE_OUT_MASK;
}

float MpptDataMessage::voltageOut() const
{
   return getFloat(messageData_, VOLTAGE_OUT_INDEX);
}

bool MpptDataMessage::isCurrentOutValid() const
{
   return validityFlags() & CURRENT_OUT_MASK;
}

float MpptDataMessage::currentOut() const
{
   return getFloat(messageData_, CURRENT_OUT_INDEX);
}

bool MpptDataMessage::isModeValid() const
{
   return validityFlags() & MODE_MASK;
}

MpptDefines::Mode MpptDataMessage::mode() const
{
   return static_cast<MpptDefines::Mode>(messageData_.at(MODE_INDEX));
}

QString MpptDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::MpptData) + ", ";
   messageString += MpptDefines::typeToString(type()) + ", ";
   messageString += QString::number(validityFlags(), 16) + ", ";
   messageString += QString::number(voltageIn()) + ", ";
   messageString += QString::number(currentIn()) + ", ";
   messageString += QString::number(voltageOut()) + ", ";
   messageString += QString::number(currentOut()) + ", ";
   messageString += MpptDefines::modeToString(mode()) + ", ";
   return messageString;
}

quint8 MpptDataMessage::validityFlags() const
{
   return messageData_.at(VALIDITY_INDEX);
}

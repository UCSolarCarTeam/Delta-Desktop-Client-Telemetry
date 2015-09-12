#include "CmuDataMessage.h"
#include "MessageDecodingHelpers.h"
#include "MessageDefines.h"

using namespace MessageDecodingHelpers;

namespace
{
   const int CELL_NUMBER_INDEX = 1;
   const int PCB_TEMPERATURE_INDEX = 2;
   const int CELL_TEMPERATURE_INDEX = 6;
   const int CELL_VOLTAGE_0_INDEX = 10;
   const int NUMBER_OF_CELLS = 8;
   const int NUMBER_OF_BYTES_IN_FLOAT = 4;
}

CmuDataMessage::CmuDataMessage(const QByteArray& messageData)
: messageData_(messageData)
{
}

quint8 CmuDataMessage::cellNumber() const
{
   return messageData_.at(CELL_NUMBER_INDEX);
}

float CmuDataMessage::pcbTemperature() const
{
   return getFloat(messageData_, PCB_TEMPERATURE_INDEX);
}

float CmuDataMessage::cellTemperature() const
{
   return getFloat(messageData_, CELL_TEMPERATURE_INDEX);
}

QList<float> CmuDataMessage::cellVoltages() const
{
   QList<float> cellVoltagesData;
   for (int i = 0; i < NUMBER_OF_CELLS; i++)
   {
      const int indexOfCell = CELL_VOLTAGE_0_INDEX + i * NUMBER_OF_BYTES_IN_FLOAT;
      cellVoltagesData << getFloat(messageData_, indexOfCell);
   }
   return cellVoltagesData;
}

QString CmuDataMessage::toString() const
{
   QString messageString;
   messageString += QString::number(MessageDefines::CmuData) + ", ";
   messageString += QString::number(cellNumber()) + ", ";
   messageString += QString::number(pcbTemperature()) + ", ";
   messageString += QString::number(cellTemperature()) + ", ";
   foreach(const float& cellVoltage, cellVoltages())
   {
      messageString += QString::number(cellVoltage) + ", ";
   }
   return messageString;
}

#pragma once

#include <QByteArray>
#include <QList>

class CmuDataMessage
{
public:
   CmuDataMessage(const QByteArray& messageData);

   int cellNumber() const;
   float pcbTemperature() const;
   float cellTemperature() const;
   QList<float> cellVoltages() const;

private:
   const QByteArray messageData_;
};

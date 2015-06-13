#pragma once

#include <QByteArray>
#include <QList>
#include <QString>

class CmuDataMessage
{
public:
   CmuDataMessage(const QByteArray& messageData);

   quint8 cellNumber() const;
   float pcbTemperature() const;
   float cellTemperature() const;
   QList<float> cellVoltages() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};

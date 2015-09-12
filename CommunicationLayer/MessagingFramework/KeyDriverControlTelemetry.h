#pragma once

#include <QByteArray>
#include <QString>

class KeyDriverControlTelemetry
{
public:
   KeyDriverControlTelemetry(const QByteArray& messageData);

   float setSpeed() const;
   float setCurrent() const;
   float busCurrent() const;
   float busVoltage() const;
   float speed() const;

   QString toString() const;

private:
   const QByteArray messageData_;
};

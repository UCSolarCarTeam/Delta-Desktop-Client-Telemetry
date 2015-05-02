#pragma once

#include <QByteArray>

class KeyDriverControlTelemetry
{
public:
   KeyDriverControlTelemetry(const QByteArray& messageData);

   float setSpeed() const;
   float setCurrent() const;
   float busCurrent() const;
   float busVoltage() const;
   float speed() const;

private:
   const QByteArray messageData_;
};

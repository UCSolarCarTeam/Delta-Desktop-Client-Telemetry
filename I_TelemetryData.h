#pragma once

#include <QObject>

class I_TelemetryData : public QObject
{
  Q_OBJECT
public:
   virtual ~I_TelemetryData() {}

   virtual double vehicleVelocity() const = 0;


   virtual void setVehicleVelocity(double vehicleVelocity) = 0;

signals:
   void vehicleVelocityReceived(double vehicleVelocity);

};


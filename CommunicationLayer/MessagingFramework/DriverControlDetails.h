#pragma once

#include <QByteArray>

class DriverControlDetails
{
public:
   DriverControlDetails(const QByteArray& messageData);

   float motorVelocity() const;
   float motorVoltage() const;
   float motorCurrentReal() const;
   float backEmf() const;
   float dpsBoardTemperature() const;
   float dcBusAmpHours() const;
   float odometer() const;

private:
   const QByteArray messageData_;
};

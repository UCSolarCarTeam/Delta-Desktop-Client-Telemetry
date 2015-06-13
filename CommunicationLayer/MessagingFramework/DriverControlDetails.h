#pragma once

#include <QByteArray>
#include <QString>

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

   QString toString() const;

private:
   const QByteArray messageData_;
};

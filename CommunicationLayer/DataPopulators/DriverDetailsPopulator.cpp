#include "DriverDetailsPopulator.h"

DriverDetailsPopulator::DriverDetailsPopulator(I_PacketDecoder& packetDecoder,
                                    I_VehicleData& vehicleData,
                                    I_PowerData& powerData)
: packetDecoder_(packetDecoder)
, vehicleData_(vehicleData)
, powerData_(powerData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const DriverControlDetails)),
          this, SLOT(populateData(const DriverControlDetails)));
}

void DriverDetailsPopulator::populateData(const DriverControlDetails message)
{
   vehicleData_.setMotorVelocityRpm(message.motorVelocity());
   powerData_.setMotorVoltageReal(message.motorVoltage());
   powerData_.setMotorCurrentReal(message.motorCurrentReal());
   powerData_.setBackEmfImaginary(message.backEmf());
   vehicleData_.setDspBoardTemp(message.dpsBoardTemperature());
   powerData_.setDcBusAmpHours(message.dcBusAmpHours());
   //message.odometer()
}



#include "KeyDriverControlPopulator.h"

KeyDriverControlPopulator::KeyDriverControlPopulator(I_PacketDecoder& packetDecoder,
                                        I_VehicleData& vehicleData,
                                        I_PowerData& powerData)
: packetDecoder_(packetDecoder)
, vehicleData_(vehicleData)
, powerData_(powerData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const KeyDriverControlTelemetry)),
         this, SLOT(populateData(const KeyDriverControlTelemetry)));
}

void KeyDriverControlPopulator::populateData(const KeyDriverControlTelemetry message)
{
   vehicleData_.setDriverSetSpeedMetersPerSecond(message.setSpeed());
   vehicleData_.setDriverSetCurrent(message.setCurrent());
   vehicleData_.setVehicleVelocityMetersPerSecond(message.speed());
   powerData_.setBusCurrentA(message.busCurrent());
   powerData_.setBusVoltage(message.busVoltage());
}

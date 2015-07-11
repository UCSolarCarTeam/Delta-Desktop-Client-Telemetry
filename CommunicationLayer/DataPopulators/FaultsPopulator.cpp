#include "FaultsPopulator.h"

FaultsPopulator::FaultsPopulator(I_PacketDecoder& packetDecoder,
                         I_FaultsData& faultsData)
: packetDecoder_(packetDecoder)
, faultsData_(faultsData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const FaultsMessage&)),
         this, SLOT(populateData(const FaultsMessage&)));
}

void FaultsPopulator::populateData(const FaultsMessage& message)
{
   faultsData_.setMotorOneFaults(message.motorOneFaults());
   faultsData_.setMotorOneLimitFlags(message.motorOneLimitFlags());
   faultsData_.setMotorTwoFaults(message.motorTwoFaults());
   faultsData_.setMotorTwoLimitFlags(message.motorTwoLimitFlags());
   faultsData_.setBatteryFaults(message.batteryFaults());
}

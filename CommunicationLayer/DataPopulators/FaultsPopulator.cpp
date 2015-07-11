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
   faultsData_.setMotorFaults(message.motorOneFaults());
   faultsData_.setLimitFlags(message.motorOneLimitFlags());
   faultsData_.setBatteryFaults(message.batteryFaults());
}

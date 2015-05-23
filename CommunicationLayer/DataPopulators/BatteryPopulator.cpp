#include "BatteryPopulator.h"

BatteryPopulator::BatteryPopulator(I_PacketDecoder& packetDecoder,
                           I_BatteryData& batteryData)
: packetDecoder_(packetDecoder)
, batteryData_(batteryData)
{
   connect(&packetDecoder_, SIGNAL(packetDecoded(const BatteryDataMessage)),
         this, SLOT(populateData(const BatteryDataMessage)));
}

void BatteryPopulator::populateData(const BatteryDataMessage message)
{
   batteryData_.setBatteryVoltage(message.batteryVoltage());
   batteryData_.setBatteryCurrent(message.batteryCurrent());
   // batteryData_.set***SOMETHINGHERE***(message.stateOfCharge());
   // batteryData_.set***SOMETHINGHERE***(message.balanceStateOfCharge());
   // batteryData_.set***SOMETHINGHERE***(message.secondaryBatteryUnderVoltage());
}

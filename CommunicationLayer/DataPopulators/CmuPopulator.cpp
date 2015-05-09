#include "CmuPopulator.h"

CmuPopulator::CmuPopulator(I_PacketDecoder& packetDecoder,
                           I_BatteryData& batteryData)
: packetDecoder_(packetDecoder)
, batteryData_(batteryData)
{
    connect(&packetDecoder_, SIGNAL(packetDecoded(const CmuDataMessage)),
            this, SLOT(populateData(const CmuDataMessage)));
}

void CmuPopulator::populateData(const CmuDataMessage message)
{
    switch(message.cellNumber()){ 
        case 0:
            batteryData_.setMod0PcbTemperature(message.pcbTemperature());
            batteryData_.setMod0CellTemperature(message.cellTemperature());
            batteryData_.setMod0CellVoltage0(message.cellVoltages()[0]);
            batteryData_.setMod0CellVoltage1(message.cellVoltages()[1]);
            batteryData_.setMod0CellVoltage2(message.cellVoltages()[2]);
            batteryData_.setMod0CellVoltage3(message.cellVoltages()[3]);
            batteryData_.setMod0CellVoltage4(message.cellVoltages()[4]);
            batteryData_.setMod0CellVoltage5(message.cellVoltages()[5]);
            batteryData_.setMod0CellVoltage6(message.cellVoltages()[6]);
            batteryData_.setMod0CellVoltage7(message.cellVoltages()[7]);
            break;
        case 1:
            batteryData_.setMod1PcbTemperature(message.pcbTemperature());
            batteryData_.setMod1CellTemperature(message.cellTemperature());
            batteryData_.setMod1CellVoltage0(message.cellVoltages()[0]);
            batteryData_.setMod1CellVoltage1(message.cellVoltages()[1]);
            batteryData_.setMod1CellVoltage2(message.cellVoltages()[2]);
            batteryData_.setMod1CellVoltage3(message.cellVoltages()[3]);
            batteryData_.setMod1CellVoltage4(message.cellVoltages()[4]);
            batteryData_.setMod1CellVoltage5(message.cellVoltages()[5]);
            batteryData_.setMod1CellVoltage6(message.cellVoltages()[6]);
            batteryData_.setMod1CellVoltage7(message.cellVoltages()[7]);
            break;
        case 2:
            batteryData_.setMod2PcbTemperature(message.pcbTemperature());
            batteryData_.setMod2CellTemperature(message.cellTemperature());
            batteryData_.setMod2CellVoltage0(message.cellVoltages()[0]);
            batteryData_.setMod2CellVoltage1(message.cellVoltages()[1]);
            batteryData_.setMod2CellVoltage2(message.cellVoltages()[2]);
            batteryData_.setMod2CellVoltage3(message.cellVoltages()[3]);
            batteryData_.setMod2CellVoltage4(message.cellVoltages()[4]);
            batteryData_.setMod2CellVoltage5(message.cellVoltages()[5]);
            batteryData_.setMod2CellVoltage6(message.cellVoltages()[6]);
            batteryData_.setMod2CellVoltage7(message.cellVoltages()[7]);
            break;
        case 3:
            batteryData_.setMod3PcbTemperature(message.pcbTemperature());
            batteryData_.setMod3CellTemperature(message.cellTemperature());
            batteryData_.setMod3CellVoltage0(message.cellVoltages()[0]);
            batteryData_.setMod3CellVoltage1(message.cellVoltages()[1]);
            batteryData_.setMod3CellVoltage2(message.cellVoltages()[2]);
            batteryData_.setMod3CellVoltage3(message.cellVoltages()[3]);
            batteryData_.setMod3CellVoltage4(message.cellVoltages()[4]);
            batteryData_.setMod3CellVoltage5(message.cellVoltages()[5]);
            batteryData_.setMod3CellVoltage6(message.cellVoltages()[6]);
            batteryData_.setMod3CellVoltage7(message.cellVoltages()[7]);
            break;
    }

}
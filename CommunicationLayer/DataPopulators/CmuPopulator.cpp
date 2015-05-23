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
            batteryData_.setMod0CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 1:
            batteryData_.setMod1PcbTemperature(message.pcbTemperature());
            batteryData_.setMod1CellTemperature(message.cellTemperature());
            batteryData_.setMod1CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 2:
            batteryData_.setMod2PcbTemperature(message.pcbTemperature());
            batteryData_.setMod2CellTemperature(message.cellTemperature());
            batteryData_.setMod2CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
        case 3:
            batteryData_.setMod3PcbTemperature(message.pcbTemperature());
            batteryData_.setMod3CellTemperature(message.cellTemperature());
            batteryData_.setMod3CellVoltages(
                convertFloatListToDouble(message.cellVoltages()));
            break;
    }

}

QList<double> CmuPopulator::convertFloatListToDouble(QList<float> floatList)
{
    QList<double> doubleList;
    for(int i = 0; i < floatList.length(); i++)
    {
        doubleList.append((double)floatList[i]);
    }
    return doubleList;
}

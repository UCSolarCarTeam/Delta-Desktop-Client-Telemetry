#include <QtSerialPort/QSerialPort>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "ConnectionService/SerialPortConnectionService.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverDetailsPopulator.h"
#include "DataPopulators/FaultsPopulator.h"
#include "DataPopulators/KeyDriverControlPopulator.h"
#include "PacketDecoder/PacketDecoder.h"
#include "PacketSynchronizer/PacketSynchronizer.h"

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer)
: port_(new QSerialPort)
, connectionService_(new SerialPortConnectionService(*port_))
, packetSynchronizer_(new PacketSynchronizer(
   *port_,
   *connectionService_))
, packetDecoder_(new PacketDecoder(
   *packetSynchronizer_))
, keyDriverControlPopulator_(new KeyDriverControlPopulator(
   *packetDecoder_,
   dataContainer.vehicleData(),
   dataContainer.powerData()))
, driverDetailsPopulator_(new DriverDetailsPopulator(
   *packetDecoder_,
   dataContainer.vehicleData(),
   dataContainer.powerData()))
, faultsPopulator_(new FaultsPopulator(
   *packetDecoder_,
   dataContainer.faultsData()))
, batteryPopulator_(new BatteryPopulator(
   *packetDecoder_,
   dataContainer.batteryData()))
, cmuPopulator_(new CmuPopulator(
   *packetDecoder_,
   dataContainer.batteryData()))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

I_ConnectionService& CommunicationContainer::connectionService()
{
   return *connectionService_;
}

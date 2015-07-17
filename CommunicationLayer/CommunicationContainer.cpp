#include <QtSerialPort/QSerialPort>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "ConnectionService/RadioConnectionService.h"
#include "DataPopulators/BatteryPopulator.h"
#include "DataPopulators/CmuPopulator.h"
#include "DataPopulators/DriverDetailsPopulator.h"
#include "DataPopulators/FaultsPopulator.h"
#include "DataPopulators/KeyDriverControlPopulator.h"
#include "DataPopulators/MpptPopulator.h"
#include "PacketChecksumChecker/PacketChecksumChecker.h"
#include "PacketDecoder/PacketDecoder.h"
#include "PacketSynchronizer/PacketSynchronizer.h"
#include "PacketUnstuffer/PacketUnstuffer.h"

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer)
: port_(new QSerialPort)
, connectionService_(new RadioConnectionService(*port_))
, packetSynchronizer_(new PacketSynchronizer(
   *port_,
   *connectionService_))
, packetUnstuffer_(new PacketUnstuffer(
   *packetSynchronizer_))
, packetChecksumChecker_(new PacketChecksumChecker(
   *packetUnstuffer_))
, packetDecoder_(new PacketDecoder(
   *packetChecksumChecker_))
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
, mpptPopulator_(new MpptPopulator(
   *packetDecoder_,
   dataContainer.mpptData()))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

I_ConnectionService& CommunicationContainer::connectionService()
{
   return *connectionService_;
}

I_PacketSynchronizer& CommunicationContainer::packetSynchronizer()
{
   return *packetSynchronizer_;
}

I_DataInjectionService& CommunicationContainer::dataInjectionService()
{
   return *packetUnstuffer_;
}

I_PacketDecoder& CommunicationContainer::packetDecoder()
{
   return *packetDecoder_;
}

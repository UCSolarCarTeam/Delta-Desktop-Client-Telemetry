#include <QtSerialPort/QSerialPort>
#include <QUdpSocket>

#include "../DataLayer/DataContainer.h"
#include "CommunicationContainer.h"
#include "CommDeviceControl/ConnectionController.h"
#include "CommDeviceControl/CommDeviceManager.h"
#include "CommDeviceControl/RadioConnectionService.h"
#include "CommDeviceControl/UdpConnectionService.h"
#include "CommDeviceControl/UdpMessageForwarder.h"
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

class CommunicationContainerPrivate
{
public:
   CommunicationContainerPrivate(DataContainer& dataContainer)
   : radioConnectionService(serialPort)
   , udpConnectionService(udpSocket)
   , commDeviceManager(
      udpSocket,
      serialPort)
   , connectionController(
      radioConnectionService,
      udpConnectionService)
   , messageForwarder(commDeviceManager)
   , packetSynchronizer(commDeviceManager)
   , packetUnstuffer(packetSynchronizer)
   , packetChecksumChecker(packetUnstuffer)
   , packetDecoder(packetChecksumChecker)
   , keyDriverControlPopulator(
      packetDecoder,
      dataContainer.vehicleData(),
      dataContainer.powerData())
   , driverDetailsPopulator(
      packetDecoder,
      dataContainer.vehicleData(),
      dataContainer.powerData())
   , faultsPopulator(
      packetDecoder,
      dataContainer.faultsData())
   , batteryPopulator(
      packetDecoder,
      dataContainer.batteryData())
   , cmuPopulator(
      packetDecoder,
      dataContainer.batteryData())
   , mpptPopulator(
      packetDecoder,
      dataContainer.mpptData())
   {
   }

   QSerialPort serialPort;
   QUdpSocket udpSocket;
   RadioConnectionService radioConnectionService;
   UdpConnectionService udpConnectionService;
   CommDeviceManager commDeviceManager;
   ConnectionController connectionController;
   UdpMessageForwarder messageForwarder;
   PacketSynchronizer packetSynchronizer;
   PacketUnstuffer packetUnstuffer;
   PacketChecksumChecker packetChecksumChecker;
   PacketDecoder packetDecoder;
   KeyDriverControlPopulator keyDriverControlPopulator;
   DriverDetailsPopulator driverDetailsPopulator;
   FaultsPopulator faultsPopulator;
   BatteryPopulator batteryPopulator;
   CmuPopulator cmuPopulator;
   MpptPopulator mpptPopulator;
};

CommunicationContainer::CommunicationContainer(DataContainer& dataContainer)
: impl_(new CommunicationContainerPrivate(dataContainer))
{
}

CommunicationContainer::~CommunicationContainer()
{
}

UdpMessageForwarder& CommunicationContainer::messageForwarder()
{
   return impl_->messageForwarder;
}

ConnectionController& CommunicationContainer::connectionController()
{
   return impl_->connectionController;
}

UdpConnectionService& CommunicationContainer::udpConnectionService()
{
   return impl_->udpConnectionService;
}

RadioConnectionService& CommunicationContainer::radioConnectionService()
{
   return impl_->radioConnectionService;
}

I_PacketSynchronizer& CommunicationContainer::packetSynchronizer()
{
   return impl_->packetSynchronizer;
}

I_DataInjectionService& CommunicationContainer::dataInjectionService()
{
   return impl_->packetUnstuffer;
}

I_PacketDecoder& CommunicationContainer::packetDecoder()
{
   return impl_->packetDecoder;
}

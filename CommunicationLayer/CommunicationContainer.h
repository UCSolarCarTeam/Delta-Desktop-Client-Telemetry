#pragma once

#include <QScopedPointer>
class QSerialPort;

class BatteryPopulator;
class CmuPopulator;
class DataContainer;
class DriverDetailsPopulator;
class FaultsPopulator;
class I_ConnectionService;
class I_PacketDecoder;
class I_PacketSynchronizer;
class KeyDriverControlPopulator;
class PacketChecksumChecker;
class PacketDecoder;
class PacketSynchronizer;
class PacketUnstuffer;
class MpptPopulator;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   I_ConnectionService& connectionService();
   I_PacketSynchronizer& packetSynchronizer();
   I_PacketDecoder& packetDecoder();

private:
   QScopedPointer<QSerialPort> port_;
   QScopedPointer<I_ConnectionService> connectionService_;
   QScopedPointer<PacketSynchronizer> packetSynchronizer_;
   QScopedPointer<PacketUnstuffer> packetUnstuffer_;
   QScopedPointer<PacketChecksumChecker> packetChecksumChecker_;
   QScopedPointer<PacketDecoder> packetDecoder_;
   QScopedPointer<KeyDriverControlPopulator> keyDriverControlPopulator_;
   QScopedPointer<DriverDetailsPopulator> driverDetailsPopulator_;
   QScopedPointer<FaultsPopulator> faultsPopulator_;
   QScopedPointer<BatteryPopulator> batteryPopulator_;
   QScopedPointer<CmuPopulator> cmuPopulator_;
   QScopedPointer<MpptPopulator> mpptPopulator_;
};

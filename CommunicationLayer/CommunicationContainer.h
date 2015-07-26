#pragma once

#include <QScopedPointer>

class CommunicationContainerPrivate;
class ConnectionController;
class DataContainer;
class I_DataInjectionService;
class I_PacketDecoder;
class I_PacketSynchronizer;
class RadioConnectionService;
class UdpConnectionService;
class UdpMessageForwarder;

class CommunicationContainer
{
public:
   explicit CommunicationContainer(DataContainer& dataContainer);
   ~CommunicationContainer();

   UdpMessageForwarder& messageForwarder();
   ConnectionController& connectionController();
   UdpConnectionService& udpConnectionService();
   RadioConnectionService& radioConnectionService();
   I_PacketSynchronizer& packetSynchronizer();
   I_DataInjectionService& dataInjectionService();
   I_PacketDecoder& packetDecoder();

private:
   // This is using the PIMPL design pattern, refer to http://c2.com/cgi/wiki?PimplIdiom
   QScopedPointer<CommunicationContainerPrivate> impl_;
};

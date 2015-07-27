#include <QHostAddress>

  #include "BusinessLayer/CommunicationsMonitoringService/CommunicationsMonitoringService.h"
  #include "CommunicationLayer/CommDeviceControl/CommDeviceManager.h"
  #include "CommunicationLayer/CommDeviceControl/ConnectionController.h"
  #include "CommunicationLayer/CommDeviceControl/I_ConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/RadioConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/UdpConnectionService.h"
  #include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
  #include "CommunicationPresenter.h"

CommunicationPresenter::CommunicationPresenter(
      UdpMessageForwarder& udpMessageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService,
      CommDeviceManager& commDeviceManager,
      I_CommunicationsMonitoringService& communicationsMonitoringService)
: udpMessageForwarder_(udpMessageForwarder)
, connectionController_(connectionController)
, udpConnectionService_(udpConnectionService)
, radioConnectionService_(radioConnectionService)
, commDeviceManager_(commDeviceManager)
, communicationsMonitoringService_(communicationsMonitoringService)
{
   relayPacketInformation();
   relayConnectionStatus();
}


void CommunicationPresenter::connectToDataSource(CommDefines::Type type)
{
   udpMessageForwarder_.stop();
   connectionController_.setDeviceType(type);
   if(connectionController_.connectToDataSource())
   {
      communicationsMonitoringService_.start();
      commDeviceManager_.connectToDevice(type);
      if (type == CommDefines::Serial)
      {
         udpMessageForwarder_.start();
      }
   }
}

void CommunicationPresenter::disconnectFromDataSource()
{
   udpMessageForwarder_.stop();
   communicationsMonitoringService_.stop();
   connectionController_.disconnectFromDataSource();
}

void CommunicationPresenter::setMulticastNetwork(const QString& groupAddressString, quint16 port)
{
   QHostAddress groupAddress = QHostAddress(groupAddressString);

   udpMessageForwarder_.setMulticastNetwork(groupAddress, port);
   udpConnectionService_.setMulticastNetwork(groupAddress, port);
}

void CommunicationPresenter::setSerialParameters(const QString& serialPortName, int baudRate)
{
   radioConnectionService_.setSerialParameters(serialPortName, baudRate);
}

void CommunicationPresenter::relayPacketInformation()
{
   connect(&communicationsMonitoringService_, SIGNAL(secondsSinceLastPacketReceivedUpdate(int)),
           this, SIGNAL(secondsSinceLastPacketReceivedUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(packetsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(packetsReceivedInLastMinuteUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(secondsSinceLastValidPacketReceivedUpdate(int)),
           this, SIGNAL(secondsSinceLastValidPacketReceivedUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(validPacketsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(validPacketsReceivedInLastMinuteUpdated(int)));
   connect(&communicationsMonitoringService_, SIGNAL(invalidPacketsReceivedInLastMinuteUpdate(int)),
           this, SIGNAL(invalidPacketsReceivedInLastMinuteUpdated(int)));
}

void CommunicationPresenter::relayConnectionStatus()
{
   connect(&connectionController_, SIGNAL(connectionSucceeded()),
           this, SIGNAL(connectionSucceeded()));
   connect(&connectionController_, SIGNAL(connectionFailed(QString)),
           this, SIGNAL(connectionFailed(QString)));
}

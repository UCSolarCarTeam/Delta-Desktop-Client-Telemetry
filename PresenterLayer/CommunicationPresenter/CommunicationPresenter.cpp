#include <QHostAddress>

#include "CommunicationPresenter.h"
#include "CommunicationLayer/CommDeviceControl/I_ConnectionService.h"
#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
#include "CommunicationLayer/CommDeviceControl/ConnectionController.h"
#include "CommunicationLayer/CommDeviceControl/UdpConnectionService.h"
#include "CommunicationLayer/CommDeviceControl/RadioConnectionService.h"

CommunicationPresenter::CommunicationPresenter(
      UdpMessageForwarder& udpMessageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService)
: udpMessageForwarder_(udpMessageForwarder)
, connectionController_(connectionController)
, udpConnectionService_(udpConnectionService)
, radioConnectionService_(radioConnectionService)
{
   relayConnectionStatus();
}

void CommunicationPresenter::connectToDataSource(CommDefines::Type type)
{
   udpMessageForwarder_.stop();
   connectionController_.setDeviceType(type);
   connectionController_.connectToDataSource();

   if (type == CommDefines::Udp)
   {
      udpMessageForwarder_.start();
   }

}

void CommunicationPresenter::disconnectFromDataSource()
{
   udpMessageForwarder_.stop();
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

void CommunicationPresenter::relayConnectionStatus()
{
   connect(&connectionController_, SIGNAL(connectionSucceeded()),
           this, SIGNAL(connectionSucceeded()));
   connect(&connectionController_, SIGNAL(connectionFailed(QString)),
           this, SIGNAL(connectionFailed(QString)));
}

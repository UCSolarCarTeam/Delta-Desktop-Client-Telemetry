#include <QHostAddress>

#include "CommunicationPresenter.h"
#include "CommunicationLayer/CommDeviceControl/I_ConnectionService.h"
#include "CommunicationLayer/CommDeviceControl/UdpMessageForwarder.h"
#include "CommunicationLayer/CommDeviceControl/ConnectionController.h"
#include "CommunicationLayer/CommDeviceControl/UdpConnectionService.h"
#include "CommunicationLayer/CommDeviceControl/RadioConnectionService.h"

CommunicationPresenter::CommunicationPresenter(
      UdpMessageForwarder& messageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService)
: messageForwarder_(messageForwarder)
, connectionController_(connectionController)
, udpConnectionService_(udpConnectionService)
, radioConnectionService_(radioConnectionService)
{
   relayConnectionStatus();
}

void CommunicationPresenter::connectToDataSource(CommDefines::Type type)
{
   messageForwarder_.stop();
   connectionController_.setDeviceType(type);
   connectionController_.connectToDataSource();

   if (type == CommDefines::Udp)
   {
      messageForwarder_.start();
   }

}

void CommunicationPresenter::disconnectFromDataSource()
{
   messageForwarder_.stop();
   connectionController_.disconnectFromDataSource();
}

void CommunicationPresenter::setMulticastNetwork(const QHostAddress& groupAddress, quint16 port)
{
   messageForwarder_.setMulticastNetwork(groupAddress, port);
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

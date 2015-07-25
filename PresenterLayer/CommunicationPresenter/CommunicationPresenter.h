#pragma once

#include <QObject>
class QHostAddress;

#include "../../CommunicationLayer/CommDeviceControl/CommDefines.h"
class ConnectionController;
class RadioConnectionService;
class UdpConnectionService;
class UdpMessageForwarder;

class CommunicationPresenter : public QObject
{
	Q_OBJECT
public:
   explicit CommunicationPresenter(
      UdpMessageForwarder& messageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService);

   void connectToDataSource(CommDefines::Type type);
   void disconnectFromDataSource();

   void setMulticastNetwork(const QHostAddress& groupAddress, quint16 port);
   void setSerialParameters(const QString& serialPortName, int baudRate);

signals:
   void connectionSucceeded();
   void connectionFailed(QString failureMessage);

private:
   void relayConnectionStatus();

private:
   UdpMessageForwarder& messageForwarder_;
   ConnectionController& connectionController_;
   UdpConnectionService& udpConnectionService_;
   RadioConnectionService& radioConnectionService_;
};

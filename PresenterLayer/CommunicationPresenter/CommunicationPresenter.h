#pragma once

#include <QObject>
class QHostAddress;

#include "CommunicationLayer/CommDeviceControl/CommDefines.h"
class ConnectionController;
class RadioConnectionService;
class UdpConnectionService;
class UdpMessageForwarder;
class CommDeviceManager;
class I_CommunicationsMonitoringService;

class CommunicationPresenter : public QObject
{
	Q_OBJECT
public:
   explicit CommunicationPresenter(
      UdpMessageForwarder& udpMessageForwarder,
      ConnectionController& connectionController,
      UdpConnectionService& udpConnectionService,
      RadioConnectionService& radioConnectionService,
      CommDeviceManager& commDeviceManager,
      I_CommunicationsMonitoringService& communicationsMonitoringService);

   void connectToDataSource(CommDefines::Type type);
   void disconnectFromDataSource();

   void setMulticastNetwork(const QString& groupAddress, quint16 port);
   void setSerialParameters(const QString& serialPortName, int baudRate);


signals:
   void secondsSinceLastPacketReceivedUpdated(int secondsSinceLastPacketReceived);
   void packetsReceivedInLastMinuteUpdated(int packetsReceivedInLastMinute);
   void secondsSinceLastValidPacketReceivedUpdated(int secondsSinceLastValidPacketReceived);
   void validPacketsReceivedInLastMinuteUpdated(int validPacketsReceivedInLastMinute);
   void invalidPacketsReceivedInLastMinuteUpdated(int invalidPacketsReceivedInLastMinute);

   void connectionSucceeded();
   void connectionFailed(QString failureMessage);

private:
   void relayPacketInformation();
   void relayConnectionStatus();

private:
   UdpMessageForwarder& udpMessageForwarder_;
   ConnectionController& connectionController_;
   UdpConnectionService& udpConnectionService_;
   RadioConnectionService& radioConnectionService_;
   CommDeviceManager& commDeviceManager_;
   I_CommunicationsMonitoringService& communicationsMonitoringService_;
};

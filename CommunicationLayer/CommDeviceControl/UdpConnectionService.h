#pragma once

#include <QHostAddress>
#include <QString>
#include <QTimer>

class QUdpSocket;

#include "I_ConnectionService.h"

class UdpConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   UdpConnectionService(QUdpSocket& socket);
   virtual ~UdpConnectionService();

   void setMulticastNetwork(QHostAddress ipAddress, quint16 port);
   bool connectToDataSource();
   void disconnectFromDataSource();

private:
   QHostAddress ipAddress_;
   quint16 port_;
   QUdpSocket& socket_;
   QTimer heartbeatTimer_;

private slots:
   void sendHearbeat();
};

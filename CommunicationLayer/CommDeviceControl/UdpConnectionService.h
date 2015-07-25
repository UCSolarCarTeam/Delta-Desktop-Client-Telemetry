#pragma once

#include <QHostAddress>
#include <QString>
class QUdpSocket;

#include "I_ConnectionService.h"

class UdpConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   UdpConnectionService(QUdpSocket& socket);
   virtual ~UdpConnectionService();

   void setMulticastNetwork(QHostAddress groupAddress, quint16 port);
   bool connectToDataSource();
   void disconnectFromDataSource();

private:
   QHostAddress groupAddress_;
   quint16 port_;
   QUdpSocket& socket_;
};

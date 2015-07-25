#pragma once

#include <QHostAddress>
#include <QObject>
#include <QUdpSocket>
class I_CommDevice;

class UdpMessageForwarder : public QObject
{
   Q_OBJECT
public:
   UdpMessageForwarder(const I_CommDevice& device);
   virtual ~UdpMessageForwarder();

   void setMulticastNetwork(const QHostAddress& groupAddress, quint16 port);
   void start();
   void stop();

private slots:
   void forwardData(QByteArray data);

private:
   const I_CommDevice& device_;

   QHostAddress groupAddress_;
   quint16 port_;
   QUdpSocket socket_;
};

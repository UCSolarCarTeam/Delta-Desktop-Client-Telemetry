#pragma once

class QIODevice;
class QUdpSocket;

#include "CommDefines.h"
#include "I_CommDevice.h"

class CommDeviceManager : public I_CommDevice
{
   Q_OBJECT
public:
   CommDeviceManager(QUdpSocket& udpDevice, QIODevice& serialDevice);
   virtual ~CommDeviceManager();

   void connectToDevice(CommDefines::Type type);
   void disconnectFromDevices();

private slots:
   void handleUdpDataIncomming();
   void handleSerialDataIncomming();

private:
   QUdpSocket& udpSocket_;
   QIODevice& serialDevice_;
};

#pragma once

#include <QIODevice>
#include "I_DataInjectionService.h"
#include "I_PacketSynchronizer.h"
class I_ConnectionService;

class PacketSynchronizer : public I_PacketSynchronizer, public I_DataInjectionService
{
   Q_OBJECT
public:
   PacketSynchronizer(QIODevice& inputDevice,
      I_ConnectionService& connectionService);
   virtual ~PacketSynchronizer();

   void injectData(const QByteArray& data);

private slots:
   void handleConnectionCreated();
   void handleIncommingSerialData();

private:
   void handleIncommingData(const QByteArray& data);
   bool alignStartOfPacketToBeginningOfBuffer();
   bool extractPacketIfComplete();

private:
   QIODevice& inputDevice_;
   QByteArray buffer_;
};

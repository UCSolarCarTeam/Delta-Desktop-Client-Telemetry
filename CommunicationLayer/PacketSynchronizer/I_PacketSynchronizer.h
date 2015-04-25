#pragma once

#include <QObject>
#include <QByteArray>

class I_PacketSynchronizer : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketSynchronizer() {}

signals:
   void framedPacket(QByteArray packet);
};

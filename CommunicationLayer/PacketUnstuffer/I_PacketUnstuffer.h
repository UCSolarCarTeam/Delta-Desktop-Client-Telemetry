#pragma once

#include <QByteArray>
#include <QObject>

class I_PacketUnstuffer : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketUnstuffer() {}

signals:
   void packetUnsuffed(QByteArray decodedData);
};

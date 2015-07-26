#pragma once

#include <QObject>
#include <QByteArray>

class I_PacketChecksumChecker : public QObject
{
   Q_OBJECT
public:
   virtual ~I_PacketChecksumChecker() {}

signals:
   void validDataReceived(QByteArray data);
   void invalidDataReceived();
};

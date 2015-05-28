#pragma once

#include <QObject>
#include "I_PacketDecoder.h"
class I_PacketChecksumChecker;

class PacketDecoder : public I_PacketDecoder
{
   Q_OBJECT
public:
   explicit PacketDecoder(const I_PacketChecksumChecker& checksumChecker);

private slots:
   void handleValidData(QByteArray messageData);
};

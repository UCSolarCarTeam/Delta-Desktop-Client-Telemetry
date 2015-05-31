#include "FakePacketChecksumChecker.h"

FakePacketChecksumChecker::FakePacketChecksumChecker()
{
}

FakePacketChecksumChecker::~FakePacketChecksumChecker()
{
}

void FakePacketChecksumChecker::emitValidDataReceived(QByteArray validData)
{
   emit validDataReceived(validData);
}

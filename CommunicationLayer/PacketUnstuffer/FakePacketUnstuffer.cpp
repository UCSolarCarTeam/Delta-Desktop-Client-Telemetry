#include "FakePacketUnstuffer.h"

FakePacketUnstuffer::FakePacketUnstuffer()
{
}

FakePacketUnstuffer::~FakePacketUnstuffer()
{
}

void FakePacketUnstuffer::emitPacketUnstuffed(QByteArray decodedData)
{
   emit packetUnstuffed(decodedData);
}

#include "FakePacketSynchronizer.h"

FakePacketSynchronizer::FakePacketSynchronizer()
{
}

FakePacketSynchronizer::~FakePacketSynchronizer()
{
}

void FakePacketSynchronizer::setIoDevice(QIODevice& ioDevice)
{
   Q_UNUSED(ioDevice);
}

void FakePacketSynchronizer::emitFramedPacket(const QByteArray& packet)
{
   emit framedPacket(packet);
}

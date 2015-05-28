#include "FakePacketSynchronizer.h"

FakePacketSynchronizer::FakePacketSynchronizer()
{
}

FakePacketSynchronizer::~FakePacketSynchronizer()
{
}

void FakePacketSynchronizer::emitFramedPacket(const QByteArray& packet)
{
   emit framedPacket(packet);
}

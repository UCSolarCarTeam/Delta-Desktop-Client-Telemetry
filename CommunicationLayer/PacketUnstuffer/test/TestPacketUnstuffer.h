#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QTest>
#include "../PacketUnstuffer.h"
#include "../../PacketSynchronizer/FakePacketSynchronizer.h"

class TestPacketUnstuffer : public QObject
{
   Q_OBJECT
private slots:
   void init();
   void cleanup();

   void willNotUnstuffPacketsUnderMinimumSize();
   void willUnstuffPackets();
   void willUnstuffPackets_data();

private:
   QScopedPointer<FakePacketSynchronizer> synchronizer_;
   QScopedPointer<PacketUnstuffer> patient_;
};

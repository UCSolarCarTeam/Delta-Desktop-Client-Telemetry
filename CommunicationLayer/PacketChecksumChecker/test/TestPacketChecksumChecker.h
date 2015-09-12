#pragma once

#include <QObject>
#include <QScopedPointer>
#include <QTest>
#include "../PacketChecksumChecker.h"
#include "../../PacketUnstuffer/FakePacketUnstuffer.h"

class TestPacketChecksumChecker : public QObject
{
   Q_OBJECT
private slots:
   void init();
   void cleanup();

   void willValidateChecksumOfPacket();
   void willValidateChecksumOfPacket_data();
   void willNotValidateIfChecksumIsIncorrect();

private:
   QByteArray calculateChecksumAndAddToData(const QByteArray& data);

private:
   QScopedPointer<FakePacketUnstuffer> unstuffer_;
   QScopedPointer<PacketChecksumChecker> patient_;
};

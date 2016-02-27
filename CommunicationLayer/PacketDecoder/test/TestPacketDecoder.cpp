#include <QCoreApplication>
#include <QSignalSpy>
#include "TestPacketDecoder.h"
#include "../../MessagingFramework/MessageDefines.h"
QTEST_MAIN(TestPacketDecoder)

namespace
{
   const int NUMBER_OF_BYTES_IN_FLOAT = 4;

   union FloatCharTranslator
   {
      float floatData;
      char charData[NUMBER_OF_BYTES_IN_FLOAT];
   };

   const float ANONYMOUS_FLOAT_1 = 124.8f;
   const float ANONYMOUS_FLOAT_2 = 0.215f;
   const float ANONYMOUS_FLOAT_3 = 9214.8f;
   const float ANONYMOUS_FLOAT_4 = 147.5f;
   const float ANONYMOUS_FLOAT_5 = 64.7f;
   const float ANONYMOUS_FLOAT_6 = 24.8f;
   const float ANONYMOUS_FLOAT_7 = -34.8f;
   const quint8 ANONYMOUS_CHAR_1 = 0x83u;
   const quint8 ANONYMOUS_CHAR_2 = 0xabu;
   const quint8 ANONYMOUS_CHAR_3 = 0x0F;
   const quint8 ANONYMOUS_CHAR_4 = 0x36;
   const quint16 ANONYMOUS_SHORT_1 = 0x1234;
   const bool ANONYMOUS_BOOL_1 = true;

   const int NUMBER_OF_CELLS = 8;
}

void TestPacketDecoder::init()
{
   checksumChecker_.reset(new FakePacketChecksumChecker);
   patient_.reset(new PacketDecoder(*checksumChecker_));
   connectPacketDecodedSignals();
}

void TestPacketDecoder::cleanup()
{
   patient_.reset();
   checksumChecker_.reset();
   receivedKeyDriverControlTelemetry_.clear();
   receivedDriverControlDetails_.clear();
   receivedFaultsMessages_.clear();
   receivedBatteryDataMessages_.clear();
   receivedCmuDataMessages_.clear();
}

void TestPacketDecoder::willReceiveKeyDriverControlTelemetry()
{
   QByteArray messageData = createValidKeyDriverControlTelemetry();
   checksumChecker_->emitValidDataReceived(messageData);

   QCOMPARE(receivedKeyDriverControlTelemetry_.length(), 1);
   KeyDriverControlTelemetry receivedMessage = receivedKeyDriverControlTelemetry_.first();
   QCOMPARE(receivedMessage.setSpeed(), ANONYMOUS_FLOAT_1);
   QCOMPARE(receivedMessage.setCurrent(), ANONYMOUS_FLOAT_2);
   QCOMPARE(receivedMessage.busCurrent(), ANONYMOUS_FLOAT_3);
   QCOMPARE(receivedMessage.busVoltage(), ANONYMOUS_FLOAT_4);
   QCOMPARE(receivedMessage.speed(), ANONYMOUS_FLOAT_5);
}

void TestPacketDecoder::willReceiveDriverControlDetails()
{
   QByteArray messageData = createValidDriverControlDetails();
   checksumChecker_->emitValidDataReceived(messageData);

   QCOMPARE(receivedDriverControlDetails_.length(), 1);
   DriverControlDetails receivedMessage = receivedDriverControlDetails_.first();
   QCOMPARE(receivedMessage.motorVelocity(), ANONYMOUS_FLOAT_1);
   QCOMPARE(receivedMessage.motorVoltage(), ANONYMOUS_FLOAT_2);
   QCOMPARE(receivedMessage.motorCurrentReal(), ANONYMOUS_FLOAT_3);
   QCOMPARE(receivedMessage.backEmf(), ANONYMOUS_FLOAT_4);
   QCOMPARE(receivedMessage.dpsBoardTemperature(), ANONYMOUS_FLOAT_5);
   QCOMPARE(receivedMessage.dcBusAmpHours(), ANONYMOUS_FLOAT_6);
   QCOMPARE(receivedMessage.odometer(), ANONYMOUS_FLOAT_7);
}

void TestPacketDecoder::willReceiveFaultsMessage()
{
   QByteArray messageData = createValidFaultsMessage();
   checksumChecker_->emitValidDataReceived(messageData);

   QCOMPARE(receivedFaultsMessages_.length(), 1);
   FaultsMessage receivedMessage = receivedFaultsMessages_.first();
   QCOMPARE(receivedMessage.motorOneFaults(), MotorFaults(ANONYMOUS_CHAR_1));
   QCOMPARE(receivedMessage.motorOneLimitFlags(), LimitFlags(ANONYMOUS_CHAR_2));
   QCOMPARE(receivedMessage.motorTwoFaults(), MotorFaults(ANONYMOUS_CHAR_3));
   QCOMPARE(receivedMessage.motorTwoLimitFlags(), LimitFlags(ANONYMOUS_CHAR_4));
   QCOMPARE(receivedMessage.batteryFaults(), BatteryFaults(ANONYMOUS_SHORT_1));
   QCOMPARE(receivedMessage.canReceivedErrorCounts(), ANONYMOUS_CHAR_1);
   QCOMPARE(receivedMessage.canTransmittedErrorCounts(), ANONYMOUS_CHAR_2);
}

void TestPacketDecoder::willReceiveBatteryDataMessage()
{
   QByteArray messageData = createValidBatteryDataMessage();
   checksumChecker_->emitValidDataReceived(messageData);

   QCOMPARE(receivedBatteryDataMessages_.length(), 1);
   BatteryDataMessage receivedMessage = receivedBatteryDataMessages_.first();
   QCOMPARE(receivedMessage.batteryVoltage(), ANONYMOUS_FLOAT_1);
   QCOMPARE(receivedMessage.batteryCurrent(), ANONYMOUS_FLOAT_2);
   QCOMPARE(receivedMessage.stateOfCharge(), ANONYMOUS_FLOAT_3);
   QCOMPARE(receivedMessage.balanceStateOfCharge(), ANONYMOUS_FLOAT_4);
   QCOMPARE(receivedMessage.secondaryBatteryUnderVoltage(), ANONYMOUS_BOOL_1);
}

void TestPacketDecoder::willReceiveCmuDataMessage()
{
   QByteArray messageData = createValidCmuDataMessage();
   checksumChecker_->emitValidDataReceived(messageData);

   QCOMPARE(receivedCmuDataMessages_.length(), 1);
   CmuDataMessage receivedMessage = receivedCmuDataMessages_.first();
   QCOMPARE(receivedMessage.cellNumber(), ANONYMOUS_CHAR_1);
   QCOMPARE(receivedMessage.pcbTemperature(), ANONYMOUS_FLOAT_1);
   QCOMPARE(receivedMessage.cellTemperature(), ANONYMOUS_FLOAT_2);
   for(int i = 0; i < NUMBER_OF_CELLS; i++)
   {
      QCOMPARE(receivedMessage.cellVoltages().at(i), ANONYMOUS_FLOAT_3 + 1);
   }
}

void TestPacketDecoder::handlePacketDecoded(const KeyDriverControlTelemetry message)
{
   receivedKeyDriverControlTelemetry_.append(message);
}

void TestPacketDecoder::handlePacketDecoded(const DriverControlDetails message)
{
   receivedDriverControlDetails_.append(message);
}

void TestPacketDecoder::handlePacketDecoded(const FaultsMessage message)
{
   receivedFaultsMessages_.append(message);
}

void TestPacketDecoder::handlePacketDecoded(const BatteryDataMessage message)
{
   receivedBatteryDataMessages_.append(message);
}

void TestPacketDecoder::handlePacketDecoded(const CmuDataMessage message)
{
   receivedCmuDataMessages_.append(message);
}

void TestPacketDecoder::connectPacketDecodedSignals()
{
   connect(patient_.data(), SIGNAL(packetDecoded(const KeyDriverControlTelemetry)),
      this, SLOT(handlePacketDecoded(const KeyDriverControlTelemetry)));
   connect(patient_.data(), SIGNAL(packetDecoded(const DriverControlDetails)),
      this, SLOT(handlePacketDecoded(const DriverControlDetails)));
   connect(patient_.data(), SIGNAL(packetDecoded(const FaultsMessage)),
      this, SLOT(handlePacketDecoded(const FaultsMessage)));
   connect(patient_.data(), SIGNAL(packetDecoded(const BatteryDataMessage)),
      this, SLOT(handlePacketDecoded(const BatteryDataMessage)));
   connect(patient_.data(), SIGNAL(packetDecoded(const CmuDataMessage)),
      this, SLOT(handlePacketDecoded(const CmuDataMessage)));
}

QByteArray TestPacketDecoder::createValidKeyDriverControlTelemetry() const
{
   QByteArray messageData;
   messageData.append(static_cast<quint8>(MessageDefines::KeyDriverControlTelemetry));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_1));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_2));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_3));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_4));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_5));
   return messageData;
}

QByteArray TestPacketDecoder::createValidDriverControlDetails() const
{
   QByteArray messageData;
   messageData.append(static_cast<quint8>(MessageDefines::DriverControlDetails));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_1));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_2));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_3));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_4));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_5));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_6));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_7));
   return messageData;
}

QByteArray TestPacketDecoder::createValidFaultsMessage() const
{
   QByteArray messageData;
   messageData.append(static_cast<quint8>(MessageDefines::Faults));
   messageData.append(ANONYMOUS_CHAR_1);
   messageData.append(ANONYMOUS_CHAR_2);
   messageData.append(ANONYMOUS_CHAR_3);
   messageData.append(ANONYMOUS_CHAR_4);
   unsigned char upperChar = (ANONYMOUS_SHORT_1 >> 8) & 0xFF;
   unsigned char lowerChar = ANONYMOUS_SHORT_1 & 0xFF;
   messageData.append(lowerChar);
   messageData.append(upperChar);
   messageData.append(ANONYMOUS_CHAR_1);
   messageData.append(ANONYMOUS_CHAR_2);
   return messageData;
}

QByteArray TestPacketDecoder::createValidBatteryDataMessage() const
{
   QByteArray messageData;
   messageData.append(static_cast<quint8>(MessageDefines::BatteryData));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_1));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_2));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_3));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_4));
   messageData.append(static_cast<quint8>(ANONYMOUS_BOOL_1));
   return messageData;
}

QByteArray TestPacketDecoder::createValidCmuDataMessage() const
{
   QByteArray messageData;
   messageData.append(static_cast<quint8>(MessageDefines::CmuData));
   messageData.append(ANONYMOUS_CHAR_1);
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_1));
   messageData.append(floatToByteArray(ANONYMOUS_FLOAT_2));
   for(int i = 0; i < NUMBER_OF_CELLS; i++)
   {
      messageData.append(floatToByteArray(ANONYMOUS_FLOAT_3 + 1));
   }
   return messageData;
}

QByteArray TestPacketDecoder::floatToByteArray(float value) const
{
   FloatCharTranslator dataUnion;
   dataUnion.floatData = value;
   return QByteArray(dataUnion.charData, NUMBER_OF_BYTES_IN_FLOAT);
}

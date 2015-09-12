#pragma once

#include <QObject>
#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"

class I_FaultsData;

class FaultsPresenter : public QObject
{
   Q_OBJECT
public:
   explicit FaultsPresenter(const I_FaultsData& faultsData);

private:
   void relayFaultsData();

   const I_FaultsData& faultsData_;

signals:
   void motorOneFaultsReceived(MotorFaults motorFaults);
   void motorOneLimitFlagsReceived(LimitFlags limitFlags);
   void motorTwoFaultsReceived(MotorFaults motorFaults);
   void motorTwoLimitFlagsReceived(LimitFlags limitFlags);
   void batteryFaultsReceived(BatteryFaults batteryFaults);
};

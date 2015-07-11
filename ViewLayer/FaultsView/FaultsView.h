#pragma once

#include <QObject>
#include "../../CommunicationLayer/MessagingFramework/MotorFaults.h"
#include "../../CommunicationLayer/MessagingFramework/LimitFlags.h"
#include "../../CommunicationLayer/MessagingFramework/BatteryFaults.h"

class FaultsPresenter;
class FaultsUI;

class FaultsView : public QObject
{
   Q_OBJECT
public:
    FaultsView(FaultsPresenter& presenter, FaultsUI& ui);
    ~FaultsView();

private:
   FaultsPresenter& faultsPresenter_;
   FaultsUI& ui_;

private slots:
   void motorOneFaultsReceived(MotorFaults motorFaults);
   void motorOneLimitFlagsReceived(LimitFlags limitFlags);
   void motorTwoFaultsReceived(MotorFaults motorFaults);
   void motorTwoLimitFlagsReceived(LimitFlags limitFlags);
   void batteryFaultsReceived(BatteryFaults batteryFaults);
};


#include "FaultsView.h"
#include "../../PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "../FaultsUI/FaultsUI.h"
#include <QDateTime>

FaultsView::FaultsView(FaultsPresenter& faultsPresenter, FaultsUI& ui)
: faultsPresenter_(faultsPresenter)
, ui_(ui)
{
   connect(&faultsPresenter_, SIGNAL(motorOneFaultsReceived(MotorFaults)),
         this, SLOT(motorOneFaultsReceived(MotorFaults)));
   connect(&faultsPresenter_, SIGNAL(motorOneLimitFlagsReceived(LimitFlags)),
           this, SLOT(motorOneLimitFlagsReceived(LimitFlags)));
   connect(&faultsPresenter_, SIGNAL(motorTwoFaultsReceived(MotorFaults)),
         this, SLOT(motorTwoFaultsReceived(MotorFaults)));
   connect(&faultsPresenter_, SIGNAL(motorTwoLimitFlagsReceived(LimitFlags)),
           this, SLOT(motorTwoLimitFlagsReceived(LimitFlags)));
   connect(&faultsPresenter_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
           this, SLOT(batteryFaultsReceived(BatteryFaults)));
}

FaultsView::~FaultsView()
{
}

void FaultsView::motorOneFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){
      ui_.desaturationFaultLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Desaturation Fault - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.desaturationFaultLabel1().setStyleSheet("");
   }

   if(motorFaults.railUnderVoltageLockOut()){
     ui_.fifteenVoltRailUnderVoltageLockoutLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
     ui_.historyTextEdit().append("Motor One Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
   }
  else{
     ui_.fifteenVoltRailUnderVoltageLockoutLabel1().setStyleSheet("");
   }

   if(motorFaults.configReadError()){
      ui_.configReadErrorLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Config Read Error- " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.configReadErrorLabel1().setStyleSheet("");
   }

   if(motorFaults.watchdogCausedLastReset()){
      ui_.watchDogCausedLastResetLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One WatchDog Caused Last Reset- " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.watchDogCausedLastResetLabel1().setStyleSheet("");
   }

   if(motorFaults.badMotorPositionHallSequence()){
      ui_.badMotorPositionHallSequenceLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.badMotorPositionHallSequenceLabel1().setStyleSheet("");
   }

   if(motorFaults.dcBusOverVoltage()){
      ui_.dcBusOverVoltageLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.dcBusOverVoltageLabel1().setStyleSheet("");
   }

   if(motorFaults.softwareOverCurrent()){
      ui_.softwareOverCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Software Over Current - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.softwareOverCurrentLabel1().setStyleSheet("");
   }

   if(motorFaults.hardwareOverCurrent()){
      ui_.hardwareOverCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Hardware Over Current - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.hardwareOverCurrentLabel1().setStyleSheet("");
   }
}

void FaultsView::motorOneLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
      ui_.outputVoltagePwmLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Output Voltage PWM - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.outputVoltagePwmLabel1().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){
      ui_.motorCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Motor Current Limit- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.motorCurrentLabel1().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){
      ui_.velocityLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Velocity Limit- " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.velocityLabel1().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){
      ui_.busCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Bus Current Limit- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busCurrentLabel1().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){
      ui_.busVoltageUpperLimitLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageUpperLimitLabel1().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){
      ui_.busVoltageLowerLimitLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageLowerLimitLabel1().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
      ui_.ipmTemperatureOrMotorTemperatureLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor One IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel1().setStyleSheet("");
   }
}

void FaultsView::motorTwoFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){
      ui_.desaturationFaultLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
   ui_.historyTextEdit().append("Motor Two motorFaults - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.desaturationFaultLabel2().setStyleSheet("");
   }

    if(motorFaults.railUnderVoltageLockOut()){
      ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
    }
   else{
      ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("");
    }

    if(motorFaults.configReadError()){
      ui_.configReadErrorLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Config Read Error- " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.configReadErrorLabel2().setStyleSheet("");
    }

    if(motorFaults.watchdogCausedLastReset()){
      ui_.watchDogCausedLastResetLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Watchdog Caused Last Reset - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.watchDogCausedLastResetLabel2().setStyleSheet("");
    }

    if(motorFaults.badMotorPositionHallSequence()){
      ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("");
    }

    if(motorFaults.dcBusOverVoltage()){
      ui_.dcBusOverVoltageLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.dcBusOverVoltageLabel2().setStyleSheet("");
    }

    if(motorFaults.softwareOverCurrent()){
      ui_.softwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Software Over Current - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.softwareOverCurrentLabel2().setStyleSheet("");
    }

    if(motorFaults.hardwareOverCurrent()){
      ui_.hardwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Hardware Over Current - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.hardwareOverCurrentLabel2().setStyleSheet("");
    }
}

void FaultsView::motorTwoLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
      ui_.outputVoltagePwmLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Output Voltage PWM - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.outputVoltagePwmLabel2().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){
      ui_.motorCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Motor Current Limit- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.motorCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){
      ui_.velocityLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two velocityLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.velocityLabel2().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){
      ui_.busCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Bus Current Limit- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){
      ui_.busVoltageUpperLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageUpperLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){
      ui_.busVoltageLowerLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageLowerLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
      ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Motor Two IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("");
   }
}

void FaultsView::batteryFaultsReceived(BatteryFaults batteryFaults)
{
   if(batteryFaults.cellOverVoltage()){
      ui_.cellOverVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Cell Over Voltage - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellOverVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellUnderVoltage()){
      ui_.cellUnderVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Cell Under Voltage - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellUnderVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellOverTemperature()){
      ui_.cellOverTemperatureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Cell Over Temperature - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellOverTemperatureLabel().setStyleSheet("");
   }

   if(batteryFaults.measurementUntrusted()){
      ui_.measurementUntrustedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Measurement Untrusted - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.measurementUntrustedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCommTimeout()){
      ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery CMU Comm Timeout - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.vehicleCommTimeout()){
      ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Vehicle Comm Timeout - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.bmuIsInSetupMode()){
      ui_.bmuInSetupModeLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery BMU in Setup Mode - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.bmuInSetupModeLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCanBusPowerStatus()){
      ui_.cmuCanBusPowerStatusLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery CMU Can Bus Power Status - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuCanBusPowerStatusLabel().setStyleSheet("");
   }

   if(batteryFaults.packIsolationTestFailure()){
      ui_.packIsolationTestFailureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Pack Isolation Test Failure - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.packIsolationTestFailureLabel().setStyleSheet("");
   }

   if(batteryFaults.softwareOverCurrentMeasured()){
      ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Software Over Current Measured - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("");
   }

   if(batteryFaults.canSupplyIsLow()){
      ui_.can12vSupplyLowLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Can Supply is Low - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.can12vSupplyLowLabel().setStyleSheet("");
   }

   if(batteryFaults.contactorIsStuck()){
      ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery Contactor is Stuck - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuDetectedExtraCellPresent()){
      ui_.cmuDetectedExtraCellLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("Battery CMU Detected Extra Cell - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuDetectedExtraCellLabel().setStyleSheet("");
   }

}

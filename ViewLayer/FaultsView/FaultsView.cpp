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
      ui_.desaturationFaultLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("motorFaults - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.desaturationFaultLabel().setStyleSheet("");
   }

   if(motorFaults.railUnderVoltageLockOut()){
     ui_.fifteenVoltRailUnderVoltageLockoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
     ui_.historyTextEdit().append("railUnderVoltageLockOut - " + QDateTime::currentDateTime().toString());
   }
  else{
     ui_.fifteenVoltRailUnderVoltageLockoutLabel().setStyleSheet("");
   }

   if(motorFaults.configReadError()){
      ui_.configReadErrorLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("configReadError - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.configReadErrorLabel().setStyleSheet("");
   }

   if(motorFaults.watchdogCausedLastReset()){
      ui_.watchDogCausedLastResetLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("watchdogCausedLastReset - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.watchDogCausedLastResetLabel().setStyleSheet("");
   }

   if(motorFaults.badMotorPositionHallSequence()){
      ui_.badMotorPositionHallSequenceLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("badMotorPositionHallSequence - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.badMotorPositionHallSequenceLabel().setStyleSheet("");
   }

   if(motorFaults.dcBusOverVoltage()){
      ui_.dcBusOverVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("dcBusOverVoltage - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.dcBusOverVoltageLabel().setStyleSheet("");
   }

   if(motorFaults.softwareOverCurrent()){
      ui_.softwareOverCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("softwareOverCurrent - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.softwareOverCurrentLabel().setStyleSheet("");
   }

   if(motorFaults.hardwareOverCurrent()){
      ui_.hardwareOverCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("hardwareOverCurrent - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.hardwareOverCurrentLabel().setStyleSheet("");
   }
}

void FaultsView::motorOneLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
      ui_.outputVoltagePwmLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("outputVoltagePwmLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.outputVoltagePwmLabel().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){
      ui_.motorCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("motorCurrentLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.motorCurrentLabel().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){
      ui_.velocityLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("velocityLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.velocityLabel().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){
      ui_.busCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busCurrentLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busCurrentLabel().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){
      ui_.busVoltageUpperLimitLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busVoltageUpperLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageUpperLimitLabel().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){
      ui_.busVoltageLowerLimitLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busVoltageLowerLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageLowerLimitLabel().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
      ui_.ipmTemperatureOrMotorTemperatureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("ipmOrMotorTelemetryLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel().setStyleSheet("");
   }
}

void FaultsView::motorTwoFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){
      ui_.desaturationFaultLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
   ui_.historyTextEdit().append("motorFaults - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.desaturationFaultLabel2().setStyleSheet("");
   }

    if(motorFaults.railUnderVoltageLockOut()){
      ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("railUnderVoltageLockOut - " + QDateTime::currentDateTime().toString());
    }
   else{
      ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("");
    }

    if(motorFaults.configReadError()){
      ui_.configReadErrorLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("configReadError - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.configReadErrorLabel2().setStyleSheet("");
    }

    if(motorFaults.watchdogCausedLastReset()){
      ui_.watchDogCausedLastResetLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("watchdogCausedLastReset - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.watchDogCausedLastResetLabel2().setStyleSheet("");
    }

    if(motorFaults.badMotorPositionHallSequence()){
      ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("badMotorPositionHallSequence - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("");
    }

    if(motorFaults.dcBusOverVoltage()){
      ui_.dcBusOverVoltageLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("dcBusOverVoltage - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.dcBusOverVoltageLabel2().setStyleSheet("");
    }

    if(motorFaults.softwareOverCurrent()){
      ui_.softwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("softwareOverCurrent - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.softwareOverCurrentLabel2().setStyleSheet("");
    }

    if(motorFaults.hardwareOverCurrent()){
      ui_.hardwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("hardwareOverCurrent - " + QDateTime::currentDateTime().toString());
    }
    else{
      ui_.hardwareOverCurrentLabel2().setStyleSheet("");
    }
}

void FaultsView::motorTwoLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){
      ui_.outputVoltagePwmLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("outputVoltagePwmLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.outputVoltagePwmLabel2().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){
      ui_.motorCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("motorCurrentLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.motorCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){
      ui_.velocityLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("velocityLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.velocityLabel2().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){
      ui_.busCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busCurrentLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){
      ui_.busVoltageUpperLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busVoltageUpperLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageUpperLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){
      ui_.busVoltageLowerLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("busVoltageLowerLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.busVoltageLowerLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){
      ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("ipmOrMotorTelemetryLimit - " + QDateTime::currentDateTime().toString());
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("");
   }
}

void FaultsView::batteryFaultsReceived(BatteryFaults batteryFaults)
{
   if(batteryFaults.cellOverVoltage()){
      ui_.cellOverVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cellOverVoltage - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellOverVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellUnderVoltage()){
      ui_.cellUnderVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cellUnderVoltage - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellUnderVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellOverTemperature()){
      ui_.cellOverTemperatureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cellOverTemperature - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cellOverTemperatureLabel().setStyleSheet("");
   }

   if(batteryFaults.measurementUntrusted()){
      ui_.measurementUntrustedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("measurementUntrusted - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.measurementUntrustedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCommTimeout()){
      ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cmuCommTimeout - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.vehicleCommTimeout()){
      ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("vehicleCommTimeout - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.bmuIsInSetupMode()){
      ui_.bmuInSetupModeLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("bmuIsInSetupMode - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.bmuInSetupModeLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCanBusPowerStatus()){
      ui_.cmuCanBusPowerStatusLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cmuCanBusPowerStatus - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuCanBusPowerStatusLabel().setStyleSheet("");
   }

   if(batteryFaults.packIsolationTestFailure()){
      ui_.packIsolationTestFailureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("packIsolationTestFailure - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.packIsolationTestFailureLabel().setStyleSheet("");
   }

   if(batteryFaults.softwareOverCurrentMeasured()){
      ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("softwareOverCurrentMeasured - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("");
   }

   if(batteryFaults.canSupplyIsLow()){
      ui_.can12vSupplyLowLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("canSupplyIsLow - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.can12vSupplyLowLabel().setStyleSheet("");
   }

   if(batteryFaults.contactorIsStuck()){
      ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("contactorIsStuck - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuDetectedExtraCellPresent()){
      ui_.cmuDetectedExtraCellLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
      ui_.historyTextEdit().append("cmuDetectedExtraCellPresent - " + QDateTime::currentDateTime().toString());
   }
   else{
      ui_.cmuDetectedExtraCellLabel().setStyleSheet("");
   }

}

#include "FaultsView.h"
#include "../../PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "../FaultsUI/FaultsUI.h"
#include <QDateTime>
#include <QDebug>

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

bool FaultsView::isLabelRed(QLabel& label)
{   
    if(label.styleSheet().contains("red")){
        return true;
    } else {
        return false;
    }
}

void FaultsView::motorOneFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){ 
      if(!isLabelRed(ui_.desaturationFaultLabel1())){
        ui_.desaturationFaultLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Desaturation Fault - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.desaturationFaultLabel1().setStyleSheet("");
   }

   if(motorFaults.railUnderVoltageLockOut()){ 
      if(!isLabelRed(ui_.fifteenVoltRailUnderVoltageLockoutLabel1())){
         ui_.fifteenVoltRailUnderVoltageLockoutLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
         ui_.historyTextEdit().append("Motor One Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
      }
   }
  else{
     ui_.fifteenVoltRailUnderVoltageLockoutLabel1().setStyleSheet("");
   }

   if(motorFaults.configReadError()){ 
      if(!isLabelRed(ui_.configReadErrorLabel1())){
        ui_.configReadErrorLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Config Read Error- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.configReadErrorLabel1().setStyleSheet("");
   }

   if(motorFaults.watchdogCausedLastReset()){ 
      if(!isLabelRed(ui_.watchDogCausedLastResetLabel1())){
        ui_.watchDogCausedLastResetLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One WatchDog Caused Last Reset- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.watchDogCausedLastResetLabel1().setStyleSheet("");
   }

   if(motorFaults.badMotorPositionHallSequence()){ 
      if(!isLabelRed(ui_.badMotorPositionHallSequenceLabel1())){
        ui_.badMotorPositionHallSequenceLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.badMotorPositionHallSequenceLabel1().setStyleSheet("");
   }

   if(motorFaults.dcBusOverVoltage()){ 
      if(!isLabelRed(ui_.dcBusOverVoltageLabel1())){
        ui_.dcBusOverVoltageLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.dcBusOverVoltageLabel1().setStyleSheet("");
   }

   if(motorFaults.softwareOverCurrent()){ 
      if(!isLabelRed(ui_.softwareOverCurrentLabel1())){
        ui_.softwareOverCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Software Over Current - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.softwareOverCurrentLabel1().setStyleSheet("");
   }

   if(motorFaults.hardwareOverCurrent()){ 
      if(!isLabelRed(ui_.hardwareOverCurrentLabel1())){
        ui_.hardwareOverCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Hardware Over Current - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.hardwareOverCurrentLabel1().setStyleSheet("");
   }
}

void FaultsView::motorOneLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){ 
      if(!isLabelRed(ui_.outputVoltagePwmLabel1())){
        ui_.outputVoltagePwmLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Output Voltage PWM - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.outputVoltagePwmLabel1().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){ 
      if(!isLabelRed(ui_.motorCurrentLabel1())){
        ui_.motorCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Motor Current Limit- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.motorCurrentLabel1().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){ 
      if(!isLabelRed(ui_.velocityLabel1())){
        ui_.velocityLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Velocity Limit- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.velocityLabel1().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){ 
      if(!isLabelRed(ui_.busCurrentLabel1())){
        ui_.busCurrentLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Bus Current Limit- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busCurrentLabel1().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){ 
      if(!isLabelRed(ui_.busVoltageUpperLimitLabel1())){
        ui_.busVoltageUpperLimitLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busVoltageUpperLimitLabel1().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){ 
      if(!isLabelRed(ui_.busVoltageLowerLimitLabel1())){
        ui_.busVoltageLowerLimitLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busVoltageLowerLimitLabel1().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){ 
      if(!isLabelRed(ui_.ipmTemperatureOrMotorTemperatureLabel1())){
        ui_.ipmTemperatureOrMotorTemperatureLabel1().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor One IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel1().setStyleSheet("");
   }
}

void FaultsView::motorTwoFaultsReceived(MotorFaults motorFaults)
{
   if(motorFaults.desaturationFault()){ 
      if(!isLabelRed(ui_.desaturationFaultLabel2())){
        ui_.desaturationFaultLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
   ui_  .historyTextEdit().append("Motor Two motorFaults - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.desaturationFaultLabel2().setStyleSheet("");
   }

    if(motorFaults.railUnderVoltageLockOut()){ 
        if(!isLabelRed(ui_.fifteenVoltRailUnderVoltageLockoutLabel2())){
          ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Rail Under Voltage Lockout- " + QDateTime::currentDateTime().toString());
        }
    }
   else{
      ui_.fifteenVoltRailUnderVoltageLockoutLabel2().setStyleSheet("");
    }

    if(motorFaults.configReadError()){ 
        if(!isLabelRed(ui_.configReadErrorLabel2())){
          ui_.configReadErrorLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Config Read Error- " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.configReadErrorLabel2().setStyleSheet("");
    }

    if(motorFaults.watchdogCausedLastReset()){ 
        if(!isLabelRed(ui_.watchDogCausedLastResetLabel2())){
          ui_.watchDogCausedLastResetLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Watchdog Caused Last Reset - " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.watchDogCausedLastResetLabel2().setStyleSheet("");
    }

    if(motorFaults.badMotorPositionHallSequence()){ 
        if(!isLabelRed(ui_.badMotorPositionHallSequenceLabel2())){
          ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Bad Motor Position Hall Sequence - " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.badMotorPositionHallSequenceLabel2().setStyleSheet("");
    }

    if(motorFaults.dcBusOverVoltage()){ 
        if(!isLabelRed(ui_.dcBusOverVoltageLabel2())){
          ui_.dcBusOverVoltageLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two DC Bus Over Voltage- " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.dcBusOverVoltageLabel2().setStyleSheet("");
    }

    if(motorFaults.softwareOverCurrent()){ 
        if(!isLabelRed(ui_.softwareOverCurrentLabel2())){
          ui_.softwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Software Over Current - " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.softwareOverCurrentLabel2().setStyleSheet("");
    }

    if(motorFaults.hardwareOverCurrent()){ 
        if(!isLabelRed(ui_.hardwareOverCurrentLabel2())){
          ui_.hardwareOverCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
          ui_.historyTextEdit().append("Motor Two Hardware Over Current - " + QDateTime::currentDateTime().toString());
        }
    }
    else{
      ui_.hardwareOverCurrentLabel2().setStyleSheet("");
    }
}

void FaultsView::motorTwoLimitFlagsReceived(LimitFlags limitFlags)
{
   if(limitFlags.outputVoltagePwmLimit()){ 
      if(!isLabelRed(ui_.outputVoltagePwmLabel2())){
        ui_.outputVoltagePwmLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two Output Voltage PWM - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.outputVoltagePwmLabel2().setStyleSheet("");
   }
   if(limitFlags.motorCurrentLimit()){ 
      if(!isLabelRed(ui_.motorCurrentLabel2())){
        ui_.motorCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two Motor Current Limit- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.motorCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.velocityLimit()){ 
      if(!isLabelRed(ui_.velocityLabel2())){
        ui_.velocityLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two velocityLimit - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.velocityLabel2().setStyleSheet("");
   }
   if(limitFlags.busCurrentLimit()){ 
      if(!isLabelRed(ui_.busCurrentLabel2())){
        ui_.busCurrentLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two Bus Current Limit- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busCurrentLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageUpperLimit()){ 
      if(!isLabelRed(ui_.busVoltageUpperLimitLabel2())){
        ui_.busVoltageUpperLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two Bus Voltage Upper Limit - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busVoltageUpperLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.busVoltageLowerLimit()){ 
      if(!isLabelRed(ui_.busVoltageLowerLimitLabel2())){
        ui_.busVoltageLowerLimitLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two Bus Voltage Lower Limit - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.busVoltageLowerLimitLabel2().setStyleSheet("");
   }
   if(limitFlags.ipmOrMotorTelemetryLimit()){ 
      if(!isLabelRed(ui_.ipmTemperatureOrMotorTemperatureLabel2())){
        ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Motor Two IPM Temp Or Motor Temp- " + QDateTime::currentDateTime().toString());
      }
   }
   else{
       ui_.ipmTemperatureOrMotorTemperatureLabel2().setStyleSheet("");
   }
}

void FaultsView::batteryFaultsReceived(BatteryFaults batteryFaults)
{
   if(batteryFaults.cellOverVoltage()){ 
      if(!isLabelRed(ui_.cellOverVoltageLabel())){
        ui_.cellOverVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Cell Over Voltage - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cellOverVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellUnderVoltage()){ 
      if(!isLabelRed(ui_.cellUnderVoltageLabel())){
        ui_.cellUnderVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Cell Under Voltage - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cellUnderVoltageLabel().setStyleSheet("");
   }

   if(batteryFaults.cellOverTemperature()){ 
      if(!isLabelRed(ui_.cellOverTemperatureLabel())){
        ui_.cellOverTemperatureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Cell Over Temperature - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cellOverTemperatureLabel().setStyleSheet("");
   }

   if(batteryFaults.measurementUntrusted()){ 
      if(!isLabelRed(ui_.measurementUntrustedLabel())){
        ui_.measurementUntrustedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Measurement Untrusted - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.measurementUntrustedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCommTimeout()){ 
      if(!isLabelRed(ui_.cmuCommunicationsTimeoutLabel())){
        ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery CMU Comm Timeout - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cmuCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.vehicleCommTimeout()){ 
      if(!isLabelRed(ui_.vehicleCommunicationsTimeoutLabel())){
        ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Vehicle Comm Timeout - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.vehicleCommunicationsTimeoutLabel().setStyleSheet("");
   }

   if(batteryFaults.bmuIsInSetupMode()){ 
      if(!isLabelRed(ui_.bmuInSetupModeLabel())){
        ui_.bmuInSetupModeLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery BMU in Setup Mode - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.bmuInSetupModeLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuCanBusPowerStatus()){ 
      if(!isLabelRed(ui_.cmuCanBusPowerStatusLabel())){
        ui_.cmuCanBusPowerStatusLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery CMU Can Bus Power Status - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cmuCanBusPowerStatusLabel().setStyleSheet("");
   }

   if(batteryFaults.packIsolationTestFailure()){ 
      if(!isLabelRed(ui_.packIsolationTestFailureLabel())){
        ui_.packIsolationTestFailureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Pack Isolation Test Failure - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.packIsolationTestFailureLabel().setStyleSheet("");
   }

   if(batteryFaults.softwareOverCurrentMeasured()){ 
      if(!isLabelRed(ui_.softwareOverCurrentMeasurementNotValidLabel())){
        ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Software Over Current Measured - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.softwareOverCurrentMeasurementNotValidLabel().setStyleSheet("");
   }

   if(batteryFaults.canSupplyIsLow()){ 
      if(!isLabelRed(ui_.can12vSupplyLowLabel())){
        ui_.can12vSupplyLowLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Can Supply is Low - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.can12vSupplyLowLabel().setStyleSheet("");
   }

   if(batteryFaults.contactorIsStuck()){ 
      if(!isLabelRed(ui_.contactorStuckOrNotEngagedLabel())){
        ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery Contactor is Stuck - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.contactorStuckOrNotEngagedLabel().setStyleSheet("");
   }

   if(batteryFaults.cmuDetectedExtraCellPresent()){ 
      if(!isLabelRed(ui_.cmuDetectedExtraCellLabel())){
        ui_.cmuDetectedExtraCellLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
        ui_.historyTextEdit().append("Battery CMU Detected Extra Cell - " + QDateTime::currentDateTime().toString());
      }
   }
   else{
      ui_.cmuDetectedExtraCellLabel().setStyleSheet("");
   }

}

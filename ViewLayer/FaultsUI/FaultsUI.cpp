#include "FaultsUI.h"
#include "ui_FaultsUI.h"

FaultsUI::FaultsUI()
: ui(new Ui::FaultsUI)
{
   ui->setupUi(this);
}

FaultsUI::~FaultsUI()
{
   delete ui;
}

void FaultsUI::hideHeaderBar()
{
   ui->faultTitleLabel->hide();
}


/* Motor One Error Flags */
QLabel& FaultsUI::desaturationFaultLabel1()
{
   return *ui->desaturationFaultLabel1;
}
QLabel& FaultsUI::badMotorPositionHallSequenceLabel1()
{
   return *ui->badMotorPositionHallSequenceLabel1;
}
QLabel& FaultsUI::fifteenVoltRailUnderVoltageLockoutLabel1()
{
   return *ui->fifteenVoltRailUnderVoltageLockoutLabel1;
}
QLabel& FaultsUI::dcBusOverVoltageLabel1()
{
   return *ui->dcBusOverVoltageLabel1;
}
QLabel& FaultsUI::configReadErrorLabel1()
{
   return *ui->configReadErrorLabel1;
}
QLabel& FaultsUI::softwareOverCurrentLabel1()
{
   return *ui->softwareOverCurrentLabel1;
}
QLabel& FaultsUI::watchDogCausedLastResetLabel1()
{
   return *ui->watchDogCausedLastResetLabel1;
}
QLabel& FaultsUI::hardwareOverCurrentLabel1()
{
   return *ui->hardwareOverCurrentLabel1;
}

   /* Motor Two Error Flags */
QLabel& FaultsUI::desaturationFaultLabel2()
{
   return *ui->desaturationFaultLabel2;
}
QLabel& FaultsUI::badMotorPositionHallSequenceLabel2()
{
   return *ui->badMotorPositionHallSequenceLabel2;
}
QLabel& FaultsUI::fifteenVoltRailUnderVoltageLockoutLabel2()
{
   return *ui->fifteenVoltRailUnderVoltageLockoutLabel2;
}
QLabel& FaultsUI::dcBusOverVoltageLabel2()
{
   return *ui->dcBusOverVoltageLabel2;
}
QLabel& FaultsUI::configReadErrorLabel2()
{
   return *ui->configReadErrorLabel2;
}
QLabel& FaultsUI::softwareOverCurrentLabel2()
{
   return *ui->softwareOverCurrentLabel2;
}
QLabel& FaultsUI::watchDogCausedLastResetLabel2()
{
   return *ui->watchDogCausedLastResetLabel2;
}
QLabel& FaultsUI::hardwareOverCurrentLabel2()
{
   return *ui->hardwareOverCurrentLabel2;
}

/* Motor One Limit Flags */
QLabel& FaultsUI::ipmTemperatureOrMotorTemperatureLabel1()
{
   return *ui->ipmTemperatureOrMotorTemperatureLabel1;
}
QLabel& FaultsUI::velocityLabel1()
{
   return *ui->velocityLabel1;
}
QLabel& FaultsUI::busVoltageUpperLimitLabel1()
{
   return *ui->busVoltageUpperLimitLabel1;
}
QLabel& FaultsUI::busVoltageLowerLimitLabel1()
{
   return *ui->busVoltageLowerLimitLabel1;
}
QLabel& FaultsUI::motorCurrentLabel1()
{
   return *ui->motorCurrentLabel1;
}
QLabel& FaultsUI::outputVoltagePwmLabel1()
{
   return *ui->outputVoltagePwmLabel1;
}
QLabel& FaultsUI::busCurrentLabel1()
{
   return *ui->busCurrentLabel1;
}

/* Motor Two Limit Flags */
QLabel& FaultsUI::ipmTemperatureOrMotorTemperatureLabel2()
{
   return *ui->ipmTemperatureOrMotorTemperatureLabel2;
}
QLabel& FaultsUI::velocityLabel2()
{
   return *ui->velocityLabel2;
}
QLabel& FaultsUI::busVoltageUpperLimitLabel2()
{
   return *ui->busVoltageUpperLimitLabel2;
}
QLabel& FaultsUI::busVoltageLowerLimitLabel2()
{
   return *ui->busVoltageLowerLimitLabel2;
}
QLabel& FaultsUI::motorCurrentLabel2()
{
   return *ui->motorCurrentLabel2;
}
QLabel& FaultsUI::outputVoltagePwmLabel2()
{
   return *ui->outputVoltagePwmLabel2;
}
QLabel& FaultsUI::busCurrentLabel2()
{
   return *ui->busCurrentLabel2;
}

/* Battery Error Flags */
QLabel& FaultsUI::cellOverVoltageLabel()
{
   return *ui->cellOverVoltageLabel;
}
QLabel& FaultsUI::cellUnderVoltageLabel()
{
   return *ui->cellUnderVoltageLabel;
}
QLabel& FaultsUI::cellOverTemperatureLabel()
{
   return *ui->cellOverTemperatureLabel;
}
QLabel& FaultsUI::measurementUntrustedLabel()
{
   return *ui->measurementUntrustedLabel;
}
QLabel& FaultsUI::vehicleCommunicationsTimeoutLabel()
{
   return *ui->vehicleCommunicationsTimeoutLabel;
}
QLabel& FaultsUI::bmuInSetupModeLabel()
{
   return *ui->bmuInSetupModeLabel;
}
QLabel& FaultsUI::cmuCanBusPowerStatusLabel()
{
   return *ui->cmuCanBusPowerStatusLabel;
}
QLabel& FaultsUI::packIsolationTestFailureLabel()
{
   return *ui->packIsolationTestFailureLabel;
}
QLabel& FaultsUI::softwareOverCurrentMeasurementNotValidLabel()
{
   return *ui->softwareOverCurrentMeasurementNotValidLabel;
}
QLabel& FaultsUI::can12vSupplyLowLabel()
{
   return *ui->can12vSupplyLowLabel;
}
QLabel& FaultsUI::contactorStuckOrNotEngagedLabel()
{
   return *ui->contactorStuckOrNotEngagedLabel;
}
QLabel& FaultsUI::cmuDetectedExtraCellLabel()
{
   return *ui->cmuDetectedExtraCellLabel;
}
QLabel& FaultsUI::cmuCommunicationsTimeoutLabel()
{
   return *ui->cmuCommunicationsTimeoutLabel;
}

QTextEdit& FaultsUI::historyTextEdit()
{
   return *ui->historyTextEdit;
}
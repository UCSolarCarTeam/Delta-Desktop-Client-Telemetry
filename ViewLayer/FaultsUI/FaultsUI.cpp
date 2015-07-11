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


QLabel& FaultsUI::cellOverVoltageLabel()
{
   return *ui->cellOverVoltageLabel;
}
QLabel& FaultsUI::bmuInSetupModeLabel()
{
   return *ui->bmuInSetupModeLabel;
}
QLabel& FaultsUI::cellOverTemperatureLabel()
{
   return *ui->cellOverTemperatureLabel;
}
QLabel& FaultsUI::softwareOverCurrentMeasurementNotValidLabel()
{
   return *ui->softwareOverCurrentMeasurementNotValidLabel;
}
QLabel& FaultsUI::cellUnderVoltageLabel()
{
   return *ui->cellUnderVoltageLabel;
}
QLabel& FaultsUI::can12vSupplyLowLabel()
{
   return *ui->can12vSupplyLowLabel;
}
QLabel& FaultsUI::vehicleCommunicationsTimeoutLabel()
{
   return *ui->vehicleCommunicationsTimeoutLabel;
}
QLabel& FaultsUI::packIsolationTestFailureLabel()
{
   return *ui->packIsolationTestFailureLabel;
}
QLabel& FaultsUI::contactorStuckOrNotEngagedLabel()
{
   return *ui->contactorStuckOrNotEngagedLabel;
}
QLabel& FaultsUI::cmuCanBusPowerStatusLabel()
{
   return *ui->cmuCanBusPowerStatusLabel;
}
QLabel& FaultsUI::measurementUntrustedLabel()
{
   return *ui->measurementUntrustedLabel;
}
QLabel& FaultsUI::cmuDetectedExtraCellLabel()
{
   return *ui->cmuDetectedExtraCellLabel;
}
QLabel& FaultsUI::ipmTemperatureOrMotorTemperatureLabel()
{
   return *ui->ipmTemperatureOrMotorTemperatureLabel;
}
QLabel& FaultsUI::busVoltageUpperLimitLabel()
{
   return *ui->busVoltageUpperLimitLabel;
}
QLabel& FaultsUI::motorCurrentLabel()
{
   return *ui->motorCurrentLabel;
}
QLabel& FaultsUI::busVoltageLowerLimitLabel()
{
   return *ui->busVoltageLowerLimitLabel;
}
QLabel& FaultsUI::outputVoltagePwmLabel()
{
   return *ui->outputVoltagePwmLabel;
}
QLabel& FaultsUI::busCurrentLabel()
{
   return *ui->busCurrentLabel;
}
QLabel& FaultsUI::velocityLabel()
{
   return *ui->velocityLabel;
}
QLabel& FaultsUI::ipmTemperatureOrMotorTemperatureLabel2()
{
   return *ui->ipmTemperatureOrMotorTemperatureLabel2;
}
QLabel& FaultsUI::busVoltageUpperLimitLabel2()
{
   return *ui->busVoltageUpperLimitLabel2;
}
QLabel& FaultsUI::motorCurrentLabel2()
{
   return *ui->motorCurrentLabel2;
}
QLabel& FaultsUI::busVoltageLowerLimitLabel2()
{
   return *ui->busVoltageLowerLimitLabel2;
}
QLabel& FaultsUI::outputVoltagePwmLabel2()
{
   return *ui->outputVoltagePwmLabel2;
}
QLabel& FaultsUI::busCurrentLabel2()
{
   return *ui->busCurrentLabel2;
}
QLabel& FaultsUI::velocityLabel2()
{
   return *ui->velocityLabel2;
}
QLabel& FaultsUI::desaturationFaultLabel()
{
   return *ui->desaturationFaultLabel;
}
QLabel& FaultsUI::badMotorPositionHallSequenceLabel()
{
   return *ui->badMotorPositionHallSequenceLabel;
}
QLabel& FaultsUI::fifteenVoltRailUnderVoltageLockoutLabel()
{
   return *ui->fifteenVoltRailUnderVoltageLockoutLabel;
}
QLabel& FaultsUI::configReadErrorLabel()
{
   return *ui->configReadErrorLabel;
}
QLabel& FaultsUI::watchDogCausedLastResetLabel()
{
   return *ui->watchDogCausedLastResetLabel;
}
QLabel& FaultsUI::dcBusOverVoltageLabel()
{
   return *ui->dcBusOverVoltageLabel;
}
QLabel& FaultsUI::softwareOverCurrentLabel()
{
   return *ui->softwareOverCurrentLabel;
}
QLabel& FaultsUI::hardwareOverCurrentLabel()
{
   return *ui->hardwareOverCurrentLabel;
}
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
QLabel& FaultsUI::configReadErrorLabel2()
{
   return *ui->configReadErrorLabel2;
}
QLabel& FaultsUI::watchDogCausedLastResetLabel2()
{
   return *ui->watchDogCausedLastResetLabel2;
}
QLabel& FaultsUI::dcBusOverVoltageLabel2()
{
   return *ui->dcBusOverVoltageLabel2;
}
QLabel& FaultsUI::softwareOverCurrentLabel2()
{
   return *ui->softwareOverCurrentLabel2;
}
QLabel& FaultsUI::hardwareOverCurrentLabel2()
{
   return *ui->hardwareOverCurrentLabel2;
}

QLabel& FaultsUI::cmuCommunicationsTimeoutLabel()
{
   return *ui->cmuCommunicationsTimeoutLabel;
}

QTextEdit& FaultsUI::historyTextEdit()
{
   return *ui->historyTextEdit;
}

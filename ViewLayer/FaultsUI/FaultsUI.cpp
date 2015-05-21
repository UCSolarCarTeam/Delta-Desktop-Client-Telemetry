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
   ui->faultsTitleBar->hide();
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

QTextBrowser& FaultsUI::historyTextBrowser()
{
   return *ui->historyTextBrowser;
}

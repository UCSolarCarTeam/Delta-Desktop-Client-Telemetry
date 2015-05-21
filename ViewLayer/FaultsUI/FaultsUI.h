#pragma once

#include "I_FaultsUI.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

namespace Ui {
	class FaultsUI;
}

class FaultsUI : public I_SolarCarWindow, public I_FaultsUI 
{
	Q_OBJECT
public:
    explicit FaultsUI();
    ~FaultsUI();

    void hideHeaderBar();

	QLabel& cellOverVoltageLabel();
	QLabel& bmuInSetupModeLabel();
	QLabel& cellOverTemperatureLabel();
	QLabel& softwareOverCurrentMeasurementNotValidLabel();
	QLabel& cellUnderVoltageLabel();
	QLabel& can12vSupplyLowLabel();
	QLabel& vehicleCommunicationsTimeoutLabel();
	QLabel& packIsolationTestFailureLabel();
	QLabel& contactorStuckOrNotEngagedLabel();
	QLabel& cmuCanBusPowerStatusLabel();
	QLabel& measurementUntrustedLabel();
	QLabel& cmuDetectedExtraCellLabel();
	QLabel& ipmTemperatureOrMotorTemperatureLabel();
	QLabel& busVoltageUpperLimitLabel();
	QLabel& motorCurrentLabel();
	QLabel& busVoltageLowerLimitLabel();
	QLabel& outputVoltagePwmLabel();
	QLabel& busCurrentLabel();
	QLabel& velocityLabel();
	QLabel& desaturationFaultLabel();
	QLabel& badMotorPositionHallSequenceLabel();
	QLabel& fifteenVoltRailUnderVoltageLockoutLabel();
	QLabel& configReadErrorLabel();
	QLabel& watchDogCausedLastResetLabel();
	QLabel& dcBusOverVoltageLabel();
	QLabel& softwareOverCurrentLabel();
	QLabel& hardwareOverCurrentLabel();

	QTextBrowser& historyTextBrowser();

private:
	Ui::FaultsUI *ui;
};


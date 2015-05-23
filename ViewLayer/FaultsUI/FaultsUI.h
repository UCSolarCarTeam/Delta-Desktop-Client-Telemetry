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

    /* Motor Error Flags */
	QLabel& desaturationFaultLabel();
	QLabel& badMotorPositionHallSequenceLabel();
	QLabel& fifteenVoltRailUnderVoltageLockoutLabel();
	QLabel& dcBusOverVoltageLabel();
	QLabel& configReadErrorLabel();
	QLabel& softwareOverCurrentLabel();
	QLabel& watchDogCausedLastResetLabel();
	QLabel& hardwareOverCurrentLabel();

	/* Motor Limit Flags */
	QLabel& ipmTemperatureOrMotorTemperatureLabel();
	QLabel& velocityLabel();
	QLabel& busVoltageUpperLimitLabel();
	QLabel& busVoltageLowerLimitLabel();
	QLabel& motorCurrentLabel();
	QLabel& outputVoltagePwmLabel();
	QLabel& busCurrentLabel();

	/* Battery Error Flags */
	QLabel& cellOverVoltageLabel();
	QLabel& cellUnderVoltageLabel();
	QLabel& cellOverTemperatureLabel();
	QLabel& measurementUntrustedLabel();
	QLabel& vehicleCommunicationsTimeoutLabel();
	QLabel& bmuInSetupModeLabel();
	QLabel& cmuCanBusPowerStatusLabel();
	QLabel& packIsolationTestFailureLabel();
	QLabel& softwareOverCurrentMeasurementNotValidLabel();
	QLabel& can12vSupplyLowLabel();
	QLabel& contactorStuckOrNotEngagedLabel();
	QLabel& cmuDetectedExtraCellLabel();
	QLabel& cmuCommunicationsTimeoutLabel();

	QTextEdit& historyTextEdit();

private:
	Ui::FaultsUI *ui;
};


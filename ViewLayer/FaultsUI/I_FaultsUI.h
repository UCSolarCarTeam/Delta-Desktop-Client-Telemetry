#pragma once

#include <QLabel>
#include <QTextEdit>

class I_FaultsUI
{
public:
	virtual ~I_FaultsUI() {}

	virtual QLabel& cellOverVoltageLabel() = 0;
	virtual QLabel& bmuInSetupModeLabel() = 0;
	virtual QLabel& cellOverTemperatureLabel() = 0;
	virtual QLabel& softwareOverCurrentMeasurementNotValidLabel() = 0;
	virtual QLabel& cellUnderVoltageLabel() = 0;
	virtual QLabel& can12vSupplyLowLabel() = 0;
	virtual QLabel& vehicleCommunicationsTimeoutLabel() = 0;
	virtual QLabel& packIsolationTestFailureLabel() = 0;
	virtual QLabel& contactorStuckOrNotEngagedLabel() = 0;
	virtual QLabel& cmuCanBusPowerStatusLabel() = 0;
	virtual QLabel& measurementUntrustedLabel() = 0;
	virtual QLabel& cmuDetectedExtraCellLabel() = 0;
	virtual QLabel& ipmTemperatureOrMotorTemperatureLabel() = 0;
	virtual QLabel& busVoltageUpperLimitLabel() = 0;
	virtual QLabel& motorCurrentLabel() = 0;
	virtual QLabel& busVoltageLowerLimitLabel() = 0;
	virtual QLabel& outputVoltagePwmLabel() = 0;
	virtual QLabel& busCurrentLabel() = 0;
	virtual QLabel& velocityLabel() = 0;
	virtual QLabel& desaturationFaultLabel() = 0;
	virtual QLabel& badMotorPositionHallSequenceLabel() = 0;
	virtual QLabel& fifteenVoltRailUnderVoltageLockoutLabel() = 0;
	virtual QLabel& configReadErrorLabel() = 0;
	virtual QLabel& watchDogCausedLastResetLabel() = 0;
	virtual QLabel& dcBusOverVoltageLabel() = 0;
	virtual QLabel& softwareOverCurrentLabel() = 0;
	virtual QLabel& hardwareOverCurrentLabel() = 0;

	virtual QLabel& ipmTemperatureOrMotorTemperatureLabel2() = 0;
	virtual QLabel& busVoltageUpperLimitLabel2() = 0;
	virtual QLabel& motorCurrentLabel2() = 0;
	virtual QLabel& busVoltageLowerLimitLabel2() = 0;
	virtual QLabel& outputVoltagePwmLabel2() = 0;
	virtual QLabel& busCurrentLabel2() = 0;
	virtual QLabel& velocityLabel2() = 0;
	virtual QLabel& desaturationFaultLabel2() = 0;
	virtual QLabel& badMotorPositionHallSequenceLabel2() = 0;
	virtual QLabel& fifteenVoltRailUnderVoltageLockoutLabel2() = 0;
	virtual QLabel& configReadErrorLabel2() = 0;
	virtual QLabel& watchDogCausedLastResetLabel2() = 0;
	virtual QLabel& dcBusOverVoltageLabel2() = 0;
	virtual QLabel& softwareOverCurrentLabel2() = 0;
	virtual QLabel& hardwareOverCurrentLabel2() = 0;

	virtual QTextEdit& historyTextEdit() = 0;
};

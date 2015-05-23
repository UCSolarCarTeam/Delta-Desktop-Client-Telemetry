#pragma once

#include <QObject>
class I_VehicleData;

class VehiclePresenter : public QObject
{
	Q_OBJECT
public:
	explicit VehiclePresenter(const I_VehicleData& vehicleData);

private:
	void relayVehicleData();

	const I_VehicleData& vehicleData_;

signals:
    void driverSetSpeedMetersPerSecondReceived(double driverSetSpeedMetersPerSecond);
    void driverSetCurrentReceived(double driverSetCurrent);
    void vehicleVelocityMetersPerSecondReceived(double vehicleVelocityMetersPerSecond);
    void motorVelocityRpmReceived(double motorVelocityRpm);
    void ipmHeatSinkTempReceived(double ipmHeatSinkTemp);
    void dspBoardTempReceived(double dspBoardTemp);
    void receivedErrorCountReceived(double ReceivedErrorCount);
    void transmittedErrorCountReceived(double transmittedErrorCount);
    void busVoltageReceived(double busVoltage);
};
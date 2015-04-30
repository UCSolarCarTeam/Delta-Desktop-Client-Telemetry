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
    void driverSetSpeedRPMReceived(double driverSetSpeedRPM);
    void driverSetCurrentReceived(double driverSetCurrent);
    void vehicleVelocityKphReceived(double vehicleVelocityKph);
    void motorVelocityRpmReceived(double motorVelocityRpm);
    void ipmHeatSinkTempReceived(double ipmHeatSinkTemp);
    void dspBoardTempReceived(double dspBoardTemp);
    void receivedErrorCountReceived(double ReceivedErrorCount);
    void transmittedErrorCountReceived(double transmittedErrorCount);
};
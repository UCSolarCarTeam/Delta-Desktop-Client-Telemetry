#pragma once 

#include <QObject>
#include "../../DataLayer/VehicleData/I_VehicleData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"

class I_VehicleData;
class I_PowerData;
class I_BatteryData;

class PowerGraphsPresenter : I_GraphsPresenter
{
	Q_OBJECT
public:
	explicit PowerGraphsPresenter(const I_VehicleData& vehicleData, 
								  const I_PowerData& powerData, 
								  const I_BatteryData& batteryData);
	void startUpdating();
	void stopUpdating();

public slots:	
	void updateGraphData();

private:
	const I_VehicleData& vehicleData_;
	const I_PowerData& powerData_;
	const I_BatteryData& batteryData_;

signals:
	void busCurrentGraphDataUpdated();
	void busVoltageGraphDataUpdated();
	void busPowerGraphDataUpdated();

	void drivingCurrentGraphDataUpdated();
	void drivingSpeedGraphDataUpdated();

	void cellVoltageGraphDataUpdated();
	void cellTemperatureGraphDataUpdated();
}
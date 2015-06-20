#pragma once 

#include <QObject>
#include "I_PowerGraphsPresenter.h"
#include "../../DataLayer/VehicleData/I_VehicleData.h"
#include "../../DataLayer/PowerData/I_PowerData.h"
#include "../../DataLayer/BatteryData/I_BatteryData.h"
#include <QTimer>
#include "PowerGraphData.h"

class PowerGraphsPresenter : public I_PowerGraphsPresenter
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
	QTimer graphUpdateTimer_;

	const I_VehicleData& vehicleData_;
	const I_PowerData& powerData_;
	const I_BatteryData& batteryData_;

	PowerGraphData busCurrentGraphData_; 
	PowerGraphData busVoltageGraphData_;
	PowerGraphData busPowerGraphData_;
	PowerGraphData driverCurrentGraphData_;
	PowerGraphData driverSpeedGraphData_;
	PowerGraphData batteryCellTempGraphData_;
	PowerGraphData batteryCellVoltageGraphData_;

    const int BUS_CURRENT_DATA_SETS_ = 2;
    const int BUS_VOLTAGE_DATA_SETS_ = 2;
    const int BUS_POWER_DATA_SETS_ = 2;
    const int DRIVER_CURRENT_DATA_SETS_ = 1;
    const int DRIVER_SPEED_DATA_SETS_ = 2;
    const int BATTERY_CELL_TEMP_DATA_SETS_ = 3;
    const int BATTERY_CELL_VOLTAGE_DATA_SETS_ = 3;

	void updateBusCurrentGraphData();
	void updateBusVoltage();
	void updateBusPowerGraphData();
	void updateDriverCurrentGraphData();
	void updateDriverSpeedGraphData();
	void updateBatteryCellTempGraphData();
	void updateBatteryCellVoltageGraphData();

signals:
	void busCurrentGraphDataUpdated(PowerGraphData);
	void busVoltageGraphDataUpdated(PowerGraphData);
	void busPowerGraphDataUpdated(PowerGraphData);

	void drivingCurrentGraphDataUpdated(PowerGraphData);
	void drivingSpeedGraphDataUpdated(PowerGraphData);

	void cellVoltageGraphDataUpdated(PowerGraphData);
	void cellTemperatureGraphDataUpdated(PowerGraphData);
};

#include "PowerGraphsPresenter.h"
#include <QDebug>

namespace
{
   const int BUS_CURRENT_DATA_SETS_ = 1;
   const int BUS_VOLTAGE_DATA_SETS_ = 1;
   const int BUS_POWER_DATA_SETS_ = 1;
   const int DRIVER_CURRENT_DATA_SETS_ = 1;
   const int DRIVER_SPEED_DATA_SETS_ = 2;
   const int BATTERY_CELL_TEMP_DATA_SETS_ = 4;
   const int BATTERY_CELL_VOLTAGE_DATA_SETS_ = 3;
}

PowerGraphsPresenter::PowerGraphsPresenter(const I_VehicleData& vehicleData,
										   const I_PowerData& powerData,
										   const I_BatteryData& batteryData)
: vehicleData_(vehicleData)
, powerData_(powerData)
, batteryData_(batteryData)
{
	const double INTERVAL_SIZE = 1; // seconds
	const int NUMBER_OF_INTERVALS = 60;

	graphUpdateTimer_.setSingleShot(false);
	graphUpdateTimer_.setInterval(INTERVAL_SIZE * 1000); // convert to ms

	connect(&graphUpdateTimer_, SIGNAL(timeout()),
		this, SLOT(updateGraphData()));

	busCurrentGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										  INTERVAL_SIZE,
                                          BUS_CURRENT_DATA_SETS_);
	busVoltageGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
								 		  INTERVAL_SIZE,
                                          BUS_VOLTAGE_DATA_SETS_);
	busPowerGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										INTERVAL_SIZE,
                                        BUS_POWER_DATA_SETS_);
	driverCurrentGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										     INTERVAL_SIZE,
                                             DRIVER_CURRENT_DATA_SETS_);
	driverSpeedGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										   INTERVAL_SIZE,
                                           DRIVER_SPEED_DATA_SETS_);
	batteryCellTempGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										       INTERVAL_SIZE,
                                               BATTERY_CELL_TEMP_DATA_SETS_);
	batteryCellVoltageGraphData_ = PowerGraphData(NUMBER_OF_INTERVALS,
										          INTERVAL_SIZE,
                                                  BATTERY_CELL_VOLTAGE_DATA_SETS_);
}

void PowerGraphsPresenter::startUpdating()
{
	graphUpdateTimer_.start();
}

void PowerGraphsPresenter::stopUpdating()
{
	graphUpdateTimer_.stop();
}

void PowerGraphsPresenter::updateGraphData()
{
	updateBusCurrentGraphData();
	updateBusVoltage();
	updateBusPowerGraphData();
	updateDriverCurrentGraphData();
	updateDriverSpeedGraphData();
	updateBatteryCellTempGraphData();
	updateBatteryCellVoltageGraphData();
}

void PowerGraphsPresenter::updateBusCurrentGraphData()
{
    double busCurrentData [BUS_CURRENT_DATA_SETS_];
	busCurrentData[0] = powerData_.busCurrentA();

	busCurrentGraphData_.addData(busCurrentData);
	emit busCurrentGraphDataUpdated(busCurrentGraphData_);
}

void PowerGraphsPresenter::updateBusVoltage()
{
    double busVoltageData [BUS_VOLTAGE_DATA_SETS_];
	busVoltageData[0] = powerData_.busVoltage();

	busVoltageGraphData_.addData(busVoltageData);
	emit busVoltageGraphDataUpdated(busVoltageGraphData_);
}

void PowerGraphsPresenter::updateBusPowerGraphData()
{
    double busPowerData [BUS_POWER_DATA_SETS_];
	busPowerData[0] = powerData_.busCurrentA() * powerData_.motorCurrentReal();

	busPowerGraphData_.addData(busPowerData);
	emit busPowerGraphDataUpdated(busPowerGraphData_);
}

void PowerGraphsPresenter::updateDriverCurrentGraphData()
{
    double driverCurrentData [DRIVER_CURRENT_DATA_SETS_];
	driverCurrentData[0] = vehicleData_.driverSetCurrent();

	driverCurrentGraphData_.addData(driverCurrentData);
	emit drivingCurrentGraphDataUpdated(driverCurrentGraphData_);
}

void PowerGraphsPresenter::updateDriverSpeedGraphData()
{
    double driverSpeedData [DRIVER_SPEED_DATA_SETS_];
	driverSpeedData[0] = vehicleData_.driverSetSpeedMetersPerSecond();
	driverSpeedData[1] = vehicleData_.vehicleVelocityMetersPerSecond();

	driverSpeedGraphData_.addData(driverSpeedData);
	emit drivingSpeedGraphDataUpdated(driverSpeedGraphData_);
}

void PowerGraphsPresenter::updateBatteryCellTempGraphData()
{
    double batteryCellTempData [BATTERY_CELL_TEMP_DATA_SETS_];
	batteryCellTempData[0] = batteryData_.mod0CellTemperature();
	batteryCellTempData[1] = batteryData_.mod1CellTemperature();
	batteryCellTempData[2] = batteryData_.mod2CellTemperature();
	batteryCellTempData[3] = batteryData_.mod3CellTemperature();

	batteryCellTempGraphData_.addData(batteryCellTempData);
	emit cellTemperatureGraphDataUpdated(batteryCellTempGraphData_);
}

void PowerGraphsPresenter::updateBatteryCellVoltageGraphData()
{
	double maxBatteryCellVoltage = 0;
	double avgBatteryCellVoltage = 0;
	double minBatteryCellVoltage = 0;
    double batteryCellVoltageData [BATTERY_CELL_VOLTAGE_DATA_SETS_];

	QList<double> allBatteryCellVoltages = QList<double>();
	allBatteryCellVoltages.append(batteryData_.mod0CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod1CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod2CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod3CellVoltages());

	if(!allBatteryCellVoltages.empty())
	{
		maxBatteryCellVoltage = allBatteryCellVoltages[0];
		minBatteryCellVoltage = allBatteryCellVoltages[0];
	}

	foreach(double batteryCellVoltage, allBatteryCellVoltages)
	{
		if(maxBatteryCellVoltage < batteryCellVoltage){
			maxBatteryCellVoltage = batteryCellVoltage;
		}
		if(minBatteryCellVoltage > batteryCellVoltage){
			minBatteryCellVoltage = batteryCellVoltage;
		}
		avgBatteryCellVoltage += batteryCellVoltage;
	}
	avgBatteryCellVoltage /= 32.0; // for number of batteryCellVoltages

	batteryCellVoltageData[0] = maxBatteryCellVoltage * 1000; // convert to milliVolts from volts
	batteryCellVoltageData[1] = avgBatteryCellVoltage * 1000; // convert to milliVolts from volts
	batteryCellVoltageData[2] = minBatteryCellVoltage * 1000; // convert to milliVolts from volts
	batteryCellVoltageGraphData_.addData(batteryCellVoltageData);
	emit cellVoltageGraphDataUpdated(batteryCellVoltageGraphData_);
}

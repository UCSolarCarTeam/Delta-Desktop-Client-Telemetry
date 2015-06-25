#include "PowerGraphsPresenter.h"

namespace
{
   const int BUS_CURRENT_DATA_SETS_ = 2;
   const int BUS_VOLTAGE_DATA_SETS_ = 2;
   const int BUS_POWER_DATA_SETS_ = 2;
   const int DRIVER_CURRENT_DATA_SETS_ = 1;
   const int DRIVER_SPEED_DATA_SETS_ = 2;
   const int BATTERY_CELL_TEMP_DATA_SETS_ = 3;
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

	busCurrentGraphData_ = PowerGraphData(INTERVAL_SIZE,
										  NUMBER_OF_INTERVALS,
                                          BUS_CURRENT_DATA_SETS_);
	busVoltageGraphData_ = PowerGraphData(INTERVAL_SIZE,
								 		  NUMBER_OF_INTERVALS,
                                          BUS_VOLTAGE_DATA_SETS_);
	busPowerGraphData_ = PowerGraphData(INTERVAL_SIZE,
										NUMBER_OF_INTERVALS,
                                        BUS_POWER_DATA_SETS_);
	driverCurrentGraphData_ = PowerGraphData(INTERVAL_SIZE,
										     NUMBER_OF_INTERVALS,
                                             DRIVER_CURRENT_DATA_SETS_);
	driverSpeedGraphData_ = PowerGraphData(INTERVAL_SIZE,
										   NUMBER_OF_INTERVALS,
                                           DRIVER_SPEED_DATA_SETS_);
	batteryCellTempGraphData_ = PowerGraphData(INTERVAL_SIZE,
										       NUMBER_OF_INTERVALS,
                                               BATTERY_CELL_TEMP_DATA_SETS_);
	batteryCellVoltageGraphData_ = PowerGraphData(INTERVAL_SIZE,
										          NUMBER_OF_INTERVALS,
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
	double maxBatteryCellTemp = batteryData_.mod0CellTemperature();
	double avgBatteryCellTemp = 0;
	double minBatteryCellTemp = batteryData_.mod0CellTemperature();
    double batteryCellTempData [BATTERY_CELL_TEMP_DATA_SETS_];

	QList<double> allBatteryCellTemps = QList<double>();
	allBatteryCellTemps.append(batteryData_.mod0CellTemperature());
	allBatteryCellTemps.append(batteryData_.mod1CellTemperature());
	allBatteryCellTemps.append(batteryData_.mod2CellTemperature());
	allBatteryCellTemps.append(batteryData_.mod3CellTemperature());

	foreach(double batteryCellTemp, allBatteryCellTemps)
	{
		if(batteryCellTemp < maxBatteryCellTemp){
			maxBatteryCellTemp = batteryCellTemp;
		}
		if(minBatteryCellTemp > batteryCellTemp){
			minBatteryCellTemp = batteryCellTemp;
		}
		avgBatteryCellTemp += batteryCellTemp;
	}
	avgBatteryCellTemp /= 4.0; // number of batteryCellTemps

	batteryCellTempData[0] = maxBatteryCellTemp;
	batteryCellTempData[1] = avgBatteryCellTemp;
	batteryCellTempData[2] = minBatteryCellTemp;

	batteryCellTempGraphData_.addData(batteryCellTempData);
	emit cellVoltageGraphDataUpdated(batteryCellTempGraphData_);
}

void PowerGraphsPresenter::updateBatteryCellVoltageGraphData()
{
	double maxBatteryCellVoltage = batteryData_.mod0CellVoltages()[0];
	double avgBatteryCellVoltage = 0;
	double minBatteryCellVoltage = batteryData_.mod0CellVoltages()[0];
    double batteryCellVoltageData [BATTERY_CELL_VOLTAGE_DATA_SETS_];

	QList<double> allBatteryCellVoltages = QList<double>();
	allBatteryCellVoltages.append(batteryData_.mod0CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod1CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod2CellVoltages());
	allBatteryCellVoltages.append(batteryData_.mod3CellVoltages());

	foreach(double batteryCellVoltage, allBatteryCellVoltages)
	{
		if(batteryCellVoltage < maxBatteryCellVoltage){
			maxBatteryCellVoltage = batteryCellVoltage;
		}
		if(minBatteryCellVoltage > batteryCellVoltage){
			minBatteryCellVoltage = batteryCellVoltage;
		}
		avgBatteryCellVoltage += batteryCellVoltage;
	}
	avgBatteryCellVoltage /= 32.0; // for number of batteryCellVoltages

	batteryCellVoltageData[0] = maxBatteryCellVoltage;
	batteryCellVoltageData[1] = avgBatteryCellVoltage;
	batteryCellVoltageData[2] = minBatteryCellVoltage;

	batteryCellVoltageGraphData_.addData(batteryCellVoltageData);
	emit cellTemperatureGraphDataUpdated(batteryCellVoltageGraphData_);
}

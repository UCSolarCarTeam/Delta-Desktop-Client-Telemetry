#pragma once

#include <QSharedPointer>
#include <QSerialPort>

class I_ConnectionService;
class I_DataParser;
class I_ArrayData;
class I_VehicleData;
class I_PowerData;
class I_BatteryData;
class DataPopulator;

class DataContainer
{
public:
    QSharedPointer<I_ArrayData> arrayData();
    QSharedPointer<I_PowerData> powerData();
    QSharedPointer<I_VehicleData> vehicleData();
    QSharedPointer<I_BatteryData> batteryData();

 	explicit DataContainer();
    ~DataContainer();

private:
	QSharedPointer<I_ArrayData> arrayData_;
	QSharedPointer<I_VehicleData> vehicleData_; 
	QSharedPointer<I_PowerData> powerData_;
	QSharedPointer<I_BatteryData> batteryData_;
};


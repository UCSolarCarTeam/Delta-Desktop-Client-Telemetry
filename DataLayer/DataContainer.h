#pragma once

#include <QSharedPointer>
#include <QSerialPort>

class DataParser;
class I_ConnectionService;
class ArrayData;
class VehicleData;
class PowerData;
class BatteryData;
class DataPopulator;

class DataContainer
{
public:
    QSharedPointer<QSerialPort> port();
    QSharedPointer<I_ConnectionService> connectionService();
    QSharedPointer<DataParser> dataParser();
    QSharedPointer<DataPopulator> dataPopulator();
    QSharedPointer<ArrayData> arrayData();
    QSharedPointer<PowerData> powerData();
    QSharedPointer<VehicleData> vehicleData();
    QSharedPointer<BatteryData> batteryData();

 	explicit DataContainer();
    ~DataContainer();

private:
    QSharedPointer<QSerialPort> port_;
    QSharedPointer<I_ConnectionService> connectionService_;
	QSharedPointer<DataParser> dataParser_;
	QSharedPointer<ArrayData> arrayData_;
	QSharedPointer<VehicleData> vehicleData_; 
	QSharedPointer<PowerData> powerData_;
	QSharedPointer<BatteryData> batteryData_;
    QSharedPointer<DataPopulator> dataPopulator_;

};


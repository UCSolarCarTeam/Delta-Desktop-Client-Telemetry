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
   PowerGraphData batteryPowerGraphData_;

   void updateBusCurrentGraphData();
   void updateBusVoltage();
   void updateBusPowerGraphData();
   void updateDriverCurrentGraphData();
   void updateDriverSpeedGraphData();
   void updateBatteryCellTempGraphData();
   void updateBatteryCellVoltageGraphData();
   void updateBatteryPowerGraphData();

signals:
   void busCurrentGraphDataUpdated(PowerGraphData);
   void busVoltageGraphDataUpdated(PowerGraphData);
   void busPowerGraphDataUpdated(PowerGraphData);

   void drivingCurrentGraphDataUpdated(PowerGraphData);
   void drivingSpeedGraphDataUpdated(PowerGraphData);

   void cellTemperatureGraphDataUpdated(PowerGraphData);
   void cellVoltageGraphDataUpdated(PowerGraphData);
   void batteryPowerGraphUpdated(PowerGraphData);
};

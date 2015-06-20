#pragma once
#include "../../PresenterLayer/GraphsPresenter/PowerGraphData.h"
#include <QObject>

class DisplayPresenter;
class BatteryPresenter;
class VehiclePresenter;
class PowerGraphsPresenter;
class PowerUI;
class PowerGraphData;

class PowerView : public QObject
{
   Q_OBJECT
public:
   PowerView(DisplayPresenter& presenter,
             BatteryPresenter& batteryPresenter,
             VehiclePresenter& vehiclePresenter,
             PowerGraphsPresenter& graphsPresenter_,
             PowerUI& ui);
   ~PowerView();

private:
   DisplayPresenter& presenter_;
   BatteryPresenter& batteryPresenter_;
   VehiclePresenter& vehiclePresenter_;
   PowerGraphsPresenter& graphsPresenter_;
   PowerUI& ui_;
   
private slots:
   void driverSetSpeedMetersPerSecondReceived(double);
   void driverSetCurrentReceived(double);
   void vehicleVelocityMetersPerSecondReceived(double);
   void busCurrentAReceived(double);
   void busVoltageReceived(double);
   void arrayCurrentReceived(double);

   void mod0CellTemperatureReceived(double);
   void mod0CellVoltagesReceived(QList<double>);
   void mod1CellTemperatureReceived(double);
   void mod1CellVoltagesReceived(QList<double>);
   void mod2CellTemperatureReceived(double);
   void mod2CellVoltagesReceived(QList<double>);
   void mod3CellTemperatureReceived(double);
   void mod3CellVoltagesReceived(QList<double>);

   void updateBusCurrentGraph(PowerGraphData);
   void updateBusVoltageGraph(PowerGraphData);
   void updateBusPowerGraph(PowerGraphData);
   void updateDriverCurrentGraph(PowerGraphData);
   void updateDriverSpeedGraph(PowerGraphData);
   void updateBatteryCellTempGraph(PowerGraphData);
   void updateBatteryCellVoltageGraph(PowerGraphData);

   void handleConnectButtonClicked();
   void handleBusGraphButtonClicked();
   void handleDriverGraphButtonClicked();
   void handleBatteryGraphButtonClicked();
   void connectionFailed(QString);
   void connectionSucceeded(QString);
   void clearDebugLog();
};

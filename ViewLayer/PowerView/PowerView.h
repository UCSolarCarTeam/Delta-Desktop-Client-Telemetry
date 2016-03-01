#pragma once
#include "PresenterLayer/GraphsPresenter/PowerGraphData.h"
#include <QObject>
#include <QLabel>
#include <QPushButton>

class BatteryPresenter;
class VehiclePresenter;
class PowerPresenter;
class PowerGraphsPresenter;
class CommunicationPresenter;
class PowerUI;
class PowerGraphData;

class PowerView : public QObject
{
   Q_OBJECT
public:
   PowerView(BatteryPresenter& batteryPresenter,
             VehiclePresenter& vehiclePresenter,
             PowerPresenter& powerPresenter,
             PowerGraphsPresenter& graphsPresenter,
             CommunicationPresenter& communicationPresenter,
             PowerUI& ui);
   ~PowerView() {}

private:
   bool isValuesGarbage(QList<double>);

   BatteryPresenter& batteryPresenter_;
   VehiclePresenter& vehiclePresenter_;
   PowerPresenter& powerPresenter_;
   PowerGraphsPresenter& graphsPresenter_;
   CommunicationPresenter& communicationPresenter_;
   PowerUI& ui_;


private slots:
   void driverSetSpeedMetersPerSecondReceived(double);
   void driverSetCurrentReceived(double);
   void vehicleVelocityMetersPerSecondReceived(double);
   void busCurrentAReceived(double);
   void busVoltageReceived(double);
   void batteryCurrentReceived(double);
   void batteryVoltageReceived(double);

   void mod0CellTemperatureReceived(double);
   void mod0CellVoltagesReceived(QList<double>);
   void mod1CellTemperatureReceived(double);
   void mod1CellVoltagesReceived(QList<double>);
   void mod2CellTemperatureReceived(double);
   void mod2CellVoltagesReceived(QList<double>);
   void mod3CellTemperatureReceived(double);
   void mod3CellVoltagesReceived(QList<double>);
   void highlightMinMaxVoltages();
   void highlightUntrustedVoltages();

   void updateBusCurrentGraph(PowerGraphData);
   void updateBusVoltageGraph(PowerGraphData);
   void updateBusPowerGraph(PowerGraphData);
   void updateDriverCurrentGraph(PowerGraphData);
   void updateDriverSpeedGraph(PowerGraphData);
   void updateBatteryCellTempGraph(PowerGraphData);
   void updateBatteryCellVoltageGraph(PowerGraphData);
   void updateBatteryPowerGraph(PowerGraphData);

   void secondsSinceLastPacketUpdated(int);
   void packetInLastMinuteUpdated(int);
   void secondsSinceLastValidPacketUpdated(int);
   void validPacketsInLastMinuteUpdated(int);
   void invalidPacketsInLastMinuteUpdated(int);

   void handleConnectButtonClicked();
   void handleBusGraphButtonClicked();
   void handleDriverGraphButtonClicked();
   void handleBatteryGraphButtonClicked();
   void selectGraphButton(QPushButton*);
   void toggleSerialParameters(QString);
   void connectionFailed(QString);
   void connectionSucceeded();
};

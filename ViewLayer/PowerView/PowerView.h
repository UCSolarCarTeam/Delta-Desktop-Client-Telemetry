#pragma once

#include <QObject>

class DisplayPresenter;
class BatteryPresenter;
class VehiclePresenter;
class PowerUI;

class PowerView : public QObject
{
   Q_OBJECT
public:
   PowerView(DisplayPresenter& presenter,
             BatteryPresenter& batteryPresenter,
             VehiclePresenter& vehiclePresenter,
             PowerUI& ui);
   ~PowerView();

private:
   DisplayPresenter& presenter_;
   BatteryPresenter& batteryPresenter_;
   VehiclePresenter& vehiclePresenter_;
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

   void handleGraph1Selected();
   void handleGraph2Selected();
   void handleGraph3Selected();

   void handleConnectButtonClicked();
   // void handleDisconnectButtonClicked();
   void connectionFailed(QString);
   void connectionSucceeded(QString);
   void clearDebugLog();
};

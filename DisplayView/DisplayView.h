#pragma once

#include <QObject>

class DisplayPresenter;
class SolarCarTestUI;

class DisplayView : public QObject
{
   Q_OBJECT
public:
   DisplayView(class DisplayPresenter& presenter, class SolarCarTestUI& ui);
   ~DisplayView();


   
private:
   DisplayPresenter& presenter_;
   SolarCarTestUI& ui_;

private slots:
   void driverSetSpeedRPMReceived(double);
   void driverSetCurrentReceived(double);

   void vehicleVelocityKphReceived(double);
   void busCurrentAReceived(double);
   void busVoltageReceived(double);

   void mod0CellTemperatureReceived(double);
   void mod0CellVoltage0Received(double);
   void mod0CellVoltage1Received(double);
   void mod0CellVoltage2Received(double);
   void mod0CellVoltage3Received(double);
   void mod0CellVoltage4Received(double);
   void mod0CellVoltage5Received(double);
   void mod0CellVoltage6Received(double);
   void mod0CellVoltage7Received(double);

   void mod1CellTemperatureReceived(double);
   void mod1CellVoltage0Received(double);
   void mod1CellVoltage1Received(double);
   void mod1CellVoltage2Received(double);
   void mod1CellVoltage3Received(double);
   void mod1CellVoltage4Received(double);
   void mod1CellVoltage5Received(double);
   void mod1CellVoltage6Received(double);
   void mod1CellVoltage7Received(double);

   void mod2CellTemperatureReceived(double);
   void mod2CellVoltage0Received(double);
   void mod2CellVoltage1Received(double);
   void mod2CellVoltage2Received(double);
   void mod2CellVoltage3Received(double);
   void mod2CellVoltage4Received(double);
   void mod2CellVoltage5Received(double);
   void mod2CellVoltage6Received(double);
   void mod2CellVoltage7Received(double);

   void mod3CellTemperatureReceived(double);
   void mod3CellVoltage0Received(double);
   void mod3CellVoltage1Received(double);
   void mod3CellVoltage2Received(double);
   void mod3CellVoltage3Received(double);
   void mod3CellVoltage4Received(double);
   void mod3CellVoltage5Received(double);
   void mod3CellVoltage6Received(double);
   void mod3CellVoltage7Received(double);

   void handleConnectButtonClicked();
   void handleDisconnectButtonClicked();
   void connectionFailed(QString);
   void connectionSucceeded(QString);
   void clearDebugLog();
   void writeToDebugLog(QString);
};

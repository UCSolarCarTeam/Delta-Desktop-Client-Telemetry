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

           void mod0PcbTemperatureReceived(int);
           void mod0CellVoltage0Received(int);
           void mod0CellVoltage1Received(int);
           void mod0CellVoltage2Received(int);
           void mod0CellVoltage3Received(int);
           void mod0CellVoltage4Received(int);
           void mod0CellVoltage5Received(int);
           void mod0CellVoltage6Received(int);
           void mod0CellVoltage7Received(int);

           void mod1PcbTemperatureReceived(int);
           void mod1CellVoltage0Received(int);
           void mod1CellVoltage1Received(int);
           void mod1CellVoltage2Received(int);
           void mod1CellVoltage3Received(int);
           void mod1CellVoltage4Received(int);
           void mod1CellVoltage5Received(int);
           void mod1CellVoltage6Received(int);
           void mod1CellVoltage7Received(int);

           void mod2PcbTemperatureReceived(int);
           void mod2CellVoltage0Received(int);
           void mod2CellVoltage1Received(int);
           void mod2CellVoltage2Received(int);
           void mod2CellVoltage3Received(int);
           void mod2CellVoltage4Received(int);
           void mod2CellVoltage5Received(int);
           void mod2CellVoltage6Received(int);
           void mod2CellVoltage7Received(int);

           void mod3PcbTemperatureReceived(int);
           void mod3CellVoltage0Received(int);
           void mod3CellVoltage1Received(int);
           void mod3CellVoltage2Received(int);
           void mod3CellVoltage3Received(int);
           void mod3CellVoltage4Received(int);
           void mod3CellVoltage5Received(int);
           void mod3CellVoltage6Received(int);
           void mod3CellVoltage7Received(int);

};

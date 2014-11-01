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

   driverSetSpeedRPMReceived(double);

   void DriverSetSpeedRPM(double);
   void DriverSetCurrent(double);

   void VehicleVelocityKph(double);
   void BusCurrentA(double);
   void BusVoltage(double);

   void Mod0PcbTemperature(double);

   void Mod0CellVoltage0(double);
   void Mod0CellVoltage1(double);
   void Mod0CellVoltage2(double);
   void Mod0CellVoltage3(double);
   void Mod0CellVoltage4(double);
   void Mod0CellVoltage5(double);
   void Mod0CellVoltage6(double);
   void Mod0CellVoltage7(double);

   void Mod1PcbTemperature(double);

   void Mod1CellVoltage0(double);
   void Mod1CellVoltage1(double);
   void Mod1CellVoltage2(double);
   void Mod1CellVoltage3(double);
   void Mod1CellVoltage4(double);
   void Mod1CellVoltage5(double);
   void Mod1CellVoltage6(double);
   void Mod1CellVoltage7(double);

   void Mod2PcbTemperature(double);

   void Mod2CellVoltage0(double);
   void Mod2CellVoltage1(double);
   void Mod2CellVoltage2(double);
   void Mod2CellVoltage3(double);
   void Mod2CellVoltage4(double);
   void Mod2CellVoltage5(double);
   void Mod2CellVoltage6(double);
   void Mod2CellVoltage7(double);

   void Mod3PcbTemperature(double);

   void Mod3CellVoltage0(double);
   void Mod3CellVoltage1(double);
   void Mod3CellVoltage2(double);
   void Mod3CellVoltage3(double);
   void Mod3CellVoltage4(double);
   void Mod3CellVoltage5(double);
   void Mod3CellVoltage6(double);
   void Mod3CellVoltage7(double);




};

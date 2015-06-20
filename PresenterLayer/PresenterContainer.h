#pragma once

#include <QScopedPointer>

class DataContainer;
class CommunicationContainer;
class BusinessContainer;
class DisplayPresenter;
class BatteryPresenter;
class VehiclePresenter;
class MpptPresenter;
class FaultsPresenter;
class PowerGraphsPresenter;

class PresenterContainer
{
public:
   PresenterContainer(DataContainer& dataContainer,
         CommunicationContainer& communicationContainer,
         BusinessContainer& businessContainer);
   ~PresenterContainer();

   DisplayPresenter& displayPresenter();
   BatteryPresenter& batteryPresenter();
   VehiclePresenter& vehiclePresenter();
   MpptPresenter& mpptPresenter();
   FaultsPresenter& faultsPresenter();
   PowerGraphsPresenter& powerGraphsPresenter();

private:
   QScopedPointer<DisplayPresenter> displayPresenter_;
   QScopedPointer<BatteryPresenter> batteryPresenter_;
   QScopedPointer<VehiclePresenter> vehiclePresenter_;
   QScopedPointer<MpptPresenter> mpptPresenter_;
   QScopedPointer<FaultsPresenter> faultsPresenter_;
   QScopedPointer<PowerGraphsPresenter> powerGraphsPresenter_;
};

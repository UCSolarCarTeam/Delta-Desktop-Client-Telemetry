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

private:
   QScopedPointer<DisplayPresenter> displayPresenter_;
   QScopedPointer<BatteryPresenter> batteryPresenter_;
   QScopedPointer<VehiclePresenter> vehiclePresenter_;
   QScopedPointer<MpptPresenter> mpptPresenter_;
   QScopedPointer<FaultsPresenter> faultsPresenter_;
};

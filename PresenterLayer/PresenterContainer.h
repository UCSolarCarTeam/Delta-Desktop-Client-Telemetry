#pragma once

#include <QScopedPointer>

class BatteryPresenter;
class BusinessContainer;
class CommunicationContainer;
class CommunicationPresenter;
class DataContainer;
class DisplayPresenter;
class FaultsPresenter;
class MpptPresenter;
class PlaybackPresenter;
class PowerGraphsPresenter;
class PowerPresenter;
class VehiclePresenter;

class PresenterContainer
{
public:
   PresenterContainer(DataContainer& dataContainer,
         CommunicationContainer& communicationContainer,
         BusinessContainer& businessContainer);
   ~PresenterContainer();

   BatteryPresenter& batteryPresenter();
   CommunicationPresenter& communicationPresenter();
   VehiclePresenter& vehiclePresenter();
   MpptPresenter& mpptPresenter();
   PowerPresenter& powerPresenter();
   FaultsPresenter& faultsPresenter();
   PowerGraphsPresenter& powerGraphsPresenter();
   PlaybackPresenter& playbackPresenter();

private:
   QScopedPointer<BatteryPresenter> batteryPresenter_;
   QScopedPointer<CommunicationPresenter> communicationPresenter_;
   QScopedPointer<VehiclePresenter> vehiclePresenter_;
   QScopedPointer<MpptPresenter> mpptPresenter_;
   QScopedPointer<PowerPresenter> powerPresenter_;
   QScopedPointer<FaultsPresenter> faultsPresenter_;
   QScopedPointer<PowerGraphsPresenter> powerGraphsPresenter_;
   QScopedPointer<PlaybackPresenter> playbackPresenter_;
};

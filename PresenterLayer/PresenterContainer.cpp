#include "BatteryPresenter/BatteryPresenter.h"
#include "BusinessLayer/BusinessContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "DataLayer/DataContainer.h"
#include "DisplayPresenter/DisplayPresenter.h"
#include "MpptPresenter/MpptPresenter.h"
#include "PresenterContainer.h"
#include "VehiclePresenter/VehiclePresenter.h"

PresenterContainer::PresenterContainer(DataContainer& dataContainer,
      CommunicationContainer& communicationContainer,
      BusinessContainer& businessContainer)
: displayPresenter_(new DisplayPresenter(dataContainer.powerData(),
      communicationContainer.connectionService(),
      businessContainer.loggerService()))
, batteryPresenter_(new BatteryPresenter(dataContainer.batteryData()))
, vehiclePresenter_(new VehiclePresenter(dataContainer.vehicleData()))
, mpptPresenter_(new MpptPresenter(dataContainer.arrayData()))
{
}

PresenterContainer::~PresenterContainer()
{
}

DisplayPresenter& PresenterContainer::displayPresenter()
{
   return *displayPresenter_;
}

BatteryPresenter& PresenterContainer::batteryPresenter()
{
   return *batteryPresenter_;
}

VehiclePresenter& PresenterContainer::vehiclePresenter()
{
   return *vehiclePresenter_;
}

MpptPresenter& PresenterContainer::mpptPresenter()
{
   return *mpptPresenter_;
}

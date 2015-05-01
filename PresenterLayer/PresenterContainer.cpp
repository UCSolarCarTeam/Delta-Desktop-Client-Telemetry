#include "PresenterContainer.h"

#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "DisplayPresenter/DisplayPresenter.h"
#include "BatteryPresenter/BatteryPresenter.h"
#include "VehiclePresenter/VehiclePresenter.h"
#include "MpptPresenter/MpptPresenter.h"

PresenterContainer::PresenterContainer(QSharedPointer<DataContainer> dataContainer,
									   QSharedPointer<CommunicationContainer> communicationContainer,
									   QSharedPointer<BusinessContainer> businessContainer)
: dataContainer_(dataContainer)
, communicationContainer_(communicationContainer)
, businessContainer_(businessContainer)
, displayPresenter_(new DisplayPresenter(*(dataContainer->powerData()),
										 *(communicationContainer->connectionService()),
										 *(businessContainer->loggerService())))
, batteryPresenter_(new BatteryPresenter(*(dataContainer->batteryData())))
, vehiclePresenter_(new VehiclePresenter(*(dataContainer->vehicleData())))
, mpptPresenter_(new MpptPresenter(*(dataContainer->arrayData())))
{
}

QSharedPointer<DisplayPresenter> PresenterContainer::displayPresenter()
{
	return displayPresenter_;
}

QSharedPointer<BatteryPresenter> PresenterContainer::batteryPresenter()
{
	return batteryPresenter_;
}

QSharedPointer<VehiclePresenter> PresenterContainer::vehiclePresenter()
{
	return vehiclePresenter_;
}

QSharedPointer<MpptPresenter> PresenterContainer::mpptPresenter()
{
	return mpptPresenter_;
}

PresenterContainer::~PresenterContainer()
{
}


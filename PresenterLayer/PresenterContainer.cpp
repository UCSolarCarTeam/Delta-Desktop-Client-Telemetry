#include "PresenterContainer.h"

#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "DisplayPresenter/DisplayPresenter.h"
#include "BatteryPresenter/BatteryPresenter.h"

PresenterContainer::PresenterContainer(QSharedPointer<DataContainer> dataContainer,
									   QSharedPointer<CommunicationContainer> communicationContainer,
									   QSharedPointer<BusinessContainer> businessContainer)
: dataContainer_(dataContainer)
, communicationContainer_(communicationContainer)
, businessContainer_(businessContainer)
, displayPresenter_(new DisplayPresenter(*(dataContainer->arrayData()),
										 *(dataContainer->powerData()),
										 *(dataContainer->vehicleData()),
										 *(communicationContainer->connectionService()),
										 *(businessContainer->loggerService())))
, batteryPresenter_(new BatteryPresenter(*(dataContainer->batteryData())))
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

PresenterContainer::~PresenterContainer()
{
}


#include "PresenterContainer.h"

#include "DataLayer/DataContainer.h"
#include "CommunicationLayer/CommunicationContainer.h"
#include "BusinessLayer/BusinessContainer.h"
#include "DisplayPresenter/DisplayPresenter.h"

PresenterContainer::PresenterContainer(QSharedPointer<DataContainer> dataContainer,
									   QSharedPointer<CommunicationContainer> communicationContainer,
									   QSharedPointer<BusinessContainer> businessContainer)
: dataContainer_(dataContainer)
, communicationContainer_(communicationContainer)
, businessContainer_(businessContainer)
, displayPresenter_(new DisplayPresenter(*(dataContainer->arrayData()),
										 *(dataContainer->powerData()),
										 *(dataContainer->vehicleData()),
										 *(dataContainer->batteryData()),
										 *(communicationContainer->connectionService()),
										 *(businessContainer->loggerService())))
{
}

QSharedPointer<DisplayPresenter> PresenterContainer::displayPresenter()
{
	return displayPresenter_;
}

PresenterContainer::~PresenterContainer()
{
}


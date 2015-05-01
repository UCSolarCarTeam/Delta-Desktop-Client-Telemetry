#pragma once

#include <QSharedPointer>

class DataContainer;
class CommunicationContainer;
class BusinessContainer;
class DisplayPresenter;
class BatteryPresenter;
class VehiclePresenter;
class MpptPresenter;

class PresenterContainer
{
public:
	QSharedPointer<DisplayPresenter> displayPresenter();
	QSharedPointer<BatteryPresenter> batteryPresenter();
	QSharedPointer<VehiclePresenter> vehiclePresenter();
	QSharedPointer<MpptPresenter> mpptPresenter();

    explicit PresenterContainer(QSharedPointer<DataContainer> dataContainer,
    							QSharedPointer<CommunicationContainer> communicationContainer,
    							QSharedPointer<BusinessContainer> businessContainer);
    ~PresenterContainer();

private:
	QSharedPointer<DataContainer> dataContainer_;
	QSharedPointer<CommunicationContainer> communicationContainer_;
	QSharedPointer<BusinessContainer> businessContainer_;
	QSharedPointer<DisplayPresenter> displayPresenter_;
	QSharedPointer<BatteryPresenter> batteryPresenter_;
	QSharedPointer<VehiclePresenter> vehiclePresenter_;
	QSharedPointer<MpptPresenter> mpptPresenter_;
};


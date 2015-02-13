#pragma once

#include <QSharedPointer>

class DataContainer;
class CommunicationContainer;
class BusinessContainer;
class DisplayPresenter;

class PresenterContainer
{
public:
	QSharedPointer<DisplayPresenter> displayPresenter();

    explicit PresenterContainer(QSharedPointer<DataContainer> dataContainer,
    							QSharedPointer<CommunicationContainer> communicationContainer,
    							QSharedPointer<BusinessContainer> businessContainer);
    ~PresenterContainer();

private:
	QSharedPointer<DataContainer> dataContainer_;
	QSharedPointer<CommunicationContainer> communicationContainer_;
	QSharedPointer<BusinessContainer> businessContainer_;
	QSharedPointer<DisplayPresenter> displayPresenter_;
};


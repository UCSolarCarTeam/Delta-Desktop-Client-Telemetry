#pragma once

#include <QSharedPointer>

class PresenterContainer;
class PowerUI;
class SolarCarTestUI;
class DisplayView;

class ViewContainer
{
public:
	QSharedPointer<PowerUI> powerWidget();
	QSharedPointer<SolarCarTestUI> mainWindow();
	QSharedPointer<DisplayView> displayView();

    explicit ViewContainer(QSharedPointer<PresenterContainer> presenterContainer);
    ~ViewContainer();

private:
	QSharedPointer<PresenterContainer> presenterContainer_;
	QSharedPointer<PowerUI> powerWidget_; 
	QSharedPointer<SolarCarTestUI> mainWindow_;
	QSharedPointer<DisplayView> displayView_;
};


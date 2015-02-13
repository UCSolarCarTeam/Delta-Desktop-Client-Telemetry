#pragma once

#include <QSharedPointer>

class PresenterContainer;
class SolarCarTestUI;
class DisplayView;

class ViewContainer
{
public:
	QSharedPointer<SolarCarTestUI> mainWindow();
	QSharedPointer<DisplayView> displayView();

    explicit ViewContainer(QSharedPointer<PresenterContainer> presenterContainer);
    ~ViewContainer();

private:
	QSharedPointer<PresenterContainer> presenterContainer_;
	QSharedPointer<SolarCarTestUI> mainWindow_;
	QSharedPointer<DisplayView> displayView_;
};


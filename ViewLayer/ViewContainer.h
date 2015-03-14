#pragma once

#include <QSharedPointer>

class PresenterContainer;
class PowerUI;
class DisplayView;

class ViewContainer
{
public:
	QSharedPointer<PowerUI> mainWindow();
	QSharedPointer<DisplayView> displayView();

    explicit ViewContainer(QSharedPointer<PresenterContainer> presenterContainer);
    ~ViewContainer();

private:
	QSharedPointer<PresenterContainer> presenterContainer_;
	QSharedPointer<PowerUI> mainWindow_;
	QSharedPointer<DisplayView> displayView_;
};


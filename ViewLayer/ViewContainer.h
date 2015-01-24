#pragma once

#include <QScopedPointer>

class SolarCarTestUI;
class DisplayView;
class PresenterContainer;

class ViewContainer
{
public:
	SolarCarTestUI& mainWindow();
	DisplayView& displayView();

    explicit ViewContainer();
    ~ViewContainer();

private:
	QScopedPointer<PresenterContainer> presenterLayer_;
	QScopedPointer<SolarCarTestUI> mainWindow_;
	QScopedPointer<DisplayView> displayView_;
};


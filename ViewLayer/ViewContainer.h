#pragma once

#include <QScopedPointer>
class SolarCarTestUI;
class DisplayView;

class ViewContainer
{
public:
    explicit ViewContainer();
    ~ViewContainer();

private:
	QScopedPointer<SolarCarTestUI> mainWindow_;
	QScopedPointer<DisplayView> displayView_;
};


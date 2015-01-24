#pragma once

#include <QScopedPointer>

class DisplayPresenter;

class PresenterContainer
{
public:
    PresenterContainer();
    ~PresenterContainer();

private:
	QScopedPointer<DisplayPresenter> displayPresenter_;
};


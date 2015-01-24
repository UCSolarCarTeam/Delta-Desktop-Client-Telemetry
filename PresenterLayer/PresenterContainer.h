#pragma once

#include <QScopedPointer>

class BusinessContainer;
class DisplayPresenter;

class PresenterContainer
{
public:
    explicit PresenterContainer();
    ~PresenterContainer();

private:
	QScopedPointer<BusinessContainer> businessLayer_;
	QScopedPointer<DisplayPresenter> displayPresenter_;
};


#pragma once

#include <QObject>

class DisplayPresenter;
class FaultsUI;

class FaultsView : public QObject
{
	Q_OBJECT
public:
    FaultsView(DisplayPresenter& presenter, FaultsUI& ui);
    ~FaultsView();

private:
	DisplayPresenter& presenter_;
	FaultsUI& ui_;
};


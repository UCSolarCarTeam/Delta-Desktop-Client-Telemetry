#pragma once

#include <QObject>

class DisplayPresenter;
class OverlordWidget;

class DisplayView : public QObject
{
   Q_OBJECT
public:
   DisplayView(DisplayPresenter& presenter, OverlordWidget& ui);
   ~DisplayView();

private:
   DisplayPresenter& presenter_;
   OverlordWidget& ui_;
};

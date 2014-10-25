#pragma once

#include <QObject>

class DisplayPresenter;
class SolarCarTestUI;

class DisplayView : public QObject
{
   Q_OBJECT
public:
   DisplayView(class DisplayPresenter& presenter, class SolarCarTestUI& ui);
   ~DisplayView();
   
private:
   DisplayPresenter& presenter_;
   SolarCarTestUI& ui_;
};

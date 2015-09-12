#pragma once

#include <QObject>

class OverlordWidget;

class DisplayView : public QObject
{
   Q_OBJECT
public:
   DisplayView(OverlordWidget& ui);
   ~DisplayView();

private:
   OverlordWidget& ui_;
};

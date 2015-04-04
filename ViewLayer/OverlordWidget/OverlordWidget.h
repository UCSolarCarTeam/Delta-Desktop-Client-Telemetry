#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QSharedPointer>
#include "I_OverlordWidget.h"

class I_SolarCarWindow;

class OverlordWidget : public QWidget, public I_OverlordWidget
{
	Q_OBJECT
public:
	explicit OverlordWidget(QList<I_SolarCarWindow*> viewWindows, 
                            QWidget *parent = 0);
	~OverlordWidget();

    QString changeState();
    QString getState();
    // void showSettings();

private:
   QList<I_SolarCarWindow*> viewWindows_;
   QString state_;
   // QWidget* settingsWindow_;
   // QWidget* escWindow_;
};

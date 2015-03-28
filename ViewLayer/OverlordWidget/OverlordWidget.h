#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QSharedPointer>
#include "I_OverlordWidget.h"

class OverlordWidget : public QWidget, public I_OverlordWidget
{
	Q_OBJECT
public:
	explicit OverlordWidget(QList<QWidget*> viewWindows, 
                            QWidget *parent = 0);
	~OverlordWidget();

    QString changeState();
    QString getState();
    // void showSettings();

private:
   QList<QWidget*> viewWindows_;
   QString state_;
   // QWidget* settingsWindow_;
   // QWidget* escWindow_;
};
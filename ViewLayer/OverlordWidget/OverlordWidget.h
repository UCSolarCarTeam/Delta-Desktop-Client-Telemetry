#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QSharedPointer>
#include "I_OverlordWidget.h"

class I_SolarCarWindow;
class EscapeDialog;

class OverlordWidget : public QWidget, public I_OverlordWidget
{
	Q_OBJECT
public:
	explicit OverlordWidget(QList<I_SolarCarWindow*> viewWindows, 
                            EscapeDialog* escapeDialog,
                            QWidget *parent = 0);
	~OverlordWidget();

    void keyPressEvent(QKeyEvent * event);
    
    QString changeState();
    QString getState();
    // void showSettings();

private:
    void addFonts();
   QList<I_SolarCarWindow*> viewWindows_;
   QString state_;
   // QWidget* settingsWindow_;
   EscapeDialog* escapeDialog_;
};

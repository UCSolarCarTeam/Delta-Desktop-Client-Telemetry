#pragma once

#include <QObject>

class DisplayPresenter;
class EscapeDialog;

class EscapeDialogView : public QObject
{
   Q_OBJECT
public:
   EscapeDialogView(EscapeDialog& ui);
   ~EscapeDialogView();

private:
   EscapeDialog& ui_;

private slots:
   void handleSettingsButtonClicked();
   void handleAboutButtonClicked();
   void handleReturnButtonClicked();
   void handleExitButtonClicked();
};

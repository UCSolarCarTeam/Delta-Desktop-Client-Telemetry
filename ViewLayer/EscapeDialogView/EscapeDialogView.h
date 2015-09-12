#pragma once

#include <QObject>

class DisplayPresenter;
class EscapeDialog;
class I_PlaybackUI;

class EscapeDialogView : public QObject
{
   Q_OBJECT
public:
   EscapeDialogView(EscapeDialog& ui, I_PlaybackUI& playbackUi);
   ~EscapeDialogView();


private:
   EscapeDialog& ui_;
   I_PlaybackUI& playbackUi_;

private slots:
   void handleSettingsSelectionPushButtonClicked();
   void handleAboutSelectionPushButtonClicked();
   void handleExitPushButtonClicked();
   void handleOkPushButtonClicked();
   void handleClosePushButtonClicked();
   void saveChanges();
   void handleRequestToOpenPlaybackMode();
};

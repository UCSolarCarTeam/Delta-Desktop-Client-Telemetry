#include "EscapeDialogView.h"
#include "ViewLayer/EscapeDialog/EscapeDialog.h"
#include "ViewLayer/PlaybackUI/I_PlaybackUI.h"
#include <QDebug>
#include <QApplication>

EscapeDialogView::EscapeDialogView(EscapeDialog& ui, I_PlaybackUI& playbackUi)
: ui_(ui)
, playbackUi_(playbackUi)
{
   connect(&ui.settingsSelectionPushButton(), SIGNAL(clicked()),
      this, SLOT(handleSettingsSelectionPushButtonClicked()));
   connect(&ui.aboutSelectionPushButton(), SIGNAL(clicked()),
      this, SLOT(handleAboutSelectionPushButtonClicked()));
   connect(&ui.closePushButton(), SIGNAL(clicked()),
      this, SLOT(handleClosePushButtonClicked()));
   connect(&ui.exitPushButton(), SIGNAL(clicked()),
      this, SLOT(handleExitPushButtonClicked()));
   connect(&ui.okPushButton(), SIGNAL(clicked()),
      this, SLOT(handleOkPushButtonClicked()));
   connect(&ui.playbackModePushButton(), SIGNAL(clicked()),
      this, SLOT(handleRequestToOpenPlaybackMode()));

}

EscapeDialogView::~EscapeDialogView()
{
}

void EscapeDialogView::handleSettingsSelectionPushButtonClicked()
{
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(100,100,100);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(50,50,50);");
    ui_.optionsDisplayWidget().setCurrentIndex(1);
}

void EscapeDialogView::handleAboutSelectionPushButtonClicked()
{
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(50,50,50);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(100,100,100);");
    ui_.optionsDisplayWidget().setCurrentIndex(0);
}

void EscapeDialogView::handleExitPushButtonClicked()
{
    QApplication::exit();
}

void EscapeDialogView::handleClosePushButtonClicked()
{
    ui_.hide();
}

void EscapeDialogView::handleOkPushButtonClicked()
{
    saveChanges();
    ui_.hide();
}

void EscapeDialogView::saveChanges()
{
}

void EscapeDialogView::handleRequestToOpenPlaybackMode()
{
   if(!playbackUi_.isVisible()){
      Qt::WindowFlags windowFlags = Qt::Tool | Qt::WindowStaysOnTopHint;
      playbackUi_.setWindowFlags(windowFlags);
      ui_.hide();
      playbackUi_.show();
   }
}


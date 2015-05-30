#include "EscapeDialogView.h"
#include "../EscapeDialog/EscapeDialog.h"
#include <QDebug>
#include <QApplication>

EscapeDialogView::EscapeDialogView(EscapeDialog& ui)
: ui_(ui)
{
    connect(&ui.settingsSelectionPushButton(), SIGNAL(clicked()),
            this, SLOT(handleSettingsPushButtonClicked()));
    connect(&ui.aboutSelectionPushButton(), SIGNAL(clicked()),
            this, SLOT(handleAboutSelectionPushButtonClicked()));
    connect(&ui.closePushButton(), SIGNAL(clicked()),
            this, SLOT(handleClosePushButtonClicked()));
    connect(&ui.exitPushButton(), SIGNAL(clicked()),
            this, SLOT(handleExitPushButtonClicked()));
    connect(&ui.okPushButton(), SIGNAL(clicked()),
            this, SLOT(handleOkPushButtonClicked()));
}

EscapeDialogView::~EscapeDialogView()
{
}
void EscapeDialogView::handleFileDialogPushButtonClicked()
{
    qDebug() << "file dialog button clicked"; // placeholder code
}
void EscapeDialogView::handleSettingsSelectionPushButtonClicked()
{
    qDebug() << "settings button clicked"; // placeholder code
}

void EscapeDialogView::handleAboutSelectionPushButtonClicked()
{
    qDebug() << "about button clicked"; // placeholder code
}

void EscapeDialogView::handleExitPushButtonClicked()
{
    QApplication::exit();
    qDebug() << "exit button clicked"; // placeholder code
}

void EscapeDialogView::handleClosePushButtonClicked()
{
    ui_.hide();
    qDebug() << "close button clicked"; // placeholder code
}

void EscapeDialogView::handleOkPushButtonClicked()
{
    qDebug() << "ok button clicked"; // placeholder code
}

//void handleFileDialogPushButton();
//void handleSettingsSelectionPushButton();
//void handleAboutSelectionPushButton();
//void handleExitPushButton();
//void handleOkPushButton();
//void handleClosePushButton();

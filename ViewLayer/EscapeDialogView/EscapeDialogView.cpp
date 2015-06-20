#include "EscapeDialogView.h"
#include "../EscapeDialog/EscapeDialog.h"
#include <QDebug>
#include <QApplication>
#include <QFileDialog>
EscapeDialogView::EscapeDialogView(EscapeDialog& ui)
: ui_(ui)
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
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(100,100,100);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(50,50,50);");
    ui_.optionsDisplayWidget().setCurrentIndex(1);
    qDebug() << "settings button clicked"; // placeholder code
}

void EscapeDialogView::handleAboutSelectionPushButtonClicked()
{
    ui_.settingsSelectionPushButton().setStyleSheet("border-top:1px solid rgb(50,50,50);background: rgb(50,50,50);");
    ui_.aboutSelectionPushButton().setStyleSheet("background: rgb(100,100,100);");
    ui_.optionsDisplayWidget().setCurrentIndex(0);
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
    saveChanges();
    ui_.hide();
    qDebug() << "ok button clicked"; // placeholder code
}
void EscapeDialogView::saveChanges(){

}

//void handleFileDialogPushButton();
//void handleSettingsSelectionPushButton();
//void handleAboutSelectionPushButton();
//void handleExitPushButton();
//void handleOkPushButton();
//void handleClosePushButton();

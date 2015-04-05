#include "EscapeDialogView.h"
#include "../EscapeDialog/EscapeDialog.h"
#include <QDebug>
#include <QApplication>

EscapeDialogView::EscapeDialogView(EscapeDialog& ui)
: ui_(ui)
{
    connect(&ui.settingsButton(), SIGNAL(clicked()),
            this, SLOT(handleSettingsButtonClicked()));
    connect(&ui.aboutButton(), SIGNAL(clicked()),
            this, SLOT(handleAboutButtonClicked()));
    connect(&ui.returnButton(), SIGNAL(clicked()),
            this, SLOT(handleReturnButtonClicked()));
    connect(&ui.exitButton(), SIGNAL(clicked()),
            this, SLOT(handleExitButtonClicked()));
}

EscapeDialogView::~EscapeDialogView()
{
}

void EscapeDialogView::handleSettingsButtonClicked()
{
    qDebug() << "settings button clicked"; // placeholder code
}

void EscapeDialogView::handleAboutButtonClicked()
{
    qDebug() << "about button clicked"; // placeholder code
}

void EscapeDialogView::handleReturnButtonClicked()
{
    ui_.hide();
    qDebug() << "return button clicked"; // placeholder code
}

void EscapeDialogView::handleExitButtonClicked()
{
    QApplication::exit();
    qDebug() << "exit button clicked"; // placeholder code
}

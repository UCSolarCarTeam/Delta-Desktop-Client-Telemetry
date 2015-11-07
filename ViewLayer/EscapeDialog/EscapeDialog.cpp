#include "EscapeDialog.h"
#include "ui_EscapeDialog.h"
#include <QPainter>
#include <QDebug>


EscapeDialog::EscapeDialog()
: ui(new Ui::EscapeDialog)
{
    ui->setupUi(this);
    connect(&(this->fullscreenCheckBox()),SIGNAL(stateChanged(int)),
            this, SLOT(handleFullScreenCheckBoxStateChange(int)));
}

EscapeDialog::~EscapeDialog()
{
    delete ui;
}

void EscapeDialog::keyPressEvent(QKeyEvent* event)
{
   Q_UNUSED(event);
   hide();
}

void EscapeDialog::hideHeaderBar()
{
    ui->escapeTitleBarWidget->hide();
}

void EscapeDialog::handleFullScreenCheckBoxStateChange(int state)
{
    emit changeWindowState(state);
}

void EscapeDialog::paintEvent(QPaintEvent* e)
{
   Q_UNUSED(e);
   QColor backgroundColor = palette().light().color();
   backgroundColor.setAlpha(50);
   QPainter customPainter(this);
   customPainter.fillRect(rect(), backgroundColor);
}
QPushButton& EscapeDialog::settingsSelectionPushButton()
{
   return *ui->settingsSelectionPushButton;
}
QPushButton& EscapeDialog::aboutSelectionPushButton()
{
   return *ui->aboutSelectionPushButton;
}

QPushButton& EscapeDialog::exitPushButton()
{
   return *ui->exitPushButton;
}
QPushButton& EscapeDialog::okPushButton()
{
   return *ui->okPushButton;
}
QPushButton& EscapeDialog::closePushButton()
{
   return *ui->closePushButton;
}
QPushButton& EscapeDialog::playbackModePushButton()
{
   return *ui->playbackModePushButton;
}
QCheckBox& EscapeDialog::fullscreenCheckBox()
{
   return *ui->fullscreenCheckBox;
}
QStackedWidget& EscapeDialog::optionsDisplayWidget()
{
   return *ui->optionsDisplayWidget;
}

#include "EscapeDialog.h"
#include "ui_EscapeDialog.h"
#include <QPainter>
#include <QDebug>


EscapeDialog::EscapeDialog()
: ui(new Ui::EscapeDialog)
{
    ui->setupUi(this);
}

EscapeDialog::~EscapeDialog()
{
    delete ui;
}

void EscapeDialog::keyPressEvent(QKeyEvent * event){
   hide();
}

void EscapeDialog::hideHeaderBar()
{
    ui->escapeTitleBarWidget->hide();
}

void EscapeDialog::paintEvent(QPaintEvent* e)
{
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
QCheckBox& EscapeDialog::fullscreenCheckBox()
{
   return *ui->fullscreenCheckBox;
}
QCheckBox& EscapeDialog::multiWindowCheckBox()
{
   return *ui->multiWindowCheckBox;
}
QStackedWidget& EscapeDialog::optionsDisplayWidget()
{
   return *ui->optionsDisplayWidget;
}

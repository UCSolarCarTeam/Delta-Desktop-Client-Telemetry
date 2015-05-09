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

QPushButton& EscapeDialog::settingsButton()
{
   return *ui->settingsPushButton;
}
QPushButton& EscapeDialog::aboutButton()
{
   return *ui->aboutPushButton;
}
QPushButton& EscapeDialog::returnButton()
{
   return *ui->returnPushButton;
}
QPushButton& EscapeDialog::toggleFullscreenPushButton()
{
   return *ui->toggleFullscreenPushButton;
}
QPushButton& EscapeDialog::exitButton()
{
   return *ui->exitPushButton;
}

#include "EscapeDialog.h"
#include "ui_EscapeDialog.h"
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

QPushButton& EscapeDialog::settingsButton()
{
   return *ui->settingsButton;
}
QPushButton& EscapeDialog::aboutButton()
{
   return *ui->aboutButton;
}
QPushButton& EscapeDialog::returnButton()
{
   return *ui->returnButton;
}
QPushButton& EscapeDialog::exitButton()
{
   return *ui->exitButton;
}

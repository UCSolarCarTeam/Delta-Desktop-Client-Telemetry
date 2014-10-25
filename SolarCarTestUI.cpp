#include "SolarCarTestUI.h"
#include "ui_SolarCarTestUI.h"

SolarCarTestUI::SolarCarTestUI(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::SolarCarTestUI)
{
   ui->setupUi(this);
}

SolarCarTestUI::~SolarCarTestUI()
{
   delete ui;
}


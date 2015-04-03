#include "FaultsUI.h"
#include "ui_FaultsUI.h"

FaultsUI::FaultsUI(QWidget *parent)
: QWidget(parent)
, ui(new Ui::FaultsUI)
{
	ui->setupUi(this);
}

FaultsUI::~FaultsUI()
{
	delete ui;
}


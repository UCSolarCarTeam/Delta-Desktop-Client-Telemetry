#include "FaultsUI.h"
#include "ui_FaultsUI.h"

FaultsUI::FaultsUI()
: ui(new Ui::FaultsUI)
{
	ui->setupUi(this);
}

FaultsUI::~FaultsUI()
{
	delete ui;
}

void FaultsUI::hideHeaderBar()
{
	ui->faultsTitleBar->hide();
}

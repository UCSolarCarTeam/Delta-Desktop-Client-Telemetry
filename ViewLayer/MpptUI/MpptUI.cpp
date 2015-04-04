#include "MpptUI.h"
#include "ui_MpptUI.h"

MpptUI::MpptUI()
: ui(new Ui::MpptUI)
{
	ui->setupUi(this);
}

MpptUI::~MpptUI()
{
	delete ui;
}

void MpptUI::hideHeaderBar()
{
	ui->mpptTitleBar->hide();
}

#include "MpptUI.h"
#include "ui_MpptUI.h"

MpptUI::MpptUI(QWidget *parent)
: QWidget(parent)
, ui(new Ui::MpptUI)
{
	ui->setupUi(this);
}

MpptUI::~MpptUI()
{
	delete ui;
}


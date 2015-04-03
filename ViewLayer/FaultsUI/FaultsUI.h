#pragma once

#include <QWidget>
#include "I_FaultsUI.h"

namespace Ui {
	class FaultsUI;
}

class FaultsUI : public QWidget, public I_FaultsUI 
{
	Q_OBJECT
public:
    explicit FaultsUI(QWidget *parent = 0);
    ~FaultsUI();

private:
	Ui::FaultsUI *ui;
};


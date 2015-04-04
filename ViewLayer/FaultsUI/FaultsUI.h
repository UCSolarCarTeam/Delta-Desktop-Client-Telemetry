#pragma once

#include "I_FaultsUI.h"
#include "../I_SolarCarWindow/I_SolarCarWindow.h"

namespace Ui {
	class FaultsUI;
}

class FaultsUI : public I_SolarCarWindow, public I_FaultsUI 
{
	Q_OBJECT
public:
    explicit FaultsUI();
    ~FaultsUI();

    void hideHeaderBar();

private:
	Ui::FaultsUI *ui;
};


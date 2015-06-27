#pragma once

#include "../I_SolarCarWindow/I_SolarCarWindow.h"
#include "I_MpptUI.h"

namespace Ui {
	class MpptUI;
}

class MpptUI : public I_SolarCarWindow, public I_MpptUI 
{
	Q_OBJECT
public:
    explicit MpptUI();
    ~MpptUI();

    void hideHeaderBar();

	QLabel& setMppt1PowerIn();
	QLabel& setMppt1VoltageIn();
	QLabel& setMppt1CurrentIn();
	QLabel& setMppt1PowerOut();
	QLabel& setMppt1VoltageOut();
	QLabel& setMppt1CurrentOut();
	QLabel& setMppt1Efficiency();
	QLabel& setMppt1Type();
	QLabel& setMppt1Mode();

	QLabel& setMppt2PowerIn();
	QLabel& setMppt2VoltageIn();
	QLabel& setMppt2CurrentIn();
	QLabel& setMppt2PowerOut();
	QLabel& setMppt2VoltageOut();
	QLabel& setMppt2CurrentOut();
	QLabel& setMppt2Efficiency();
	QLabel& setMppt2Type();
	QLabel& setMppt2Mode();

	QLabel& setMppt3PowerIn();
	QLabel& setMppt3VoltageIn();
	QLabel& setMppt3CurrentIn();
	QLabel& setMppt3PowerOut();
	QLabel& setMppt3VoltageOut();
	QLabel& setMppt3CurrentOut();
	QLabel& setMppt3Efficiency();
	QLabel& setMppt3Type();
	QLabel& setMppt3Mode();

	QLabel& setMppt4PowerIn();
	QLabel& setMppt4VoltageIn();
	QLabel& setMppt4CurrentIn();
	QLabel& setMppt4PowerOut();
	QLabel& setMppt4VoltageOut();
	QLabel& setMppt4CurrentOut();
	QLabel& setMppt4Efficiency();
	QLabel& setMppt4Type();
	QLabel& setMppt4Mode();

	QLabel& setMppt5PowerIn();
	QLabel& setMppt5VoltageIn();
	QLabel& setMppt5CurrentIn();
	QLabel& setMppt5PowerOut();
	QLabel& setMppt5VoltageOut();
	QLabel& setMppt5CurrentOut();
	QLabel& setMppt5Efficiency();
	QLabel& setMppt5Type();
	QLabel& setMppt5Mode();

	QLabel& setMppt6PowerIn();
	QLabel& setMppt6VoltageIn();
	QLabel& setMppt6CurrentIn();
	QLabel& setMppt6PowerOut();
	QLabel& setMppt6VoltageOut();
	QLabel& setMppt6CurrentOut();
	QLabel& setMppt6Efficiency();
	QLabel& setMppt6Type();
	QLabel& setMppt6Mode();

	QLabel& setMppt7PowerIn();
	QLabel& setMppt7VoltageIn();
	QLabel& setMppt7CurrentIn();
	QLabel& setMppt7PowerOut();
	QLabel& setMppt7VoltageOut();
	QLabel& setMppt7CurrentOut();
	QLabel& setMppt7Efficiency();
	QLabel& setMppt7Type();
	QLabel& setMppt7Mode();

private:
	Ui::MpptUI *ui;
};


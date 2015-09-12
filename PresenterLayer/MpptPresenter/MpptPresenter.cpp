#include "MpptPresenter.h"
#include "../../DataLayer/MpptData/I_MpptData.h"

MpptPresenter::MpptPresenter(const I_MpptData& mpptData)
: mpptData_(mpptData)
{
   relayMpptData();
}

void MpptPresenter::relayMpptData()
{
	connect(&mpptData_, SIGNAL(mppt1VoltageInReceived(double)),
		this, SIGNAL(mppt1VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt1CurrentInReceived(double)),
		this, SIGNAL(mppt1CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt1VoltageOutReceived(double)),
		this, SIGNAL(mppt1VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt1CurrentOutReceived(double)),
		this, SIGNAL(mppt1CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt1TypeReceived(QString)),
		this, SIGNAL(mppt1TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt1ModeReceived(QString)),
		this, SIGNAL(mppt1ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt2VoltageInReceived(double)),
		this, SIGNAL(mppt2VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2CurrentInReceived(double)),
		this, SIGNAL(mppt2CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2VoltageOutReceived(double)),
		this, SIGNAL(mppt2VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2CurrentOutReceived(double)),
		this, SIGNAL(mppt2CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2TypeReceived(QString)),
		this, SIGNAL(mppt2TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt2ModeReceived(QString)),
		this, SIGNAL(mppt2ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt3VoltageInReceived(double)),
		this, SIGNAL(mppt3VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3CurrentInReceived(double)),
		this, SIGNAL(mppt3CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3VoltageOutReceived(double)),
		this, SIGNAL(mppt3VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3CurrentOutReceived(double)),
		this, SIGNAL(mppt3CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3TypeReceived(QString)),
		this, SIGNAL(mppt3TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt3ModeReceived(QString)),
		this, SIGNAL(mppt3ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt4VoltageInReceived(double)),
		this, SIGNAL(mppt4VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4CurrentInReceived(double)),
		this, SIGNAL(mppt4CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4VoltageOutReceived(double)),
		this, SIGNAL(mppt4VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4CurrentOutReceived(double)),
		this, SIGNAL(mppt4CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4TypeReceived(QString)),
		this, SIGNAL(mppt4TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt4ModeReceived(QString)),
		this, SIGNAL(mppt4ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt5VoltageInReceived(double)),
		this, SIGNAL(mppt5VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5CurrentInReceived(double)),
		this, SIGNAL(mppt5CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5VoltageOutReceived(double)),
		this, SIGNAL(mppt5VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5CurrentOutReceived(double)),
		this, SIGNAL(mppt5CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5TypeReceived(QString)),
		this, SIGNAL(mppt5TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt5ModeReceived(QString)),
		this, SIGNAL(mppt5ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt6VoltageInReceived(double)),
		this, SIGNAL(mppt6VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6CurrentInReceived(double)),
		this, SIGNAL(mppt6CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6VoltageOutReceived(double)),
		this, SIGNAL(mppt6VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6CurrentOutReceived(double)),
		this, SIGNAL(mppt6CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6TypeReceived(QString)),
		this, SIGNAL(mppt6TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt6ModeReceived(QString)),
		this, SIGNAL(mppt6ModeReceived(QString)));

	connect(&mpptData_, SIGNAL(mppt7VoltageInReceived(double)),
		this, SIGNAL(mppt7VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7CurrentInReceived(double)),
		this, SIGNAL(mppt7CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7VoltageOutReceived(double)),
		this, SIGNAL(mppt7VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7CurrentOutReceived(double)),
		this, SIGNAL(mppt7CurrentOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7TypeReceived(QString)),
		this, SIGNAL(mppt7TypeReceived(QString)));
	connect(&mpptData_, SIGNAL(mppt7ModeReceived(QString)),
		this, SIGNAL(mppt7ModeReceived(QString)));
}
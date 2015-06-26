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

	connect(&mpptData_, SIGNAL(mppt2VoltageInReceived(double)),
		this, SIGNAL(mppt2VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2CurrentInReceived(double)),
		this, SIGNAL(mppt2CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2VoltageOutReceived(double)),
		this, SIGNAL(mppt2VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt2CurrentOutReceived(double)),
		this, SIGNAL(mppt2CurrentOutReceived(double)));

	connect(&mpptData_, SIGNAL(mppt3VoltageInReceived(double)),
		this, SIGNAL(mppt3VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3CurrentInReceived(double)),
		this, SIGNAL(mppt3CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3VoltageOutReceived(double)),
		this, SIGNAL(mppt3VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt3CurrentOutReceived(double)),
		this, SIGNAL(mppt3CurrentOutReceived(double)));

	connect(&mpptData_, SIGNAL(mppt4VoltageInReceived(double)),
		this, SIGNAL(mppt4VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4CurrentInReceived(double)),
		this, SIGNAL(mppt4CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4VoltageOutReceived(double)),
		this, SIGNAL(mppt4VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt4CurrentOutReceived(double)),
		this, SIGNAL(mppt4CurrentOutReceived(double)));

	connect(&mpptData_, SIGNAL(mppt5VoltageInReceived(double)),
		this, SIGNAL(mppt5VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5CurrentInReceived(double)),
		this, SIGNAL(mppt5CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5VoltageOutReceived(double)),
		this, SIGNAL(mppt5VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt5CurrentOutReceived(double)),
		this, SIGNAL(mppt5CurrentOutReceived(double)));

	connect(&mpptData_, SIGNAL(mppt6VoltageInReceived(double)),
		this, SIGNAL(mppt6VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6CurrentInReceived(double)),
		this, SIGNAL(mppt6CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6VoltageOutReceived(double)),
		this, SIGNAL(mppt6VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt6CurrentOutReceived(double)),
		this, SIGNAL(mppt6CurrentOutReceived(double)));

	connect(&mpptData_, SIGNAL(mppt7VoltageInReceived(double)),
		this, SIGNAL(mppt7VoltageInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7CurrentInReceived(double)),
		this, SIGNAL(mppt7CurrentInReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7VoltageOutReceived(double)),
		this, SIGNAL(mppt7VoltageOutReceived(double)));
	connect(&mpptData_, SIGNAL(mppt7CurrentOutReceived(double)),
		this, SIGNAL(mppt7CurrentOutReceived(double)));

	// connect(&mpptData_, SIGNAL(power1VoltageValueReceived(double)),
	// 	this, SIGNAL(power1VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power1CurrentValueReceived(double)),
	// 	this, SIGNAL(power1CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power2VoltageValueReceived(double)),
	// 	this, SIGNAL(power2VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power2CurrentValueReceived(double)),
	// 	this, SIGNAL(power2CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power3VoltageValueReceived(double)),
	// 	this, SIGNAL(power3VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power3CurrentValueReceived(double)),
	// 	this, SIGNAL(power3CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power4VoltageValueReceived(double)),
	// 	this, SIGNAL(power4VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power4CurrentValueReceived(double)),
	// 	this, SIGNAL(power4CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power5VoltageValueReceived(double)),
	// 	this, SIGNAL(power5VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power5CurrentValueReceived(double)),
	// 	this, SIGNAL(power5CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power6VoltageValueReceived(double)),
	// 	this, SIGNAL(power6VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power6CurrentValueReceived(double)),
	// 	this, SIGNAL(power6CurrentValueReceived(double)));

	// connect(&mpptData_, SIGNAL(power7VoltageValueReceived(double)),
	// 	this, SIGNAL(power7VoltageValueReceived(double)));
	// connect(&mpptData_, SIGNAL(power7CurrentValueReceived(double)),
	// 	this, SIGNAL(power7CurrentValueReceived(double)));
}
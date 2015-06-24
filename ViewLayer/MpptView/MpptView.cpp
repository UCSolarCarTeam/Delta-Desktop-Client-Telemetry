#include "MpptView.h"
#include "../../PresenterLayer/DisplayPresenter/DisplayPresenter.h"
#include "../MpptUI/MpptUI.h"

MpptView::MpptView(DisplayPresenter& presenter, MpptUI& ui)
: presenter_(presenter)
, ui_(ui)
{
}

MpptView::~MpptView()
{
}

void MpptView::mppt1VoltageInReceived(double mppt1VoltageIn)
{
	ui_.setMppt1VoltageIn().setNum(mppt1VoltageIn);
	ui_.setMppt1PowerIn().setNum(mppt1VoltageIn * 
		ui_.setMppt1CurrentIn().text().toDouble());
	ui_.setMppt1Efficiency().setNum(ui_.setMppt1PowerIn().text().toDouble() *
		ui_.setMppt1PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt1CurrentInReceived(double mppt1CurrentIn)
{
	ui_.setMppt1CurrentIn().setNum(mppt1CurrentIn);
	ui_.setMppt1PowerIn().setNum(mppt1CurrentIn * 
		ui_.setMppt1VoltageIn().text().toDouble());
	ui_.setMppt1Efficiency().setNum(ui_.setMppt1PowerIn().text().toDouble() *
		ui_.setMppt1PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt1VoltageOutReceived(double mppt1VoltageOut)
{
	ui_.setMppt1VoltageOut().setNum(mppt1VoltageOut);
	ui_.setMppt1PowerOut().setNum(mppt1VoltageOut * 
		ui_.setMppt1CurrentOut().text().toDouble());
	ui_.setMppt1Efficiency().setNum(ui_.setMppt1PowerIn().text().toDouble() *
		ui_.setMppt1PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt1CurrentOutReceived(double mppt1CurrentOut)
{
	ui_.setMppt1CurrentOut().setNum(mppt1CurrentOut);
	ui_.setMppt1PowerOut().setNum(mppt1CurrentOut * 
		ui_.setMppt1VoltageOut().text().toDouble());
	ui_.setMppt1Efficiency().setNum(ui_.setMppt1PowerIn().text().toDouble() *
		ui_.setMppt1PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt2VoltageInReceived(double mppt2VoltageIn)
{
	ui_.setMppt2VoltageIn().setNum(mppt2VoltageIn);
	ui_.setMppt2PowerIn().setNum(mppt2VoltageIn * 
		ui_.setMppt2CurrentIn().text().toDouble());
	ui_.setMppt2Efficiency().setNum(ui_.setMppt2PowerIn().text().toDouble() *
		ui_.setMppt2PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt2CurrentInReceived(double mppt2CurrentIn)
{
	ui_.setMppt2CurrentIn().setNum(mppt2CurrentIn);
	ui_.setMppt2PowerIn().setNum(mppt2CurrentIn * 
		ui_.setMppt2VoltageIn().text().toDouble());
	ui_.setMppt2Efficiency().setNum(ui_.setMppt2PowerIn().text().toDouble() *
		ui_.setMppt2PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt2VoltageOutReceived(double mppt2VoltageOut)
{
	ui_.setMppt2VoltageOut().setNum(mppt2VoltageOut);
	ui_.setMppt2PowerOut().setNum(mppt2VoltageOut * 
		ui_.setMppt2CurrentOut().text().toDouble());
	ui_.setMppt2Efficiency().setNum(ui_.setMppt2PowerIn().text().toDouble() *
		ui_.setMppt2PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt2CurrentOutReceived(double mppt2CurrentOut)
{
	ui_.setMppt2CurrentOut().setNum(mppt2CurrentOut);
	ui_.setMppt2PowerOut().setNum(mppt2CurrentOut * 
		ui_.setMppt2VoltageOut().text().toDouble());
	ui_.setMppt2Efficiency().setNum(ui_.setMppt2PowerIn().text().toDouble() *
		ui_.setMppt2PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt3VoltageInReceived(double mppt3VoltageIn)
{
	ui_.setMppt3VoltageIn().setNum(mppt3VoltageIn);
	ui_.setMppt3PowerIn().setNum(mppt3VoltageIn * 
		ui_.setMppt3CurrentIn().text().toDouble());
	ui_.setMppt3Efficiency().setNum(ui_.setMppt3PowerIn().text().toDouble() *
		ui_.setMppt3PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt3CurrentInReceived(double mppt3CurrentIn)
{
	ui_.setMppt3CurrentIn().setNum(mppt3CurrentIn);
	ui_.setMppt3PowerIn().setNum(mppt3CurrentIn * 
		ui_.setMppt3VoltageIn().text().toDouble());
	ui_.setMppt3Efficiency().setNum(ui_.setMppt3PowerIn().text().toDouble() *
		ui_.setMppt3PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt3VoltageOutReceived(double mppt3VoltageOut)
{
	ui_.setMppt3VoltageOut().setNum(mppt3VoltageOut);
	ui_.setMppt3PowerOut().setNum(mppt3VoltageOut * 
		ui_.setMppt3CurrentOut().text().toDouble());
	ui_.setMppt3Efficiency().setNum(ui_.setMppt3PowerIn().text().toDouble() *
		ui_.setMppt3PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt3CurrentOutReceived(double mppt3CurrentOut)
{
	ui_.setMppt3CurrentOut().setNum(mppt3CurrentOut);
	ui_.setMppt3PowerOut().setNum(mppt3CurrentOut * 
		ui_.setMppt3VoltageOut().text().toDouble());
	ui_.setMppt3Efficiency().setNum(ui_.setMppt3PowerIn().text().toDouble() *
		ui_.setMppt3PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt4VoltageInReceived(double mppt4VoltageIn)
{
	ui_.setMppt4VoltageIn().setNum(mppt4VoltageIn);
	ui_.setMppt4PowerIn().setNum(mppt4VoltageIn * 
		ui_.setMppt4CurrentIn().text().toDouble());
	ui_.setMppt4Efficiency().setNum(ui_.setMppt4PowerIn().text().toDouble() *
		ui_.setMppt4PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt4CurrentInReceived(double mppt4CurrentIn)
{
	ui_.setMppt4CurrentIn().setNum(mppt4CurrentIn);
	ui_.setMppt4PowerIn().setNum(mppt4CurrentIn * 
		ui_.setMppt4VoltageIn().text().toDouble());
	ui_.setMppt4Efficiency().setNum(ui_.setMppt4PowerIn().text().toDouble() *
		ui_.setMppt4PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt4VoltageOutReceived(double mppt4VoltageOut)
{
	ui_.setMppt4VoltageOut().setNum(mppt4VoltageOut);
	ui_.setMppt4PowerOut().setNum(mppt4VoltageOut * 
		ui_.setMppt4CurrentOut().text().toDouble());
	ui_.setMppt4Efficiency().setNum(ui_.setMppt4PowerIn().text().toDouble() *
		ui_.setMppt4PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt4CurrentOutReceived(double mppt4CurrentOut)
{
	ui_.setMppt4CurrentOut().setNum(mppt4CurrentOut);
	ui_.setMppt4PowerOut().setNum(mppt4CurrentOut * 
		ui_.setMppt4VoltageOut().text().toDouble());
	ui_.setMppt4Efficiency().setNum(ui_.setMppt4PowerIn().text().toDouble() *
		ui_.setMppt4PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt5VoltageInReceived(double mppt5VoltageIn)
{
	ui_.setMppt5VoltageIn().setNum(mppt5VoltageIn);
	ui_.setMppt5PowerIn().setNum(mppt5VoltageIn * 
		ui_.setMppt5CurrentIn().text().toDouble());
	ui_.setMppt5Efficiency().setNum(ui_.setMppt5PowerIn().text().toDouble() *
		ui_.setMppt5PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt5CurrentInReceived(double mppt5CurrentIn)
{
	ui_.setMppt5CurrentIn().setNum(mppt5CurrentIn);
	ui_.setMppt5PowerIn().setNum(mppt5CurrentIn * 
		ui_.setMppt5VoltageIn().text().toDouble());
	ui_.setMppt5Efficiency().setNum(ui_.setMppt5PowerIn().text().toDouble() *
		ui_.setMppt5PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt5VoltageOutReceived(double mppt5VoltageOut)
{
	ui_.setMppt5VoltageOut().setNum(mppt5VoltageOut);
	ui_.setMppt5PowerOut().setNum(mppt5VoltageOut * 
		ui_.setMppt5CurrentOut().text().toDouble());
	ui_.setMppt5Efficiency().setNum(ui_.setMppt5PowerIn().text().toDouble() *
		ui_.setMppt5PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt5CurrentOutReceived(double mppt5CurrentOut)
{
	ui_.setMppt5CurrentOut().setNum(mppt5CurrentOut);
	ui_.setMppt5PowerOut().setNum(mppt5CurrentOut * 
		ui_.setMppt5VoltageOut().text().toDouble());
	ui_.setMppt5Efficiency().setNum(ui_.setMppt5PowerIn().text().toDouble() *
		ui_.setMppt5PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt6VoltageInReceived(double mppt6VoltageIn)
{
	ui_.setMppt6VoltageIn().setNum(mppt6VoltageIn);
	ui_.setMppt6PowerIn().setNum(mppt6VoltageIn * 
		ui_.setMppt6CurrentIn().text().toDouble());
	ui_.setMppt6Efficiency().setNum(ui_.setMppt6PowerIn().text().toDouble() *
		ui_.setMppt6PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt6CurrentInReceived(double mppt6CurrentIn)
{
	ui_.setMppt6CurrentIn().setNum(mppt6CurrentIn);
	ui_.setMppt6PowerIn().setNum(mppt6CurrentIn * 
		ui_.setMppt6VoltageIn().text().toDouble());
	ui_.setMppt6Efficiency().setNum(ui_.setMppt6PowerIn().text().toDouble() *
		ui_.setMppt6PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt6VoltageOutReceived(double mppt6VoltageOut)
{
	ui_.setMppt6VoltageOut().setNum(mppt6VoltageOut);
	ui_.setMppt6PowerOut().setNum(mppt6VoltageOut * 
		ui_.setMppt6CurrentOut().text().toDouble());
	ui_.setMppt6Efficiency().setNum(ui_.setMppt6PowerIn().text().toDouble() *
		ui_.setMppt6PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt6CurrentOutReceived(double mppt6CurrentOut)
{
	ui_.setMppt6CurrentOut().setNum(mppt6CurrentOut);
	ui_.setMppt6PowerOut().setNum(mppt6CurrentOut * 
		ui_.setMppt6VoltageOut().text().toDouble());
	ui_.setMppt6Efficiency().setNum(ui_.setMppt6PowerIn().text().toDouble() *
		ui_.setMppt6PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::mppt7VoltageInReceived(double mppt7VoltageIn)
{
	ui_.setMppt7VoltageIn().setNum(mppt7VoltageIn);
	ui_.setMppt7PowerIn().setNum(mppt7VoltageIn * 
		ui_.setMppt7CurrentIn().text().toDouble());
	ui_.setMppt7Efficiency().setNum(ui_.setMppt7PowerIn().text().toDouble() *
		ui_.setMppt7PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt7CurrentInReceived(double mppt7CurrentIn)
{
	ui_.setMppt7CurrentIn().setNum(mppt7CurrentIn);
	ui_.setMppt7PowerIn().setNum(mppt7CurrentIn * 
		ui_.setMppt7VoltageIn().text().toDouble());
	ui_.setMppt7Efficiency().setNum(ui_.setMppt7PowerIn().text().toDouble() *
		ui_.setMppt7PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt7VoltageOutReceived(double mppt7VoltageOut)
{
	ui_.setMppt7VoltageOut().setNum(mppt7VoltageOut);
	ui_.setMppt7PowerOut().setNum(mppt7VoltageOut * 
		ui_.setMppt7CurrentOut().text().toDouble());
	ui_.setMppt7Efficiency().setNum(ui_.setMppt7PowerIn().text().toDouble() *
		ui_.setMppt7PowerOut().text().toDouble() * 100); // in percentage
}
void MpptView::mppt7CurrentOutReceived(double mppt7CurrentOut)
{
	ui_.setMppt7CurrentOut().setNum(mppt7CurrentOut);
	ui_.setMppt7PowerOut().setNum(mppt7CurrentOut * 
		ui_.setMppt7VoltageOut().text().toDouble());
	ui_.setMppt7Efficiency().setNum(ui_.setMppt7PowerIn().text().toDouble() *
		ui_.setMppt7PowerOut().text().toDouble() * 100); // in percentage
}

void MpptView::power1VoltageValueReceived(double power1VoltageValue)
{
	ui_.setPower1VoltageValue().setNum(power1VoltageValue);
	ui_.setPower1PowerValue().setNum(power1VoltageValue * 
		ui_.setPower1CurrentValue().text().toDouble());
}
void MpptView::power1CurrentValueReceived(double power1CurrentValue)
{
	ui_.setPower1CurrentValue().setNum(power1CurrentValue);
	ui_.setPower1PowerValue().setNum(power1CurrentValue * 
		ui_.setPower1VoltageValue().text().toDouble());
}

void MpptView::power2VoltageValueReceived(double power2VoltageValue)
{
	ui_.setPower2VoltageValue().setNum(power2VoltageValue);
	ui_.setPower2PowerValue().setNum(power2VoltageValue * 
		ui_.setPower2CurrentValue().text().toDouble());
}
void MpptView::power2CurrentValueReceived(double power2CurrentValue)
{
	ui_.setPower2CurrentValue().setNum(power2CurrentValue);
	ui_.setPower2PowerValue().setNum(power2CurrentValue * 
		ui_.setPower2VoltageValue().text().toDouble());
}

void MpptView::power3VoltageValueReceived(double power3VoltageValue)
{
	ui_.setPower3VoltageValue().setNum(power3VoltageValue);
	ui_.setPower3PowerValue().setNum(power3VoltageValue * 
		ui_.setPower3CurrentValue().text().toDouble());
}
void MpptView::power3CurrentValueReceived(double power3CurrentValue)
{
	ui_.setPower3CurrentValue().setNum(power3CurrentValue);
	ui_.setPower3PowerValue().setNum(power3CurrentValue * 
		ui_.setPower3VoltageValue().text().toDouble());
}

void MpptView::power4VoltageValueReceived(double power4VoltageValue)
{
	ui_.setPower4VoltageValue().setNum(power4VoltageValue);
	ui_.setPower4PowerValue().setNum(power4VoltageValue * 
		ui_.setPower4CurrentValue().text().toDouble());
}
void MpptView::power4CurrentValueReceived(double power4CurrentValue)
{
	ui_.setPower4CurrentValue().setNum(power4CurrentValue);
	ui_.setPower4PowerValue().setNum(power4CurrentValue * 
		ui_.setPower4VoltageValue().text().toDouble());
}

void MpptView::power5VoltageValueReceived(double power5VoltageValue)
{
	ui_.setPower5VoltageValue().setNum(power5VoltageValue);
	ui_.setPower5PowerValue().setNum(power5VoltageValue * 
		ui_.setPower5CurrentValue().text().toDouble());
}
void MpptView::power5CurrentValueReceived(double power5CurrentValue)
{
	ui_.setPower5CurrentValue().setNum(power5CurrentValue);
	ui_.setPower5PowerValue().setNum(power5CurrentValue * 
		ui_.setPower5VoltageValue().text().toDouble());
}

void MpptView::power6VoltageValueReceived(double power6VoltageValue)
{
	ui_.setPower6VoltageValue().setNum(power6VoltageValue);
	ui_.setPower6PowerValue().setNum(power6VoltageValue * 
		ui_.setPower6CurrentValue().text().toDouble());
}
void MpptView::power6CurrentValueReceived(double power6CurrentValue)
{
	ui_.setPower6CurrentValue().setNum(power6CurrentValue);
	ui_.setPower6PowerValue().setNum(power6CurrentValue * 
		ui_.setPower6VoltageValue().text().toDouble());
}

void MpptView::power7VoltageValueReceived(double power7VoltageValue)
{
	ui_.setPower7VoltageValue().setNum(power7VoltageValue);
	ui_.setPower7PowerValue().setNum(power7VoltageValue * 
		ui_.setPower7CurrentValue().text().toDouble());
}
void MpptView::power7CurrentValueReceived(double power7CurrentValue)
{
	ui_.setPower7CurrentValue().setNum(power7CurrentValue);
	ui_.setPower7PowerValue().setNum(power7CurrentValue * 
		ui_.setPower7VoltageValue().text().toDouble());
}

void MpptView::updatePvGraph()
{

}
void MpptView::updateIvGraph()
{

}
void MpptView::updatePtGraph()
{

}

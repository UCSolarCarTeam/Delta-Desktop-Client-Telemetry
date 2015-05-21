#include "FaultsView.h"
#include "../../PresenterLayer/FaultsPresenter/FaultsPresenter.h"
#include "../FaultsUI/FaultsUI.h"
#include <QDateTime>

FaultsView::FaultsView(FaultsPresenter& faultsPresenter, FaultsUI& ui)
: faultsPresenter_(faultsPresenter)
, ui_(ui)
{
	connect(&faultsPresenter_, SIGNAL(motorFaultsReceived(MotorFaults)),
			this, SLOT(motorFaultsReceived(MotorFaults)));
	connect(&faultsPresenter_, SIGNAL(limitFlagsReceived(LimitFlags)),
	        this, SLOT(limitFlagsReceived(LimitFlags)));
	connect(&faultsPresenter_, SIGNAL(batteryFaultsReceived(BatteryFaults)),
	        this, SLOT(batteryFaultsReceived(BatteryFaults)));        		 	
}

FaultsView::~FaultsView()
{
}

void FaultsView::motorFaultsReceived(MotorFaults motorFaults)
{
	if(motorFaults.desaturationFault()){
		ui_.desaturationFaultLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");	
	ui_.historyTextEdit().append("motorFaults - " + QDateTime::currentDateTime().toString());
	}
	else{
		ui_.desaturationFaultLabel().setStyleSheet("");			
	}

    if(motorFaults.railUnderVoltageLockOut()){
    	ui_.fifteenVoltRailUnderVoltageLockoutLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("railUnderVoltageLockOut - " + QDateTime::currentDateTime().toString());
    }
	else{
    	ui_.fifteenVoltRailUnderVoltageLockoutLabel().setStyleSheet("");
    }

    if(motorFaults.configReadError()){
    	ui_.configReadErrorLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("configReadError - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.configReadErrorLabel().setStyleSheet("");
    }
        
    if(motorFaults.watchdogCausedLastReset()){
    	ui_.watchDogCausedLastResetLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("watchdogCausedLastReset - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.watchDogCausedLastResetLabel().setStyleSheet("");
    }
    
    if(motorFaults.badMotorPositionHallSequence()){
    	ui_.badMotorPositionHallSequenceLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("badMotorPositionHallSequence - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.badMotorPositionHallSequenceLabel().setStyleSheet("");
    }

    if(motorFaults.dcBusOverVoltage()){
    	ui_.dcBusOverVoltageLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("dcBusOverVoltage - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.dcBusOverVoltageLabel().setStyleSheet("");
    }

    if(motorFaults.softwareOverCurrent()){
    	ui_.softwareOverCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("softwareOverCurrent - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.softwareOverCurrentLabel().setStyleSheet("");
    }

    if(motorFaults.hardwareOverCurrent()){
    	ui_.hardwareOverCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
    	ui_.historyTextEdit().append("hardwareOverCurrent - " + QDateTime::currentDateTime().toString());
    }
    else{
    	ui_.hardwareOverCurrentLabel().setStyleSheet("");
    }
}
 
void FaultsView::limitFlagsReceived(LimitFlags limitFlags)
{
	if(limitFlags.outputVoltagePwmLimit()){
		ui_.outputVoltagePwmLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("outputVoltagePwmLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.outputVoltagePwmLabel().setStyleSheet("");
	}
	if(limitFlags.motorCurrentLimit()){
		ui_.motorCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("motorCurrentLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.motorCurrentLabel().setStyleSheet("");
	}
	if(limitFlags.velocityLimit()){
		ui_.velocityLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("velocityLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.velocityLabel().setStyleSheet("");
	}
	if(limitFlags.busCurrentLimit()){
		ui_.busCurrentLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("busCurrentLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.busCurrentLabel().setStyleSheet("");
	}
	if(limitFlags.busVoltageUpperLimit()){
		ui_.busVoltageUpperLimitLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("busVoltageUpperLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.busVoltageUpperLimitLabel().setStyleSheet("");
	}
	if(limitFlags.busVoltageLowerLimit()){
		ui_.busVoltageLowerLimitLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("busVoltageLowerLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.busVoltageLowerLimitLabel().setStyleSheet("");
	}
	if(limitFlags.ipmOrMotorTelemetryLimit()){
		ui_.ipmTemperatureOrMotorTemperatureLabel().setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 rgb(40, 176, 13), stop: 1 red);");
		ui_.historyTextEdit().append("ipmOrMotorTelemetryLimit - " + QDateTime::currentDateTime().toString());
	}
	else{
		 ui_.ipmTemperatureOrMotorTemperatureLabel().setStyleSheet("");
	}
}

void FaultsView::batteryFaultsReceived(BatteryFaults batteryFaults)
{

}

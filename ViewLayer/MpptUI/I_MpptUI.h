#pragma once

#include <QLabel>
#include "qwt_plot.h"
#include <QComboBox>
#include <QGraphicsView>
#include <QPushButton>
#include <QCheckBox>

class I_MpptUI
{
public:
	virtual ~I_MpptUI() {}

	virtual QLabel& setMppt1PowerIn() = 0;
	virtual QLabel& setMppt1VoltageIn() = 0;
	virtual QLabel& setMppt1CurrentIn() = 0;
	virtual QLabel& setMppt1PowerOut() = 0;
	virtual QLabel& setMppt1VoltageOut() = 0;
	virtual QLabel& setMppt1CurrentOut() = 0;
	virtual QLabel& setMppt1Efficiency() = 0;

	virtual QLabel& setMppt2PowerIn() = 0;
	virtual QLabel& setMppt2VoltageIn() = 0;
	virtual QLabel& setMppt2CurrentIn() = 0;
	virtual QLabel& setMppt2PowerOut() = 0;
	virtual QLabel& setMppt2VoltageOut() = 0;
	virtual QLabel& setMppt2CurrentOut() = 0;
	virtual QLabel& setMppt2Efficiency() = 0;

	virtual QLabel& setMppt3PowerIn() = 0;
	virtual QLabel& setMppt3VoltageIn() = 0;
	virtual QLabel& setMppt3CurrentIn() = 0;
	virtual QLabel& setMppt3PowerOut() = 0;
	virtual QLabel& setMppt3VoltageOut() = 0;
	virtual QLabel& setMppt3CurrentOut() = 0;
	virtual QLabel& setMppt3Efficiency() = 0;

	virtual QLabel& setMppt4PowerIn() = 0;
	virtual QLabel& setMppt4VoltageIn() = 0;
	virtual QLabel& setMppt4CurrentIn() = 0;
	virtual QLabel& setMppt4PowerOut() = 0;
	virtual QLabel& setMppt4VoltageOut() = 0;
	virtual QLabel& setMppt4CurrentOut() = 0;
	virtual QLabel& setMppt4Efficiency() = 0;

	virtual QLabel& setMppt5PowerIn() = 0;
	virtual QLabel& setMppt5VoltageIn() = 0;
	virtual QLabel& setMppt5CurrentIn() = 0;
	virtual QLabel& setMppt5PowerOut() = 0;
	virtual QLabel& setMppt5VoltageOut() = 0;
	virtual QLabel& setMppt5CurrentOut() = 0;
	virtual QLabel& setMppt5Efficiency() = 0;

	virtual QLabel& setMppt6PowerIn() = 0;
	virtual QLabel& setMppt6VoltageIn() = 0;
	virtual QLabel& setMppt6CurrentIn() = 0;
	virtual QLabel& setMppt6PowerOut() = 0;
	virtual QLabel& setMppt6VoltageOut() = 0;
	virtual QLabel& setMppt6CurrentOut() = 0;
	virtual QLabel& setMppt6Efficiency() = 0;

	virtual QLabel& setMppt7PowerIn() = 0;
	virtual QLabel& setMppt7VoltageIn() = 0;
	virtual QLabel& setMppt7CurrentIn() = 0;
	virtual QLabel& setMppt7PowerOut() = 0;
	virtual QLabel& setMppt7VoltageOut() = 0;
	virtual QLabel& setMppt7CurrentOut() = 0;
	virtual QLabel& setMppt7Efficiency() = 0;

	virtual QLabel& setPower1PowerValue() = 0;
	virtual QLabel& setPower1VoltageValue() = 0;
	virtual QLabel& setPower1CurrentValue() = 0;

	virtual QLabel& setPower2PowerValue() = 0;
	virtual QLabel& setPower2VoltageValue() = 0;
	virtual QLabel& setPower2CurrentValue() = 0;

	virtual QLabel& setPower3PowerValue() = 0;
	virtual QLabel& setPower3VoltageValue() = 0;
	virtual QLabel& setPower3CurrentValue() = 0;

	virtual QLabel& setPower4PowerValue() = 0;
	virtual QLabel& setPower4VoltageValue() = 0;
	virtual QLabel& setPower4CurrentValue() = 0;

	virtual QLabel& setPower5PowerValue() = 0;
	virtual QLabel& setPower5VoltageValue() = 0;
	virtual QLabel& setPower5CurrentValue() = 0;

	virtual QLabel& setPower6PowerValue() = 0;
	virtual QLabel& setPower6VoltageValue() = 0;
	virtual QLabel& setPower6CurrentValue() = 0;

	virtual QLabel& setPower7PowerValue() = 0;
	virtual QLabel& setPower7VoltageValue() = 0;
	virtual QLabel& setPower7CurrentValue() = 0;

	virtual QwtPlot& setPvGraph() = 0;
	virtual QwtPlot& setIvGraph() = 0;
	virtual QwtPlot& setPtGraph() = 0;

	virtual QCheckBox& pvGraph1MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph2MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph3MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph4MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph5MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph6MpptCheckBox() = 0;
	virtual QCheckBox& pvGraph7MpptCheckBox() = 0;

	virtual QCheckBox& ivGraph1MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph2MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph3MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph4MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph5MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph6MpptCheckBox() = 0;
	virtual QCheckBox& ivGraph7MpptCheckBox() = 0;

	virtual QCheckBox& ptGraph1MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph2MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph3MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph4MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph5MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph6MpptCheckBox() = 0;
	virtual QCheckBox& ptGraph7MpptCheckBox() = 0;

	virtual QComboBox& getAlgorithmSelector() = 0;
	virtual QPushButton& commsSendButton() = 0;
}; 
#pragma once

#include <QObject>
#include "../../DataLayer/I_MpptData.h"

class I_BatteryData;

class MpptGraphsPresenter : public I_GraphsPresenter
{
	Q_OBJECT
public:
	explicit MpptGraphsPresenter(const I_MpptData& mpptData);

	void startUpdating();
	void stopUpdating();

public slots:
	void updateGraphData();

private:
	const I_MpptData& mpptData_;

signals:
	void ivCurveUpdated();
}
#pragma once

#include <QObject>
#include "../../DataLayer/I_ArrayData.h"

class I_BatteryData;

class MpptGraphsPresenter : public I_GraphsPresenter
{
	Q_OBJECT
public:
	explicit MpptGraphsPresenter(const I_ArrayData& arrayData);

	void startUpdating();
	void stopUpdating();

public slots:
	void updateGraphData();

private:
	const I_ArrayData& arrayData_;

signals:
	void ivCurveUpdated();
}
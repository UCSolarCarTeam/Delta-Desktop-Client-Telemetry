#pragma once

#include <QObject>
#include "I_GraphsPresenter.h"
#include "PowerGraphData.h"

class I_PowerGraphsPresenter : public I_GraphsPresenter
{
    Q_OBJECT
public:
    virtual ~I_PowerGraphsPresenter() {}

    virtual void startUpdating() = 0;
    virtual void stopUpdating() = 0;

public slots:
    virtual void updateGraphData() = 0;

signals:
    virtual void busCurrentGraphDataUpdated(PowerGraphData);
    virtual void busVoltageGraphDataUpdated(PowerGraphData);
    virtual void busPowerGraphDataUpdated(PowerGraphData);

    virtual void driverCurrentGraphDataUpdated(PowerGraphData);
    virtual void driverSpeedGraphDataUpdated(PowerGraphData);

    virtual void cellVoltageGraphDataUpdated(PowerGraphData);
    virtual void cellTemperatureGraphDataUpdated(PowerGraphData);
};

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
    void busCurrentGraphDataUpdated(PowerGraphData);
    void busVoltageGraphDataUpdated(PowerGraphData);
    void busPowerGraphDataUpdated(PowerGraphData);

    void drivingCurrentGraphDataUpdated(PowerGraphData);
    void drivingSpeedGraphDataUpdated(PowerGraphData);

    void cellTemperatureGraphDataUpdated(PowerGraphData);
    void cellVoltageGraphDataUpdated(PowerGraphData);
};

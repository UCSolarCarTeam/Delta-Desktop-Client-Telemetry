#pragma once

#include <QLabel>

class I_PowerUI
{
public:
	virtual ~I_PowerUI() {}

    virtual QLabel& setBatteryCMU1Temp() = 0;
    virtual QLabel& setBatteryCMU1Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU1Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU2Temp() = 0;
    virtual QLabel& setBatteryCMU2Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU2Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU3Temp() = 0;
    virtual QLabel& setBatteryCMU3Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU3Cell8Voltage() = 0;

    virtual QLabel& setBatteryCMU4Temp() = 0;
    virtual QLabel& setBatteryCMU4Cell1Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell2Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell3Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell4Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell5Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell6Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell7Voltage() = 0;
    virtual QLabel& setBatteryCMU4Cell8Voltage() = 0;
};
#pragma once

#include "I_PowerData.h"

class PowerData : public I_PowerData
{
public:
    PowerData();
    virtual ~PowerData();

    /*PowerData "Gets"*/
    double busCurrentA() const;
    double busVoltage() const;
    double motorVoltageReal() const;
    double motorCurrentReal() const;
    double backEmfImaginary() const;
    double dcBusAmpHours() const;
    
    /*PowerData "Sets"*/
    void setBusCurrentA(double busCurrentA);
    void setBusVoltage(double busVoltage);
    void setMotorVoltageReal(double motorVoltageReal);
    void setMotorCurrentReal(double motorCurrentReal);
    void setBackEmfImaginary(double backEmfImaginary);
    void setDcBusAmpHours(double dcBusAmpHours);

private:
	double busCurrentA_;
    double busVoltage_;
    double motorVoltageReal_;
    double motorCurrentReal_;
    double backEmfImaginary_;
    double dcBusAmpHours_;
};


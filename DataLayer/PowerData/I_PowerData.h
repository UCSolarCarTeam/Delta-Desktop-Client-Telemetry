#pragma once

#include <QObject>

class I_PowerData : public QObject
{
    Q_OBJECT

public:
    virtual ~I_PowerData() {}
    
	/*PowerData "Gets"*/
    virtual double busCurrentA() const = 0; 
    virtual double busVoltage() const = 0; 
    virtual double motorVoltageReal() const = 0; 
    virtual double motorCurrentReal() const = 0; 
    virtual double backEmfImaginary() const = 0; 
    virtual double dcBusAmpHours() const = 0;  

	/*PowerData "Sets"*/
    virtual void setBusCurrentA(double busCurrentA) = 0;
    virtual void setBusVoltage(double busVoltage) = 0;
    virtual void setMotorVoltageReal(double motorVoltageReal) = 0;
    virtual void setMotorCurrentReal(double motorCurrentReal) = 0;
    virtual void setBackEmfImaginary(double backEmfImaginary) = 0;
    virtual void setDcBusAmpHours(double dcBusAmpHours) = 0;

signals:
	void busCurrentAReceived(double busCurrentA);
    void busVoltageReceived(double busVoltage);
    void motorVoltageRealReceived(double motorVoltageReal);
    void motorCurrentRealReceived(double motorCurrepowerntReal);
    void backEmfImaginaryReceived(double backEmfImaginary);
	void dcBusAmpHoursReceived(double dcBusAmpHours);
};


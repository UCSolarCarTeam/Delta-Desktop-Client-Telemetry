#pragma once

#include <QObject>
class I_PowerData;

class PowerPresenter : public QObject
{
    Q_OBJECT
public:
    explicit PowerPresenter(const I_PowerData& powerData);

private:
    void relayPowerData();

    const I_PowerData& powerData_;

signals:
    void busCurrentAReceived(double busCurrent);
    void busVoltageReceived(double busVoltage);
};

#pragma once

#include <QObject>
class I_PowerData;
class I_ConnectionService;

class DisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit DisplayPresenter(const I_PowerData& powerData,
                             I_ConnectionService& connectionService);
   void connectDataSource(QString portName, int baudRate);
   void disconnectDataSource();

private:
    void relayPowerData();
    void relayConnectionStatus();

private:
   const I_PowerData& powerData_;
   I_ConnectionService& connectionService_;

signals:
   void busCurrentAReceived(double busCurrentA);
   void busVoltageReceived(double busVoltage);
   void motorVoltageRealReceived(double motorVoltageReal);
   void motorCurrentRealReceived(double motorCurrentReal);
   void backEmfImaginaryReceived(double backEmfImaginary);
   void dcBusAmpHoursReceived(double dcBusAmpHours);

   void connectionFailed(QString failureMessage);
   void connectionSucceeded(QString successMessage);
};

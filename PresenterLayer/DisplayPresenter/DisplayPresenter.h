#pragma once

#include <QObject>
class I_PowerData;
class I_ConnectionService;
class LoggerService;

class DisplayPresenter : public QObject
{
   Q_OBJECT
public:
   explicit DisplayPresenter(const I_PowerData& powerData,
                             I_ConnectionService& connectionService,
                             LoggerService& loggerService);
   void connectDataSource(QString portName, int baudRate);
   void disconnectDataSource();

private:
    void relayPowerData();
    void relayConnectionStatus();
    void relayDebugMessage();

private:
   const I_PowerData& powerData_;
   I_ConnectionService& connectionService_;
   LoggerService& loggerService_;

signals:
   void busCurrentAReceived(double busCurrentA);
   void busVoltageReceived(double busVoltage);
   void motorVoltageRealReceived(double motorVoltageReal);
   void motorCurrentRealReceived(double motorCurrentReal);
   void backEmfImaginaryReceived(double backEmfImaginary);
   void dcBusAmpHoursReceived(double dcBusAmpHours);

   void connectionFailed(QString failureMessage);
   void connectionSucceeded(QString successMessage);
   void sendDebugMessage(QString message);
};


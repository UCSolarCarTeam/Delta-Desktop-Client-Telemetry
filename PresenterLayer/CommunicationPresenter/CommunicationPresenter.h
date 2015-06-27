#pragma once

#include <QObject>

class I_ConnectionService;

class CommunicationPresenter : public QObject
{
	Q_OBJECT
public:
   explicit CommunicationPresenter(I_ConnectionService& connectionService);
   void connectDataSource(QString portName, int baudRate);
   void disconnectDataSource();

private:
    void relayConnectionStatus();

private:
   I_ConnectionService& connectionService_;

signals:
   void connectionFailed(QString failureMessage);
   void connectionSucceeded(QString successMessage);
};
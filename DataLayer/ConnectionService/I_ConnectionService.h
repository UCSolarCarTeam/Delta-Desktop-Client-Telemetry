#pragma once

#include <QIODevice>
#include <QObject>
#include <QString>

class I_ConnectionService : public QObject
{
    Q_OBJECT

signals:
   void connectionFailed(QString failureMessage);
   void connectionSucceeded(QString successMessage2);
   void sendDebugMessage(QString debugMessage);

public slots:
   virtual void connectDataSource(QString portName, int baudRate) = 0;
   virtual void disconnectDataSource() = 0;
};

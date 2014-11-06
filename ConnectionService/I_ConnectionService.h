#ifndef I_CONNECTIONSERVICE_H
#define I_CONNECTIONSERVICE_H

#include <QObject>
#include <QIODevice>
#include <QString>

class I_ConnectionService : public QObject
{
    Q_OBJECT

public:
   bool isConnected();

signals:
   void connectionFailed(QString);
   void connectionSucceeded();

public slots:
   virtual void connectDataSource(QString, int) = 0;
   virtual void disconnectDataSource() = 0;


};

#endif // I_CONNECTIONSERVICE_H

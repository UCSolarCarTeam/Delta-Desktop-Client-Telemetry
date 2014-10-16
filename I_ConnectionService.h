#ifndef I_CONNECTIONSERVICE_H
#define I_CONNECTIONSERVICE_H

#include <QObject>

class I_ConnectionService : public QObject
{
    Q_OBJECT

signals:
   void failed(QString failureReason);
   void succeeded();

public slots:
   virtual void connectDataSource() = 0;

};

#endif // I_CONNECTIONSERVICE_H

#ifndef I_CONNECTIONSERVICE_H
#define I_CONNECTIONSERVICE_H

#include <QObject>
#include <QIODevice>
#include <QString>

class I_ConnectionService : public QObject
{
    Q_OBJECT

public:
   bool connected();

signals:
   void connectionFailed(QString);
   void connectionSucceeded();

public slots:
   virtual void connectDataSource() = 0;
   virtual QString checkStatus() = 0;


};

#endif // I_CONNECTIONSERVICE_H

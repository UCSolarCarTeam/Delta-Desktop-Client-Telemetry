#ifndef I_CONNECTIONSERVICE_H
#define I_CONNECTIONSERVICE_H

#include <QObject>
#include <QIODevice>
#include <QString>

class I_ConnectionService : public QObject
{
    Q_OBJECT
public slots:
   virtual bool connectDataSource() = 0;
   virtual QString checkStatus() = 0;

};

#endif // I_CONNECTIONSERVICE_H

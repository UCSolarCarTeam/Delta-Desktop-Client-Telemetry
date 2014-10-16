#ifndef I_SERIALPORTCONNECTIONSERVICE_H
#define I_SERIALPORTCONNECTIONSERVICE_H

#include "I_ConnectionService.h"
#include <QObject>

class I_SerialPortConnectionService : public I_ConnectionService
{
   Q_OBJECT
public:
   explicit I_SerialPortConnectionService();

signals:

public slots:
   void connectDataSource();

};

#endif // I_SERIALPORTCONNECTIONSERVICE_H

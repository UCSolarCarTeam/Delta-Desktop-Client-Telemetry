#include <QObject>
#include "i_connectionservice.h"

class I_ConnectionService : public QObject
{
    Q_OBJECT

signals:
   void failed(QString failureReason);
   void succeeded();

public slots:
   virtual void connect() = 0;

};

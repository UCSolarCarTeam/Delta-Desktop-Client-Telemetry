#pragma once

#include <QObject>
class QByteArray;

class I_CommDevice : public QObject
{
   Q_OBJECT
public:
   virtual ~I_CommDevice() {}

signals:
   void dataReceived(QByteArray data);
};

#pragma once

#include <QObject>

class I_DataParser : public QObject
{
  Q_OBJECT
public:
   virtual ~I_DataParser() {}

signals:
   void dataReceived(int id, double value);
   void sendDebugMessage(QString);
};

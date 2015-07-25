#include <QDebug>
#include "FakeConnectionService.h"

FakeConnectionService::FakeConnectionService()
{
}

bool FakeConnectionService::isConnected()
{
   qDebug() << "isConnected was Called";
   return true;
}

void FakeConnectionService::connectDataSource(QString portName, int baudRate)
{
   qDebug() << "connectDataSource with portname: " << portName
            << " and baud rate of " << baudRate;
}

void FakeConnectionService::disconnectDataSource()
{
   qDebug() << "disconnectDataSource";
}

void FakeConnectionService::emitSignalConnectionSucceeded()
{
   emit connectionSucceeded("Connected");
}


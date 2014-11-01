#include "FakeConnectionService.h"

FakeConnectionService::FakeConnectionService()
{
}

bool FakeConnectionService::isConnected()
{
   qDebug() << "isConnected was Called";
   return true;
}

void FakeConnectionService::connectDataSource()
{
   qDebug() << "connectDataSource";
}

void FakeConnectionService::emitSignalConnectionSucceeded()
{
   emit connectionSucceeded();
}


#pragma once

class QByteArray;

class I_DataInjectionService
{
public:
   virtual ~I_DataInjectionService() {}

   virtual void injectFramedData(const QByteArray& data) = 0;
};

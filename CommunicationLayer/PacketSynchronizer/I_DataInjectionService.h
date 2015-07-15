#pragma once

class QByteArray;

class I_DataInjectionService
{
public:
   virtual ~I_DataInjectionService() {}

   virtual void injectData(const QByteArray& data) = 0;
};

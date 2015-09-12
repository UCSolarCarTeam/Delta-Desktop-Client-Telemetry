#include "FakeSerialPort.h"

FakeSerialPort::FakeSerialPort()
{
}

FakeSerialPort::~FakeSerialPort()
{
}

qint64 FakeSerialPort::readData(char *data, qint64 maxlen)
{
   if (maxlen == 0)
   {
      // Called for post reading operation. Do nothing
      return 0;
   }

   QByteArray dataToReturn = data_.left(maxlen);
   if (dataToReturn.size() > 0)
   {
      memcpy(data, dataToReturn, dataToReturn.size());
   }
   data_.remove(0, maxlen);

   return dataToReturn.size();
}

qint64 FakeSerialPort::writeData(const char *data, qint64 len)
{
   Q_UNUSED(data);
   Q_UNUSED(len);
   return -1;
}

void FakeSerialPort::emitReadyRead()
{
   emit readyRead();
}

void FakeSerialPort::setData(QByteArray data)
{
   data_ = data;
}

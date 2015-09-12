#include <QByteArray>
#include <QIODevice>

class FakeSerialPort : public QIODevice
{
   Q_OBJECT
public:
   FakeSerialPort();
   virtual ~FakeSerialPort();

   qint64 readData(char *data, qint64 maxlen);
   qint64 writeData(const char *data, qint64 len);

   void emitReadyRead();
   void setData(QByteArray data);

private:
   QByteArray data_;
};

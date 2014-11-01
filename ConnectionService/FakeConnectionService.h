#ifndef FAKECONNECTIONSERVICE_H
#define FAKECONNECTIONSERVICE_H

class FakeConnectionService : public I_ConnectionService
{
   Q_OBJECT

public:
   FakeConnectionService();
public:
      bool isConnected();
      void emitSignalConnectionSucceeded();

public slots:
      void connectDataSource();


};

#endif // FAKECONNECTIONSERVICE_H

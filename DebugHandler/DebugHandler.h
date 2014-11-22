#pragma once

#include <QObject>
#include <QString>

class I_ConnectionService;
class I_DataParser;

class DebugHandler : public QObject
{
   Q_OBJECT

public:
   explicit DebugHandler(I_ConnectionService& connectionService, I_DataParser& dataParser);
   virtual ~DebugHandler();

signals:
   void sendDebugMessageToPresenter(QString);

private slots:
   void receivedConnectionService(QString);
   void receivedDebugDataParser(QString);
   void receivedParsedDataParser(int, int);

private:
   void printlnToDebugLogFile(QString);
   QString convertIDtoString(int);

   I_ConnectionService& connectionService_;
   I_DataParser& dataParser_;

};

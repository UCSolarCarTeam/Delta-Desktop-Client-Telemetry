#pragma once

#include <QObject>
#include <QString>
#include <Qfile>
#include <qdebug.h>
#include <QTextStream>
#include <QDateTime>
#include <QDir>

class I_ConnectionService;
class I_DataParser;

class DebugHandler : public QObject
{
   Q_OBJECT

public:
   explicit DebugHandler(I_ConnectionService& connectionService,
                         I_DataParser& dataParser,
                         QString filename);
   virtual ~DebugHandler();

signals:
   void sendDebugMessageToPresenter(QString);

private slots:
   void receivedConnectionService(QString);
   void receivedDebugDataParser(QString);
   void receivedParsedDataParser(int, double);

private:
   void printlnToDebuglogTxtFile(QString);
   void printlnToDebuglogCsvFile(QString);
   QString convertIDtoString(int);

   QFile logTxtFile_;
   QFile logCsvFile_;

   I_ConnectionService& connectionService_;
   I_DataParser& dataParser_;

};

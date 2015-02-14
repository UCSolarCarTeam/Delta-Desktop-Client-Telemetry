#pragma once

#include <QObject>
#include <QString>
#include <QFile>
#include <qdebug.h>
#include <QTextStream>
#include <QDateTime>
#include <QDir>
#include <QVector>

class I_ConnectionService;
class I_DataParser;

class LoggerService : public QObject
{
   Q_OBJECT

public:
   LoggerService(I_ConnectionService& connectionService,
                I_DataParser& dataParser,
                QString filename);
   virtual ~LoggerService();

signals:
   void sendDebugMessageToPresenter(QString);

private slots:
   void receivedConnectionService(QString);
   void receivedDebugDataParser(QString);
   void receivedParsedDataParser(int, double);

private:
   void storeCsv2DArray(int id, int value);
   void printlnToDebuglogTxtFile(QString);
   void printToDebuglogCsvFile(void);

   QString convertIDtoString(int);
   QFile logTxtFile_;
   QFile logCsvFile_;
   QVector< QVector<int> > csv2DArray_;

   I_ConnectionService& connectionService_;
   I_DataParser& dataParser_;
};
